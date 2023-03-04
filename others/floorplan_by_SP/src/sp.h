// sp.h
#ifndef SP_H
#define SP_H

#define DEBUG

#ifdef DEBUG
#define DEBUG_MSG(str)             \
  do {                             \
    std::cout << str << std::endl; \
  } while (false)
#else
#define DEBUG_MSG(str) \
  do {                 \
  } while (false)
#endif

#include "module.h"
#include <fstream>
#include <iostream>
#include <map>

class SequencePair {
public:
  // constructor and destructor
  SequencePair(std::ifstream &fin_blk, std::ifstream &fin_net, std::ifstream &fin_pl, double dsr, double alpha = 0.5);
  ~SequencePair();

  // input and output
  void ParseBlk(std::ifstream &fin);
  void ParseNet(std::ifstream &fin);
  void ParsePl(std::ifstream &fin);
  void ParseError(int code);
  void WriteReport(std::ofstream &fout, std::pair<double, double> time_taken);
  void UpdateOutline();

  // solver
  void Solve();
  void Rotate90(); // 90 degree clockwise rotation
  void RandomInitialize();
  int EvaluateSequence(bool mode); // 0: compute x coordinates, 1: comput y coordinates
  double Cost(int w, int h);
  size_t Area();
  double Wirelength();
  double HPWL(Net *net);

private:
  // basic information
  double alpha_, dsr_;
  int blockArea_;
  int W_, H_; // boundary constraint
  int num_blocks_;
  int num_terminals_;
  int num_nets_;
  int num_pins_;
  std::vector<Block *> block_list_;
  std::vector<Terminal *> terminal_list_;
  std::vector<Net *> net_list_;
  std::map<std::string, Terminal *> name2terminal_;
  std::map<std::string, Block *> name2block_;

  // sequence pair
  bool has_legal_;
  std::vector<size_t> X_, Y_;
  int max_width_, max_height_;
};

#endif
