// main.cpp
#include "sp.h"
#include "veb.h"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  std::ifstream fin_blk, fin_net, fin_pl;
  std::ofstream fout;
  double dsr = 0.1;
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
    dsr = std::stod(argv[5]);
  } else {
    std::cerr << "Usage: ./hw2 <input_hardblocks_file> <input_nets_file> <input_pinloc_file> <output_floorplan_file> <dead_space_ratio>" << std::endl;
    exit(1);
  }

  std::pair<double, double> time_taken{0, 0};

  clock_t start = clock();
  SequencePair sp(fin_blk, fin_net, fin_pl, dsr);
  time_taken.first = double(clock() - start) / double(CLOCKS_PER_SEC); // for IO

  start = clock();
  sp.Solve();
  time_taken.second = double(clock() - start) / double(CLOCKS_PER_SEC); // for alg

  sp.WriteReport(fout, time_taken);
  fin_blk.close();
  fin_net.close();
  fin_pl.close();
  fout.close();

  return 0;
}
