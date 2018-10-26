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


  std::ostream& wall_t::write(std::ostream& os, std::vector<int> v) {
    for (int inx = 0; inx < v.size(); ++inx)   
      os << v[inx] << " ";
  }

}



