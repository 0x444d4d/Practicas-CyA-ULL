#include <iostream>

namespace CyA {

class ladrillo {

  private:
    unsigned size;
    std::vector<bool> brick;

  public:
    ladrillo();
    ladrillo(int x): size(x) {
      brick.resize(x);
      brick[x-1].set();
    }

    ~ladrillo();

    std::vector<bool> get_brick() { return brick; }
    int get_brick() { return size; }

};

}
