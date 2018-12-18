
#include <iostream>
#include <cstdlib>
#include "../include/automata.hpp"
#include "../include/filelist.hpp"
#include "../include/grammar.hpp"
const std::string PATH = "./Automatas/";

void print_menu( void );

int main( int argc, char *argv[] ) {
  cya::automata_t aut;
  cya::grammar_t gr;
  std::string cadena;
  short opt;
  listaficheros lista( PATH, ".aut" );


  if (argc > 1) {
    std::string ifile;
    std::ofstream ofile;
  
    for (int inx = 1; inx < ( argc - 1 ) ; ++inx ) {
      if ( std::string(argv[inx] ) == "-i" ) ifile = argv[++inx];
      if ( std::string(argv[inx] ) == "-o" ) ofile.open(argv[++inx]);
    }
  
    aut.load_data( "DFA0.aut" );
    gr.build_from_dfa( aut );
    gr << ofile;

    exit(0);
  }


  while(true) {
    print_menu();

    std::cin >> opt;
    std::cin.get();

    switch(opt) {
      case 0:
        exit(0);
        break;

      case 1:
        static short pos;
        system("clear");
        std::cout << "Lista de ficheros: " << std::endl;
        lista.write_file( std::cout );
        std::cout << "0: Cancelar" << std::endl;
        
        std::cin >> pos;
        std::cin.get();

        if (pos) aut.load_data( PATH + ( lista[ pos ] ) );
        std::cin.get();
        break;

      case 2:
        system("clear");
        if ( aut.is_dfa() )
          std::cout << "El automata es DFA";
        else
          std::cout << "El automata es NFA";

        std::cin.get();
        break;

      case 3:
        system("clear");
        aut.death_states();
        std::cin.get();
        break;

      case 4:
        system("clear");
        aut.important_nodes();
        std::cin.get();
        break;

      case 5:
        system("clear");
        std::cout << "Cadena a evaluar: " << std::endl;
        std::cin >> cadena;
        std::cin.get();

        switch( aut.is_dfa() ) {
        
          case 1:
            if ( aut.evaluate( cadena ) )
              std::cout << "La cadena es valida";
            else
              std::cout << "La cadena es invalida";
            break;

          case 0:
            if ( aut.evaluate_nfa( cadena ) )
              std::cout << "La cadena es valida";
            else
              std::cout << "La cadena es invalida";
            break;
        }

        std::cin.get();
        break;

      default:
        system("clear");
        std::cout << "La opcion no es valida" << std::endl;
        std::cin.get();
    }
  }
}


void print_menu( void ) {
  system("clear");
  std::cout << "1.- Cargar DFA" << std::endl;
  std::cout << "2.- Mostrar tipo de automata" << std::endl;
  std::cout << "3.- Mostrar estados de muerte" << std::endl;
  std::cout << "4.- Mostrar estados importantes" << std::endl;
  std::cout << "5.- Evaluar cadena" << std::endl; 
  std::cout << "0.- Salir" << std::endl;
}
