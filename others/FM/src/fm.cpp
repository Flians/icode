#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>
#include <sstream>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define TIME_LIMIT 200 * CLOCKS_PER_SEC

void read_cells_nets(const std::string &cells_path, const std::string &nets_path, std::unordered_map<std::string, uint32_t> &cell_name_id, std::vector<uint32_t> &cell_size, std::unordered_map<std::string, uint32_t> &net_name_id, std::vector<std::vector<uint32_t>> &cell_array, std::vector<std::vector<uint32_t>> &net_array) {
  cell_name_id.clear();
  net_name_id.clear();
  // read cells
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
  // read nets
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

void init_partition(const std::vector<std::vector<uint32_t>> &cell_array, const std::vector<uint32_t> &cell_size, std::vector<bool> &partition, std::pair<uint32_t, uint32_t> &area) {
  std::size_t cn = cell_size.size();
  partition.resize(cn, false);
  area = {0, 0};
  uint32_t index[cn];
  std::iota(index, index + cn, 0);
  std::random_shuffle(index, index + cn);
  for (std::size_t i = 0; i < cn; ++i) {
    uint32_t cid = index[i];
    if (area.first < area.second) {
      area.first += cell_size[cid];
      partition[cid] = true;
    } else {
      area.second += cell_size[cid];
      partition[cid] = false;
    }
  }
}

uint32_t cutsize(const std::vector<std::vector<uint32_t>> &net_array, const std::vector<bool> &partition) {
  std::size_t nid = 0, nn = net_array.size(), cut_size = 0;
  for (; nid < nn; ++nid) {
    std::size_t an = 0, bn = 0;
    for (uint32_t cid : net_array[nid]) {
      if (partition[cid]) {
        an++;
      } else {
        bn++;
      }
    }
    if (an > 0 && bn > 0) {
      cut_size++;
    }
  }
  return cut_size;
}

uint32_t all_gain(const std::vector<std::vector<uint32_t>> &net_array, const std::vector<bool> &partition, std::vector<int> &gain) {
  std::size_t nid = 0, cn = partition.size(), nn = net_array.size(), cut_size = 0;
  gain.resize(cn, 0);
  std::fill(gain.begin(), gain.end(), 0);
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
      cut_size++;
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
  return cut_size;
}

void update_gain(const uint32_t cid_mv, const std::size_t maxDeg, const std::vector<std::vector<uint32_t>> &cell_array, const std::vector<std::vector<uint32_t>> &net_array, const std::vector<bool> &partition, std::vector<std::pair<std::unordered_set<uint32_t>, std::unordered_set<uint32_t>>> &unlockn_ab, std::vector<std::pair<uint32_t, uint32_t>> &net_abl, std::vector<int> &gain, std::vector<std::unordered_set<uint32_t>> &unfixed) {
  bool moveto = partition[cid_mv];
  for (auto nid : cell_array[cid_mv]) {
    auto &unlockc_ab = unlockn_ab[nid];
    if (moveto) {
      unlockc_ab.second.erase(cid_mv);
    } else {
      unlockc_ab.first.erase(cid_mv);
    }
    std::size_t an = unlockc_ab.first.size(), bn = unlockc_ab.second.size();
    auto &abn = net_abl[nid];
    if (!(an == 0 && bn == 0) && !(an >= 2 && bn >= 2)) {
      if (abn.first == 0 || abn.second == 0) {
        for (auto cid : moveto ? unlockc_ab.second : unlockc_ab.first) {
          unfixed[gain[cid] + maxDeg].erase(cid);
          gain[cid] += 1 + (abn.first == 2 || abn.second == 2);
          unfixed[gain[cid] + maxDeg].insert(cid);
        }
      } else if ((moveto && abn.second == 1) || (!moveto && abn.first == 1)) {
        for (auto cid : moveto ? unlockc_ab.first : unlockc_ab.second) {
          unfixed[gain[cid] + maxDeg].erase(cid);
          gain[cid] -= 1 + ((moveto && abn.first == 1) || (!moveto && abn.second == 1));
          unfixed[gain[cid] + maxDeg].insert(cid);
        }
      } else if ((moveto && abn.first == 1) || (!moveto && abn.second == 1)) {
        for (auto cid : moveto ? unlockc_ab.first : unlockc_ab.second) {
          unfixed[gain[cid] + maxDeg].erase(cid);
          gain[cid]--;
          unfixed[gain[cid] + maxDeg].insert(cid);
        }
        if ((moveto && abn.second == 2) || (!moveto && abn.first == 2)) {
          for (auto cid : moveto ? unlockc_ab.second : unlockc_ab.first) {
            unfixed[gain[cid] + maxDeg].erase(cid);
            gain[cid]++;
            unfixed[gain[cid] + maxDeg].insert(cid);
          }
        }
      } else if ((moveto && abn.second == 2) || (!moveto && abn.first == 2)) {
        for (auto cid : moveto ? unlockc_ab.second : unlockc_ab.first) {
          unfixed[gain[cid] + maxDeg].erase(cid);
          gain[cid]++;
          unfixed[gain[cid] + maxDeg].insert(cid);
        }
      }
    }
    if (moveto) {
      abn.first++;
      abn.second--;
    } else {
      abn.first--;
      abn.second++;
    }
  }
}

uint32_t FMAlgorithm(const std::vector<uint32_t> &cell_size, const std::vector<std::vector<uint32_t>> &cell_array, const std::vector<std::vector<uint32_t>> &net_array, std::vector<bool> &best_partition) {
  std::size_t cn = cell_array.size(), nn = net_array.size(), maxDeg = 0;
  for (const auto &item : cell_array) {
    maxDeg = std::max(maxDeg, item.size());
  }
  // Find initial cut
  std::vector<bool> partition;
  std::pair<uint32_t, uint32_t> area;
  init_partition(cell_array, cell_size, partition, area);
  const uint32_t tarea = area.first + area.second;
  // Compute the cell gain of each cell
  std::vector<int> gain;
  uint32_t cut_size = all_gain(net_array, partition, gain);
  // Best result
  uint32_t best_cut_size = 0xffffffff;
  best_partition.resize(cn);
  // timer
  clock_t timer = clock();
  int T = 200;
  while (T-- > 0) {
    // record
    std::vector<std::pair<std::unordered_set<uint32_t>, std::unordered_set<uint32_t>>> unlockn_ab(nn);
    std::vector<std::unordered_set<uint32_t>> unfixed((maxDeg << 1) + 1);
    std::vector<std::pair<uint32_t, uint32_t>> net_abl(nn, {0, 0});
    for (std::size_t cid = 0; cid < cn; ++cid) {
      unfixed[gain[cid] + maxDeg].insert(cid);
      for (uint32_t nid : cell_array[cid]) {
        if (partition[cid]) {
          unlockn_ab[nid].first.insert(cid);
          net_abl[nid].first++;
        } else {
          unlockn_ab[nid].second.insert(cid);
          net_abl[nid].second++;
        }
      }
    }
    // Best result of the current iteration
    uint32_t cur_best_cut_size = 0xffffffff;
    std::vector<bool> cur_best_partition(cn);
    std::pair<uint32_t, uint32_t> cur_best_area{0, 0};
    // Repeat until all cells are fixed
    std::size_t fn = 0;
    while (fn++ < cn) {
      // Find the cell with max gain
      uint32_t cid_maxg = cn, cid_maxg_il = cn;
      for (int i = maxDeg << 1; i >= 0 && cid_maxg == cn; --i) {
        for (uint32_t cid : unfixed[i]) {
          if (std::abs(2.0 * cell_size[cid] * (partition[cid] ? -1 : 1) + area.first - area.second) < tarea / 10.0) {
            cid_maxg = cid;
            break;
          } else if (cid_maxg_il == cn) {
            cid_maxg_il = cid;
          }
        }
      }
      if (cid_maxg == cn) {
        // std::cout << "There is no movement satisfying the constraint\n";
        cid_maxg = cid_maxg_il;
        // break;
      }
      // Move the cell with max gain to the other set
      uint32_t ca = cell_size[cid_maxg];
      if (partition[cid_maxg]) {
        area.first -= ca;
        area.second += ca;
        partition[cid_maxg] = false;
      } else {
        area.first += ca;
        area.second -= ca;
        partition[cid_maxg] = true;
      }
      // Fix the cell with max gain
      int maxg = gain[cid_maxg];
      unfixed[maxg + maxDeg].erase(cid_maxg);
      cut_size -= maxg;
      // Update gain
      update_gain(cid_maxg, maxDeg, cell_array, net_array, partition, unlockn_ab, net_abl, gain, unfixed);
      // save best
      if (cut_size < cur_best_cut_size && std::abs(0.0 + area.first - area.second) < tarea / 10.0) {
        cur_best_area = area;
        cur_best_cut_size = cut_size;
        cur_best_partition.assign(partition.begin(), partition.end());
      }
      if (clock() - timer > TIME_LIMIT) {
        T = 0;
        break;
      }
    }
    // reset gain
    partition.assign(cur_best_partition.begin(), cur_best_partition.end());
    cut_size = all_gain(net_array, partition, gain);
    area = cur_best_area;
    // Record best partition
    if (cur_best_cut_size < best_cut_size) {
      best_cut_size = cur_best_cut_size;
      best_partition.assign(cur_best_partition.begin(), cur_best_partition.end());
    }
  }
  return best_cut_size;
}

int main(int argc, char const *argv[]) {
  if (argc < 4) {
    std::cout << "please input the command: ./fm <.cell path> <.net path> <.out path>\n";
    exit(-1);
  }
  std::unordered_map<std::string, uint32_t> cell_name_id, net_name_id;
  std::vector<std::vector<uint32_t>> cell_array, net_array;
  std::vector<uint32_t> cell_size;
  read_cells_nets(argv[2], argv[1], cell_name_id, cell_size, net_name_id, cell_array, net_array);
  std::vector<bool> partition;
  uint32_t cut_size = FMAlgorithm(cell_size, cell_array, net_array, partition);
  std::string pA, pB;
  std::size_t cn = cell_array.size(), An = 0;
  pA.reserve(cn);
  pB.reserve(cn);
  for (const auto &item : cell_name_id) {
    if (partition[item.second]) {
      pA.append(item.first);
      pA.append("\n");
      An++;
    } else {
      pB.append(item.first);
      pB.append("\n");
    }
  }
  std::ofstream fout(argv[3]);
  if (fout.is_open()) {
    fout << "cut_size " << cut_size << "\nA " << An << "\n"
         << pA << "B " << cn - An << "\n"
         << pB;
    fout.flush();
    fout.close();
  } else {
    std::cout << "Unable to open the output file: " << argv[3] << std::endl;
    exit(-1);
  }
  return 0;
}
