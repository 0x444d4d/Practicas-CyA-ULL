#include <iostream>
#include "wall-old.hpp"

int main(void) {

  int x;
  int y;

  std::cin >> x;
  std::cin >> y;
  std::cin.get();

  CyA::wall_t muro(x, y);

  std::cout << "Fin del programa" << std::endl;

} 

