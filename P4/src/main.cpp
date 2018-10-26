#include <iostream>
#include "wall.hpp"

int main(void) {

  CyA::wall_t muro(9, 3);

  std::vector<bool> aux;
  muro.generate_rows();


  std::cout << "Fin del programa" << std::endl;
  std::cin.get();

} 

