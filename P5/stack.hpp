#pragma once
#include <iostream>
#include <vector>

namespace CyA {

template <class T>
class stack_t {

  private:
  int top_;
  int size_;
  std::vector<T> stack_;

  public:

  stack_t(int n): top_(-1), stack_(n, 0), size_(n) {}
  ~stack_t(void) {}

  bool full(void) {return (top_ == size_);}
  bool empty(void) {return (top_ == -1);}

  char top(void) {return stack_[top_];}
  void flush(void) {top_ = -1;}

  bool push(T aux) {
    if(!full()) {
      ++top_;
      stack_[top_ ] = aux;
      return true;
    } else return false;
  }

  bool pop(void) {
    if (!empty()) {
      --top_; 
      return true;
    } else return false;
  }


};
}
