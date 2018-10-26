#include <iostream>
#include "wall.hpp"

int main(void) {

  int x;

  std::cin >> x;
  std::cin.get();

  CyA::wall_t muro(x, 3);

  std::vector<bool> aux;
  muro.generate_rows();

  std::cout << "Fin del programa" << std::endl;
  std::cin.get();

} 

