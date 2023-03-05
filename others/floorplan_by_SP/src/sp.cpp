// sp.cpp
#include "sp.h"
#include "veb.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <random>
#include <time.h>

#define TIME_LIMIT 1000 * CLOCKS_PER_SEC

SequencePair::SequencePair(std::ifstream &fin_blk, std::ifstream &fin_net, std::ifstream &fin_pl, double dsr, double alpha) {
  dsr_ = dsr;
  alpha_ = alpha;
  blockArea_ = 0;
  this->ParseBlk(fin_blk);
  this->ParseNet(fin_net);
  this->ParsePl(fin_pl);
  DEBUG_MSG("Parse finished...");
}

SequencePair::~SequencePair() {
  for (int i = 0; i < num_blocks_; ++i)
    delete block_list_[i];
  for (int i = 0; i < num_terminals_; ++i)
    delete terminal_list_[i];
  for (int i = 0; i < num_nets_; ++i)
    delete net_list_[i];
}

/* -------------------- solver -------------------- */
void SequencePair::Solve() {
  this->RandomInitialize();
  DEBUG_MSG("RandomInitialize() finished...");

  // random
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> rand_op(0, 2);
  std::uniform_int_distribution<int> rand_blk(0, num_blocks_ - 1);
  std::uniform_real_distribution<double> rand_01(0.0, 1.0);

  // best result
  double best_cost = MAXFLOAT;
  std::vector<bool> best_R(num_blocks_, false);
  std::vector<size_t> best_X(num_blocks_), best_Y(num_blocks_);

  // simulated annealing
  double temparature = 100, R = 0.9999, threshold = dsr_, loss = 0.99;
  double cur_cost;
  int cnt = 0, NUM_STEPS = 10;
  int prev_w = max_width_, prev_h = max_height_, strike_cnt = 0, lost = 0;
  // timer
  const clock_t timer = clock();
  while (1) {
    if (temparature < 0.1) {
      if (has_legal_)
        break;
      temparature = 99;
    }
    for (int i = 0; i < NUM_STEPS; ++i) {
      int op = rand_op(mt);
      int a, b;
      if (op == 0) {
        // two module names in X
        a = rand_blk(mt);
        b = rand_blk(mt);
        int temp = X_[a];
        X_[a] = X_[b];
        X_[b] = temp;
      } else if (op == 1) {
        // two module names in Y
        a = rand_blk(mt);
        b = rand_blk(mt);
        int temp = Y_[a];
        Y_[a] = Y_[b];
        Y_[b] = temp;
      } else if (op == 2) {
        // rotate
        a = rand_blk(mt);
        block_list_[a]->Rotate();
      } else {
        exit(1);
      }

      int w = this->EvaluateSequence(0);
      int h = this->EvaluateSequence(1);

      if (h <= W_ && w <= H_) {
        this->Rotate90();
        std::swap(w, h);
      }

      bool flag = false;
      cur_cost = this->Cost(w, h);
      if (cur_cost <= best_cost || (!has_legal_ && w <= W_ && h <= H_)) {
        if (w <= W_ && h <= H_) {
          if (!has_legal_) {
            has_legal_ = true;
            temparature = 99;
          }
          max_width_ = w;
          max_height_ = h;
          best_X.assign(X_.begin(), X_.end());
          best_Y.assign(Y_.begin(), Y_.end());
          best_R.assign(R_.begin(), R_.end());
        }
        best_cost = cur_cost;
        flag = true;
      } else if (rand_01(mt) < exp(-(cur_cost - best_cost) / temparature)) {
        // std::cout << pro << " " << cur_cost << " " << best_cost << " " << exp(-(cur_cost - best_cost) / temparature) << std::endl;
        flag = true;
      } else if (lost > 100 && (h - H_) / (double)H_ < threshold && (w - W_) / (double)W_ < threshold) {
        flag = true;
        threshold *= loss;
        if (!has_legal_)
          best_cost = cur_cost;
      }
      lost = flag ? 0 : lost + 1;

      // undo the move
      if (!flag) {
        if (op == 0) {
          int temp = X_[a];
          X_[a] = X_[b];
          X_[b] = temp;
        } else if (op == 1) {
          int temp = Y_[a];
          Y_[a] = Y_[b];
          Y_[b] = temp;
        } else if (op == 2) {
          block_list_[a]->Rotate();
          R_[a] = block_list_[a]->isRotate();
        }
      }
    }
    if (cnt % 1000 == 0) {
      int w = this->EvaluateSequence(0);
      int h = this->EvaluateSequence(1);
      if (prev_w == w && prev_h == h) {
        strike_cnt++;
      } else {
        prev_w = w;
        prev_h = h;
        strike_cnt = 0;
      }
      std::cout << std::fixed
                << has_legal_ << ") Temparature = " << temparature
                << "\tcost = " << cur_cost
                << "\t( " << w << " , " << h << " )"
                << "\tarea = " << w * h
                << "\twirelength = " << this->Wirelength() << std::endl;
      cnt = 0;
    }
    cnt++;
    if (strike_cnt > 5) {
      strike_cnt = 0;
      temparature = has_legal_ ? 0.1 : 99;
    }
    if (clock() - timer > TIME_LIMIT)
      break;

    temparature = R * temparature;
  }
  X_.assign(best_X.begin(), best_X.end());
  Y_.assign(best_Y.begin(), best_Y.end());
  R_.assign(best_R.begin(), best_R.end());
  for (int i = 0; i < num_blocks_; ++i) {
    if (block_list_[i]->isRotate() != R_[i]) {
      block_list_[i]->Rotate();
    }
  }
}

