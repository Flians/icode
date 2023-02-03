#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <sstream>
#include <vector>

void read_cells_nets(const std::string &cells_path, const std::string &nets_path, std::map<std::string, uint32_t> &cell_name_id, std::vector<uint32_t> &cell_size, std::map<std::string, uint32_t> &net_name_id, std::vector<std::vector<uint32_t>> &cell_array, std::vector<std::vector<uint32_t>> &net_array) {
  cell_name_id.clear();
  net_name_id.clear();

  std::string line;
  std::ifstream cells_file;
  cells_file.open(cells_path);
  uint32_t id = 0;
  if (cells_file.is_open()) {
    std::regex pattern("(\\w+) (\\d+)");
    while (std::getline(cells_file, line)) {
      std::smatch items;
      bool ismatch = regex_match(line, items, pattern);
      if (!ismatch) {
        std::cout << "Match failed: " << line << std::endl;
        continue;
      }
      cell_size.push_back(static_cast<uint32_t>(std::stoul(items[2])));
      cell_name_id[items[1]] = id++;
    }
    cells_file.close();
  } else {
    std::cout << "Unable to open cell file: " << cells_path << std::endl;
    exit(-1);
  }

  cell_array.resize(id);
  std::vector<std::vector<uint32_t>>().swap(net_array);
  std::ifstream nets_file;
  nets_file.open(nets_path);
  if (nets_file.is_open()) {
    id = 0;
    std::regex pattern(" (\\w+)");
    while (std::getline(nets_file, line)) {
      while (line.find('}') == std::string::npos) {
        std::string tmp;
        std::getline(nets_file, tmp);
        line.append(tmp);
      }
      auto ite_begin = std::sregex_iterator(line.begin(), line.end(), pattern);
      auto ite_end = std::sregex_iterator();
      bool flag = true;
      uint32_t pn = 0;
      for (std::sregex_iterator it = ite_begin; it != ite_end; ++it) {
        std::smatch item = *it;
        if (flag) {
          net_name_id[item[1].str()] = id;
          net_array.push_back({});
          flag = false;
        } else {
          uint32_t cell_id = cell_name_id[item[1].str()];
          cell_array[cell_id].push_back(id);
          net_array[id].push_back(cell_id);
          pn++;
        }
      }
      id++;
      if (pn < 2) {
        std::cout << "The pin number of the net '" << line << "' is less than 2\n";
      }
    }
    nets_file.close();
  } else {
    std::cout << "Unable to open net file: " << nets_path << std::endl;
    exit(-1);
  }
}

void init_partition(const std::vector<uint32_t> &cell_size, std::vector<bool> &partition, std::pair<uint32_t, uint32_t> &area, uint32_t &maxCS) {
  std::size_t n = cell_size.size();
  partition.resize(n, false);
  area = {0, 0};
  maxCS = 0;
  for (std::size_t i = 0; i < n; ++i) {
    if (maxCS < cell_size[i])
      maxCS = cell_size[i];
    if (area.first < area.second) {
      area.first += cell_size[i];
      partition[i] = 1;
    } else {
      area.second += cell_size[i];
      partition[i] = 0;
    }
  }
}

uint32_t all_gain(const std::vector<std::vector<uint32_t>> &net_array, const std::vector<bool> &partition, std::vector<int> &gain) {
  std::size_t nid = 0, cn = partition.size(), nn = net_array.size(), cutsize = 0;
  gain.resize(cn, 0);
  for (; nid < nn; ++nid) {
    std::vector<uint32_t> ta, tb;
    for (uint32_t cid : net_array[nid]) {
      if (partition[cid]) {
        ta.push_back(cid);
      } else {
        tb.push_back(cid);
      }
    }
    std::size_t an = ta.size(), bn = tb.size();
    if (an > 0 && bn > 0) {
      cutsize++;
    }
    if (an == 1) {
      gain[ta[0]]++;
    } else if (an == 0) {
      for (uint32_t j : tb) {
        gain[j]--;
      }
    }
    if (bn == 1) {
      gain[tb[0]]++;
    } else if (bn == 0) {
      for (uint32_t j : ta) {
        gain[j]--;
      }
    }
  }
  return cutsize;
}

