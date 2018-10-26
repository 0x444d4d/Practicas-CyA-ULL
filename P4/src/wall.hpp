#pragma once


#include <cstdlib>
#include <iostream>
#include <vector>


namespace CyA
{

class wall_t {
  private:

    unsigned height, length;
    std::vector<std::vector<bool> > strings;

  public:

    wall_t(void) {height = 0; length = 0;};
    wall_t(int x, int y);
    ~wall_t(void) {};

    unsigned get_x(void) {return length;}
    unsigned get_y(void) {return height;}

    void generate_rows(void);

  private:

    void generate_rows(std::vector<bool> &aux, unsigned size);
    std::ostream& write(std::ostream& os, std::vector<bool> v);
    void push_string(std::vector<bool> aux, int pos);


};

}