void SequencePair::Rotate90() {
  std::vector<int> temp;
  temp.resize(X_.size());
  temp.assign(X_.begin(), X_.end());
  X_.assign(Y_.begin(), Y_.end());
  reverse(temp.begin(), temp.end());
  Y_.assign(temp.begin(), temp.end());
  for (int i = 0; i < num_blocks_; ++i) {
    block_list_[i]->Rotate();
    R_[i] = block_list_[i]->isRotate();
  }
}

void SequencePair::RandomInitialize() {
  int w, h;
  std::vector<bool> best_R(num_blocks_, false);
  std::vector<size_t> best_X(num_blocks_), best_Y(num_blocks_);
  has_legal_ = false;
  X_.resize(num_blocks_);
  Y_.resize(num_blocks_);
  R_.resize(num_blocks_, false);
  // 1st: simply 1 to n, does not care about boundary constraint
  for (int i = 0; i < num_blocks_; ++i) {
    X_[i] = i;
    Y_[i] = i;
  }
  w = this->EvaluateSequence(0);
  h = this->EvaluateSequence(1);
  if (w <= W_ && h <= H_) {
    has_legal_ = true;
  } else if (h <= W_ && w <= H_) {
    has_legal_ = true;
    this->Rotate90();
    std::swap(w, h);
  }
  max_width_ = w;
  max_height_ = h;
  best_X.assign(X_.begin(), X_.end());
  best_Y.assign(Y_.begin(), Y_.end());
  best_R.assign(R_.begin(), R_.end());

  // random
  std::random_device rd;

  // 2nd ~ 100th: shuffle, does care about boundary constraint
  for (int i = 2; i <= 100; ++i) {
    shuffle(X_.begin(), X_.end(), std::default_random_engine(rd()));
    shuffle(Y_.begin(), Y_.end(), std::default_random_engine(rd()));
    w = this->EvaluateSequence(0);
    h = this->EvaluateSequence(1);
    bool force_flag = false;
    if (has_legal_ == false) {
      if (w <= W_ && h <= H_) {
        has_legal_ = true;
        force_flag = true;
      } else if (h <= W_ && w <= H_) {
        this->Rotate90();
        std::swap(w, h);
        has_legal_ = true;
        force_flag = true;
      }
    }
    if (w * h < max_width_ * max_height_ || force_flag) {
      if (has_legal_ && (w > W_ || h > H_))
        continue;
      max_width_ = w;
      max_height_ = h;
      best_X.assign(X_.begin(), X_.end());
      best_Y.assign(Y_.begin(), Y_.end());
      best_R.assign(R_.begin(), R_.end());
    }
  }
  X_.assign(best_X.begin(), best_X.end());
  Y_.assign(best_Y.begin(), best_Y.end());
  R_.assign(best_R.begin(), best_R.end());
  for (int i = 0; i < num_blocks_; ++i) {
    if (block_list_[i]->isRotate() != R_[i]) {
      block_list_[i]->Rotate();
    }
  }
}