void update_gain(uint32_t cid, const std::vector<std::vector<uint32_t>> &cell_array, const std::vector<std::vector<uint32_t>> &net_array, const std::vector<bool> &partition, std::vector<int> &gain) {
  std::set<uint32_t> update_c;
  for (uint32_t nid : cell_array[cid]) {
    for (uint32_t cid : net_array[nid]) {
      update_c.insert(cid);
    }
  }
  update_c.insert(cid);
  for (uint32_t cid : update_c) {
    gain[cid] = 0;
    for (uint32_t nid : cell_array[cid]) {
      std::vector<uint32_t> ta, tb;
      for (uint32_t cid : net_array[nid]) {
        if (partition[cid]) {
          ta.push_back(cid);
        } else {
          tb.push_back(cid);
        }
      }
      std::size_t an = ta.size(), bn = tb.size();
      if (an == 0 || bn == 0) {
        gain[cid]--;
      } else if ((an == 1 && ta[0] == cid) || (bn == 1 && tb[0] == cid)) {
        gain[cid]++;
      }
    }
  }
}

uint32_t FMAlgorithm(const std::vector<uint32_t> &cell_size, const std::vector<std::vector<uint32_t>> &cell_array, const std::vector<std::vector<uint32_t>> &net_array, std::vector<bool> &partition) {
  std::size_t cn = cell_array.size(), nn = net_array.size();
  std::set<uint32_t> unfixed;
  // Find initial cut
  uint32_t maxCS;
  std::pair<uint32_t, uint32_t> area;
  init_partition(cell_size, partition, area, maxCS);
  uint32_t tarea = area.first + area.second;
  // Compute the cell gain of each cell
  std::vector<int> gain;
  uint32_t cut_size = all_gain(net_array, partition, gain);
  int sumg = nn;
  while (sumg > 0) {
    for (std::size_t cid = 0; cid < cn; ++cid) {
      unfixed.insert(cid);
    }
    // Repeat until no improvement can be found
    while (!unfixed.empty()) {
      // Find the cell with max gain
      int maxg = -nn;
      uint32_t cid_maxg;
      for (uint32_t cid : unfixed) {
        if (gain[cid] > maxg && std::abs(area.first - area.second + 2.0 * cell_size[cid] * (partition[cid] ? -1 : 1)) < tarea / 10.0) {
          maxg = gain[cid];
          cid_maxg = cid;
        }
      }
      // Move the cell with max gain to the other set
      if (partition[cid_maxg]) {
        area.first -= cell_size[cid_maxg];
        area.second += cell_size[cid_maxg];
        partition[cid_maxg] = false;
      } else {
        area.first += cell_size[cid_maxg];
        area.second -= cell_size[cid_maxg];
        partition[cid_maxg] = true;
      }
      // Fix the cell with max gain
      unfixed.erase(cid_maxg);
      // Update gain
      update_gain(cid_maxg, cell_array, net_array, partition, gain);
    }
    // calculate the sum of gain
    cut_size = all_gain(net_array, partition, gain);
    sumg = std::accumulate(gain.begin(), gain.end(), 0);
    std::cout << sumg << std::endl;
  }
  return cut_size;
}

int main(int argc, char const *argv[]) {
  if (argc < 4) {
    std::cout << "please input the command: ./fm <.cell path> <.net path> <.out path>\n";
    exit(-1);
  }
  std::map<std::string, uint32_t> cell_name_id, net_name_id;
  std::vector<std::vector<uint32_t>> cell_array, net_array;
  std::vector<uint32_t> cell_size;
  read_cells_nets(argv[1], argv[2], cell_name_id, cell_size, net_name_id, cell_array, net_array);
  std::vector<bool> partition;
  uint32_t cut_size = FMAlgorithm(cell_size, cell_array, net_array, partition);
  std::vector<std::string> gA, gB;
  for (const auto &item : cell_name_id) {
    if (partition[item.second]) {
      gA.push_back(item.first);
    } else {
      gB.push_back(item.first);
    }
  }
  std::ofstream fout(argv[3]);
  if (fout.is_open()) {
    fout << "cut_size " << cut_size << "\nA " << gA.size() << std::endl;
    for (std::string cell : gA) {
      fout << cell << std::endl;
    }
    fout << "B " << gB.size() << std::endl;
    for (std::string cell : gB) {
      fout << cell << std::endl;
    }
    fout.close();
  } else {
    std::cout << "Unable to open the output file: " << argv[3] << std::endl;
    exit(-1);
  }
  return 0;
}
