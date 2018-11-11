#include <iostream>

#include "lenguaje.hpp"

int main(void) {

  std::string cadena;

  std::cout << "Inicio del programa" << std::endl;

  std::cin >> cadena;
  std::cin.get();

  CyA::cadena_t lenguaje(cadena);
  std::cout << lenguaje.inversa() << std::endl;

  std::cout << "Fin del programa" << std::endl;

}