int SequencePair::EvaluateSequence(bool mode) {
  if (mode == 1)
    reverse(X_.begin(), X_.end());
  // initialize match array
  std::vector<int> match_x, match_y;
  match_x.resize(num_blocks_);
  match_y.resize(num_blocks_);
  for (int i = 0; i < num_blocks_; ++i) {
    match_x[X_[i]] = i;
    match_y[Y_[i]] = i;
  }
  // initialize H with initial index 0
  VanEmdeBoas *H = new VanEmdeBoas(num_blocks_ + 1);
  H->Insert(0);
  // initialize BUCKL with BUCKL[0] = 0
  std::vector<int> BUCKL(num_blocks_ + 1, 0);
  // for loop
  for (int i = 0; i < num_blocks_; ++i) {
    int b = X_[i];
    int p = match_y[b];
    H->Insert(p);
    if (mode == 0) {
      // x coordinates
      int pos = BUCKL[H->Predecessor(p)];
      BUCKL[p] = pos + block_list_[b]->GetWidth();
      block_list_[b]->SetX(pos);
    } else {
      // y coordinates
      int pos = BUCKL[H->Predecessor(p)];
      BUCKL[p] = pos + block_list_[b]->GetHeight();
      block_list_[b]->SetY(pos);
    }
    int k = p;
    while (H->Successor(k) != -1) {
      k = H->Successor(k);
      if (BUCKL[k] <= BUCKL[p])
        H->Delete(k);
    }
  }
  if (mode == 1)
    reverse(X_.begin(), X_.end());

  return BUCKL[H->GetMax()];
}

double SequencePair::Cost(int w, int h) const {
  double wl = Wirelength(), area = w * h;
  return ((w > W_ ? w - W_ : 0) * H_ + (h > H_ ? h - H_ : 0) * W_) * 100 + alpha_ * area + (1 - alpha_) * wl;
}

double SequencePair::Wirelength() const {
  double total_wl = 0;
  for (int i = 0; i < num_nets_; ++i) {
    total_wl += this->HPWL(net_list_[i]);
  }
  return total_wl;
}

double SequencePair::HPWL(Net *net) const {
  double min_x = MAXFLOAT, min_y = MAXFLOAT, max_x = 0, max_y = 0;
  if (net->GetTerminalDegree() > 0) {
    min_x = net->GetTerminal(0)->GetCenterX();
    min_y = net->GetTerminal(0)->GetCenterY();
    max_x = min_x;
    max_y = min_y;
  } else if (net->GetBlockDegree() > 0) {
    min_x = net->GetBlock(0)->GetCenterX();
    min_y = net->GetBlock(0)->GetCenterY();
    max_x = min_x;
    max_y = min_y;
  } else {
    assert(0);
  }
  for (int i = 0; i < net->GetTerminalDegree(); ++i) {
    Terminal *t = net->GetTerminal(i);
    double x = t->GetCenterX(), y = t->GetCenterY();
    if (x < min_x)
      min_x = x;
    if (x > max_x)
      max_x = x;
    if (y < min_y)
      min_y = y;
    if (y > max_y)
      max_y = y;
  }
  for (int i = 0; i < net->GetBlockDegree(); ++i) {
    Block *t = net->GetBlock(i);
    double x = t->GetCenterX(), y = t->GetCenterY();
    if (x < min_x)
      min_x = x;
    if (x > max_x)
      max_x = x;
    if (y < min_y)
      min_y = y;
    if (y > max_y)
      max_y = y;
  }
  return (max_x - min_x) + (max_y - min_y);
}

