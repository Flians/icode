// module.h
#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <math.h>
#include <string>
#include <vector>

class Terminal {
public:
  // constructor and destructor
  Terminal(std::string name) : name_(name) {}
  Terminal(std::string name, size_t x, size_t y) : name_(name), x_(x), y_(y) {}
  ~Terminal() {}

  // get and set
  inline const std::string GetName() const { return name_; }
  inline const size_t GetX() const { return x_; }
  inline const size_t GetY() const { return y_; }
  inline const size_t GetCenterX() const { return x_; }
  inline const size_t GetCenterY() const { return y_; }
  inline void SetX(int x) { x_ = x; }
  inline void SetY(int y) { y_ = y; }
  inline void SetXY(int x, int y) {
    x_ = x;
    y_ = y;
  }

protected:
  std::string name_;
  size_t x_;
  size_t y_;
};

class Block : public Terminal {
public:
  // constructor and destructor
  Block(std::string name, size_t w, size_t h) : Terminal(name, 0, 0), rotate_(false), width_(w), height_(h) {}
  ~Block() {}

  // get and set
  inline const size_t GetWidth() const { return rotate_ ? height_ : width_; }
  inline const size_t GetHeight() const { return rotate_ ? width_ : height_; }
  inline const size_t GetArea() const { return width_ * height_; }
  inline const double GetCenterX() const { return floor(rotate_ ? x_ + height_ / 2.0 : x_ + width_ / 2.0); }
  inline const double GetCenterY() const { return floor(rotate_ ? y_ + width_ / 2.0 : y_ + height_ / 2.0); }
  inline const bool isRotate() const { return rotate_; }
  inline void Rotate() { rotate_ = rotate_ ? false : true; }

private:
  bool rotate_;
  size_t width_;
  size_t height_;
};

class Net {
public:
  // constructor and destructor
  Net() {}
  ~Net() {}

  // get and set
  inline const int GetNetDegree() const { return terminal_list_.size() + block_list_.size(); }
  inline const int GetTerminalDegree() const { return terminal_list_.size(); }
  inline const int GetBlockDegree() const { return block_list_.size(); }
  inline Terminal *GetTerminal(int i) const { return terminal_list_[i]; }
  inline Block *GetBlock(int i) const { return block_list_[i]; }
  inline void AddTerminal(Terminal *t) { terminal_list_.push_back(t); }
  inline void AddBlock(Block *b) { block_list_.push_back(b); }

private:
  std::vector<Terminal *> terminal_list_;
  std::vector<Block *> block_list_;
};

#endif
