#include <iostream>
#include <cstdlib>
#include "automata.hpp"

void print_menu( void );

int main( void ) {
  cya::automata_t aut;
  std::string cadena;
  short opt;


  while(true) {
    print_menu();

    std::cin >> opt;
    std::cin.get();

    switch(opt) {
      case 0:
        exit(0);
        break;

      case 1:
        aut.load_data( "automata.txt" );
        std::cin.get();
        break;

      case 2:
        aut.death_states();
        std::cin.get();
        break;

      case 3:
        std::cout << "Cadena a evaluar: " << std::endl;
        std::cin >> cadena;
        std::cin.get();

        if ( aut.evaluate( cadena ) )
          std::cout << "La cadena es valida";
        else
          std::cout << "La cadena es invalida";

        std::cin.get();
        break;

      default:
        std::cout << "La opcion no es valida" << std::endl;
        std::cin.get();
    }
  }
}


void print_menu( void ) {
  system("clear");
  std::cout << "1.- Cargar DFA" << std::endl;
  std::cout << "2.- Mostrar estados de muerte" << std::endl;
  std::cout << "3.- Evaluar cadena" << std::endl; 
  std::cout << "0.- Salir" << std::endl;
}