/* -------------------- input and output -------------------- */
void SequencePair::ParseBlk(std::ifstream &fin) {
  std::string s, colon, name, sw, sh;
  int w, h;
  // fin >> W_ >> H_;
  // NumHardRectilinearBlocks : <number of blocks>
  fin >> s >> colon >> num_blocks_;
  // if (s != "NumHardRectilinearBlocks" || colon != ":") this->ParseError(1);
  // NumTerminals : <number of terminals>
  fin >> s >> colon >> num_terminals_;
  // if (s != "NumTerminals" || colon != ":") this->ParseError(2);
  // <block name> hardrectilinear vertexNumber vertex1, vertex2, ..., vertexN
  for (int i = 0; i < num_blocks_; ++i) {
    int vnum = 0;
    fin >> name >> s >> vnum;
    // if (s != "hardrectilinear") this->ParseError(3);
    int minW = INT32_MAX, maxW = INT32_MIN, minH = INT32_MAX, maxH = INT32_MIN;
    for (int j = 0; j < vnum; ++j) {
      fin >> sw >> sh;
      w = std::stoi(sw.substr(1, sw.length() - 2).c_str());
      if (w < minW)
        minW = w;
      if (w > maxW)
        maxW = w;
      h = std::stoi(sh.substr(0, sh.length() - 1).c_str());
      if (h < minH)
        minH = h;
      if (h > maxH)
        maxH = h;
    }
    Block *b = new Block(name, maxW - minW, maxH - minH);
    block_list_.push_back(b);
    name2block_.insert(std::pair<std::string, Block *>(name, b));
    blockArea_ += b->GetArea();
  }
  // calculate the width and height of the floorplan region
  UpdateOutline();
  // <terminal name> terminal <terminal x coordinate> <terminal y coordinate>
  for (int i = 0; i < num_terminals_; ++i) {
    fin >> name >> s;
    // if (s != "terminal") this->ParseError(3);
    Terminal *t = new Terminal(name);
    terminal_list_.push_back(t);
    name2terminal_.insert(std::pair<std::string, Terminal *>(name, t));
  }
}

void SequencePair::ParseNet(std::ifstream &fin) {
  std::string s, colon, name;
  int net_degree;
  // NumNets : <number of nets>
  fin >> s >> colon >> num_nets_;
  // if (s != "NumNets" || colon != ":") this->ParseError(4);
  // NumPins : <number of pins>
  fin >> s >> colon >> num_pins_;
  // if (s != "NumPins" || colon != ":") this->ParseError(5);
  for (int i = 0; i < num_nets_; ++i) {
    // NetDegree : <number of pins on the net>
    fin >> s >> colon;
    // if (s != "NetDegree" || colon != ":") this->ParseError(6);
    Net *n = new Net;
    fin >> net_degree;
    // <terminal name>
    for (int j = 0; j < net_degree; ++j) {
      fin >> name;
      if (name2terminal_.find(name) != name2terminal_.end()) {
        n->AddTerminal(name2terminal_[name]);
      } else if (name2block_.find(name) != name2block_.end()) {
        n->AddBlock(name2block_[name]);
      } else {
        assert(0);
      }
    }
    net_list_.push_back(n);
  }
}

void SequencePair::ParsePl(std::ifstream &fin) {
  std::string name;
  int x, y;
  // <terminal name> <terminal x coordinate> <terminal y coordinate>
  for (int i = 0; i < num_terminals_; ++i) {
    fin >> name >> x >> y;
    if (name2terminal_.find(name) != name2terminal_.end()) {
      name2terminal_[name]->SetXY(x, y);
    } else {
      assert(0);
    }
  }
}

void SequencePair::ParseError(int code) {
  if (code < 4)
    std::cerr << "Input.block file format error(" << code << ")." << std::endl;
  else
    std::cerr << "Input.net file format error(" << code << ")." << std::endl;
  std::cerr << "The program will be terminated..." << std::endl;
  exit(1);
}

void SequencePair::WriteReport(std::ofstream &fout, std::pair<double, double> time_taken) {
  max_width_ = this->EvaluateSequence(0);
  max_height_ = this->EvaluateSequence(1);
  double wl = this->Wirelength();
  // <total wirelength>
  fout << "Wirelength " << std::fixed << std::setprecision(0) << wl << std::endl;
  fout << "Blocks\n";
  // <macro_name> <x1> <y1> <x2> <y2>
  for (int i = 0; i < num_blocks_; ++i) {
    Block *b = block_list_[i];
    fout << b->GetName() << " "
         << b->GetX() << " " << b->GetY() << " " << b->isRotate()
         << std::endl;
  }
  std::cout << "WL: " << wl << " costing the time <IO, FP> : " << std::fixed << std::setprecision(5) << time_taken.first << " " << time_taken.second << " secends." << std::endl;
}

void SequencePair::UpdateOutline() {
  W_ = H_ = std::sqrt(blockArea_ * (1.0 + dsr_));
}
