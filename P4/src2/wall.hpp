#pragma once


#include <cstdlib>
#include <iostream>
#include <vector>
#include "fila.hpp"


namespace CyA
{

class wall_t {
  private:

    unsigned height, length;
    std::vector<fila> strings;
    std::vector<fila> compatibles;

  public:

    wall_t(void) {height = 0; length = 0;};
    wall_t(int x, int y);
    ~wall_t(void) {};

    unsigned get_x(void) {return length;}
    unsigned get_y(void) {return height;}


  private:

    //std::ostream& write(std::ostream& os, fila& v);
    void generate_rows(fila &aux, int len = 0);
//    void compute_compatibles(void);
//   int min( std::vector<int> x, std::vector<int> y );
//  int max( std::vector<int> x, std::vector<int> y );


};

}

