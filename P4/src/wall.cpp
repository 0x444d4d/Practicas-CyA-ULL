#include "wall.hpp"


namespace CyA
{

  wall_t::wall_t(int x, int y) {
    height = y; length = x;

    std::cout << strings.size() << std::endl;
    std::cin.get();
    
    //calculamos el numero de soluciones posibles 
    //y redimensionamos el vector de soluciones para
    //acomodarlas.
    

    //Tambien hay que cacular mediante el metodo 
    //generate_rows las cadenas de tamaño
    //x = length posibles y guardarlas en strings.
  }


  void wall_t::generate_rows(void) {
    std::vector<int> aux;
    generate_rows(aux);
  }


  void wall_t::generate_rows(std::vector<int> &aux, unsigned len) {

    if (len >= get_x()) {
      if (len == get_x()){
        push_string(aux);
        write(std::cout, aux);
        std::cin.get();
      }
      return;
    } 

    aux.push_back(2);
    generate_rows(aux, len+=2);
    aux.pop_back();
    len -=2;

    aux.push_back(3);
    generate_rows(aux, len+=3);
    aux.pop_back();
    len -=3;
    
  }


  //PENDIENTE!!!
  //
  //Pasar a hpp.
  void wall_t::push_string( std::vector<int> aux) {
    strings.push_back(aux);
  }

  int wall_t::min( std::vector<int> x, std::vector<int> y ) {
    return (x.size() < y.size()) ? x.size() : y.size();
  }


  void wall_t::compute_compatibles(void) {
    int sum0 = 0; 
    int sum1 = 0;

    for (int sel = 0; sel < strings.size(); ++sel)
      for (int row = 0; row < strings.size(); ++row)
        for (int col = 0; ; ++col) {
          if (sel != row) {
            sum0 += strings[sel][col];
            sum1 += strings[row][col];

            if (sum0 != sum1 && col == min(strings[row], strings[sel])) {
              compatibles[sel].push_back(row);
            }

          }
        }  
  }


  std::ostream& wall_t::write(std::ostream& os, std::vector<int> v) {
    for (int inx = 0; inx < v.size(); ++inx)   
      os << v[inx] << " ";
  }

}



