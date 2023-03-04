// main.cpp
#include "sp.h"
#include "veb.h"
#include <fstream>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[]) {
  std::ifstream fin_blk, fin_net, fin_pl;
  std::ofstream fout;
  double alpha = 0.1;
  if (argc == 6) {
    fin_blk.open(argv[1]);
    fin_net.open(argv[2]);
    fin_pl.open(argv[3]);
    fout.open(argv[4]);
    if (!fin_blk) {
      std::cerr << "Cannot open the input hardblock file \"" << argv[1] << "\"." << std::endl
                << "The program will be terminated..." << std::endl;
      exit(1);
    }
    if (!fin_net) {
      std::cerr << "Cannot open the input net file \"" << argv[2] << "\"." << std::endl
                << "The program will be terminated..." << std::endl;
      exit(1);
    }
    if (!fout) {
      std::cerr << "Cannot open the input pinloc file \"" << argv[3] << "\"." << std::endl
                << "The program will be terminated..." << std::endl;
      exit(1);
    }
    alpha = std::stod(argv[5]);
  } else {
    std::cerr << "Usage: ./hw2 <input_hardblocks_file> <input_nets_file> <input_pinloc_file> <output_floorplan_file> <dead_space_ratio>" << std::endl;
    exit(1);
  }

  SequencePair sp(fin_blk, fin_net, fin_pl, alpha);

  clock_t start, end;
  start = clock();
  sp.Solve();
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  std::cout << "Time taken by fp is : " << std::fixed << std::setprecision(5)
            << time_taken << " secends." << std::endl;

  sp.WriteReport(fout, time_taken);
  fin_blk.close();
  fin_net.close();
  fin_pl.close();
  fout.close();

  return 0;
}
