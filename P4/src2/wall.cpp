#include "wall.hpp"
#include "fila.hpp"


namespace CyA
{

  wall_t::wall_t(int x, int y) {
    height = y; length = x;

    fila aux(x);
    generate_rows(aux);
//    compute_compatibles();

  }


  void wall_t::generate_rows(fila &aux, int len) {

    if (len >= length) {
      if (len == length){
   //     write(std::cout, aux);
        strings.push_back(aux);
    //    std::cout << std::endl;
      }
    } else {
      aux.insert_brick(ladrillo (2));
      generate_rows(aux, len+=2);
      aux.pop_brick();
      len -=2;

      aux.insert_brick(ladrillo (3));
      generate_rows(aux, len+=3);
      aux.pop_brick();
      len -=3;
    } 
  }

  /*

  int wall_t::min( std::vector<int> x, std::vector<int> y ) {
    return (x.size() < y.size()) ? x.size() : y.size();
  }


  int wall_t::max( std::vector<int> x, std::vector<int> y ) {
    return (x.size() < y.size()) ? y.size() : x.size();
  }


  void wall_t::compute_compatibles(void) {
    int sum0 = 0; 
    int sum1 = 0;

    compatibles.resize(strings.size());

    for (int sel = 0; sel < strings.size(); ++sel) {
      for (int row = 0; row < strings.size(); ++row) {
        for (int col = 0; col < (max(strings[row], strings[sel]) - 1); ++col) {

          //CAmbiar a bitset en msol.cpp/msol.hpp
          //
            sum0 += strings[sel][col];
          if (col < strings[row].size())
            sum1 += strings[row][col];
          if (sum0 == sum1) break;

        }
        if (sum0 != sum1) compatibles[sel].push_back(row);
        sum0 = sum1 = 0;
      }
    }
  
    for (int index = 0; index < compatibles.size(); ++index ) {
      std::cout << "Fila " << index << ":  ";
      write(std::cout, compatibles[index]);
      std::cout << std::endl;
    }   
 
  }


  std::ostream& wall_t::write(std::ostream& os, std::vector<int>& v) {
    for (int inx = 0; inx < v.size(); ++inx)   
      os << v[inx] << " ";
    return os;
  }
  */

}



