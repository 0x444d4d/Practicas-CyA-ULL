#include <iostream>
#include "wall.hpp"

int main(void) {

  int x;

  std::cin >> x;
  std::cin.get();

  CyA::wall_t muro(x, 3);

  std::cout << "Fin del programa" << std::endl;

} 

