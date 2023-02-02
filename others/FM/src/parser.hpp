#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <vector>

void read_cells_nets(const std::string &cells_path, const std::string &nets_path, std::map<std::string, uint32_t> &cell_name_id, std::map<std::string, uint32_t> &net_name_id, std::vector<std::vector<uint32_t>> &cell_array, std::vector<std::vector<uint32_t>> &net_array) {
  cell_name_id.clear();
  net_name_id.clear();

  std::string line;
  std::ifstream cells_file;
  cells_file.open(cells_path);
  std::vector<uint32_t> cell_size;
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
    std::cout << "Unable to open cell file: " << cells_path << '\n';
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
      auto ite_begin = std::sregex_iterator(line.begin(), line.end(), pattern);
      auto ite_end = std::sregex_iterator();
      bool flag = true;
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
        }
      }
      id++;
    }
    nets_file.close();
  } else {
    std::cout << "Unable to open net file: " << nets_path << '\n';
    exit(-1);
  }
}