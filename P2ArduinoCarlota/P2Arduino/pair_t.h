#pragma once

class pair_t
{
private:
  int pre_;
  float freq_;
public:

  pair_t() {}
  pair_t(int pre, float freq) {
    pre_ = pre;
    freq_ = freq;
  }
  int val_1() {
    return pre_;
  }
  float val_2() {
    return freq_;
  }
  ~pair_t(){}
};
