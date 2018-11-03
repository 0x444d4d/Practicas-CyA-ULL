#pragma once


#include <cstdlib>
#include <iostream>
#include <vector>


namespace CyA
{

class wall_t {
  private:

    unsigned height, length;
    std::vector<std::vector<int> > strings;
    std::vector<std::vector<int> > compatibles;

  public:

    wall_t(void) {height = 0; length = 0;};
    wall_t(int x, int y);
    ~wall_t(void) {};

    unsigned get_x(void) {return length;}
    unsigned get_y(void) {return height;}


  private:

    std::ostream& write(std::ostream& os, std::vector<int>& v);
    void generate_rows(std::vector<int> &aux, int len = 0);
    void compute_compatibles(void);
    int min( std::vector<int> x, std::vector<int> y );
    int max( std::vector<int> x, std::vector<int> y );


};

}

