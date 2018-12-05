#pragma once


#include <cstdlib>
#include <iostream>
#include <vector>
#include "fila-old.hpp"


namespace CyA
{

class wall_t {
  private:

    unsigned height, length;
    std::vector<fila> strings;
    std::vector<std::vector<int> > compatibles;
    std::vector<std::vector<int> > muros;

  public:

    wall_t(void) {height = 0; length = 0;};
    wall_t(int x, int y);
    ~wall_t(void) {};

    unsigned get_x(void) {return length;}
    unsigned get_y(void) {return height;}


  private:

    void generate_rows(fila &aux, int len = 0);
    void compute_compatibles(void);
    void create_wall(void); 
    void create_wall(std::vector<int> aux, std::vector<bool> visited, int i, int height = 0); 
    bool match_last(std::vector<int> aux);


};

}

