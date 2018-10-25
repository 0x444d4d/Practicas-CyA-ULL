#include "wall.hpp"


namespace CyA
{

  wall_t::wall_t(int x, int y) {
    height = y; length = x;

    strings.resize(1 << x);

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
    std::vector<bool> aux(get_x());
    generate_rows(aux, get_x());
  }


  void wall_t::generate_rows(std::vector<bool> &aux, unsigned size) {
    static unsigned pos = 0;

    if (size <= 0) {
      strings[pos] = aux;
      ++pos;

      write(std::cout, aux);
      std::cin.get();
    }

    aux[size-1] = 1;
    generate_rows(aux, size - 1);
    aux[size-1] = 0;
    generate_rows(aux, size - 1);

  }


  std::ostream& wall_t::write(std::ostream& os, std::vector<bool> v) {
    for (int inx = 0; inx < v.size(); ++inx)   
      os << v[inx] << " ";
  }

}



