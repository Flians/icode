#include "parser.hpp"

int main() {
  std::map<std::string, uint32_t> cell_name_id, net_name_id;
  std::vector<std::vector<uint32_t>> cell_array, net_array;
  read_cells_nets("/home/flynn/workplace/icode/others/FM/testcases/p2-1.cells", "/home/flynn/workplace/icode/others/FM/testcases/p2-1.nets", cell_name_id, net_name_id, cell_array, net_array);
  for (auto item : cell_name_id) {
    std::cout << item.first << " " << item.second << "\n";
  }

  for (auto item : net_name_id) {
    std::cout << item.first << " ";
    for (auto pin : net_array[item.second]) {
      std::cout << pin << " ";
    }
    std::cout << "\n";
  }
  return 0;
}