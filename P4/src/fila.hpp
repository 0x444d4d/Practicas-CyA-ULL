#include <iostream>
#include <vector>
#include "ladrillo.hpp"


namespace CyA {

class fila {

  private:
    int size_;
    int last_;
    std::vector<bool> row_;

  public:
    fila();
    fila(int x): size_(x), last_(0) {}
    ~fila();

    void insert_brick(ladrillo brick) {
      insert(std::end(row_), std::begin(brick.get_brick()), std::end(brick.get_brick()));
      last_ = brick.get_size();
    }

    void pop_brick() { for (int inx = 0; inx < last_; ++inx) { row_.pop_back() } }

};

}
