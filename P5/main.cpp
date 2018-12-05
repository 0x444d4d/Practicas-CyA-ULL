#include <iostream>
#include <cstdlib>

#include "lenguaje.hpp"

using namespace CyA;

void input(CyA::lenguaje_t& Leng, std::string L1);

int main(void) {

  int opt;
  CyA::lenguaje_t L1, L2, Lout;

  /*
  L1.insertar_cadena( "hola" );
  L1.insertar_cadena( "ab" );
  L1.insertar_cadena( "a" );
  L2.insertar_cadena( "adios" );
  L2.insertar_cadena( "ba" );
  L2.insertar_cadena( "b" );
  */

  while( 1 ) {
    system( "clear" );
    std::cout << "1.- inversa" << std::endl;
    std::cout << "2.- concatenacion" << std::endl;
    std::cout << "3.- union" << std::endl;
    std::cout << "4.- interseccion" << std::endl;
    std::cout << "5.- diferencia" << std::endl;
    std::cout << "6.- potencia" << std::endl;
    std::cout << "7.- sublenguaje" << std::endl;
    std::cout << "8.- igualdad" << std::endl;
    std::cout << "9.- cierre de Kleene" << std::endl;
    std::cout << "10.- Insertar lenguajes" << std::endl;
    std::cout << "0.- Salir" << std::endl;

    std::cin >> opt;
    std::cin.get();

    system( "clear" );

    switch( opt ) {
      case 0:
        exit(0);
        break;
      case 1:
        cout << L1.inversa();
        std::cin.get();
        Lout.write( std::cout );
        break;
      case 2:
        L1.concatenacion( L2 ).write( std::cout );
        std::cin.get();
        break;
      case 3:
        Lout = L1+L2;
        Lout.write( std::cout );
        std::cin.get();
        break;
      case 4:
        ( L1-L2 ).write( std::cout );
        std::cin.get();
        break;
      case 5:
        L1.diferencia( L2.get_lenguaje() ).write( std::cout );
        std::cin.get();
        break;
      case 6:
        int potencia;
        std::cin >> potencia;
        std::cin.get();
        L1.potencia( /*L1,*/ potencia ).write( std::cout );
        std::cin.get();
        break;
      case 7:
        std::cout << L1.sublenguaje( L2.get_lenguaje() );
        std::cin.get();
        break;
      case 8:
        std::cout << L1.igualdad( L2.get_lenguaje() );
        std::cin.get();
        break;
      case 9:
        std::cout << "Cierre de kleene, L1: ";
        L1.kleene().write( std::cout );
        std::cout << std::endl << "Cierre de kleene, L2: ";
        L2.kleene().write( std::cout );
        std::cin.get();
        break;
      case 10:
        std::string l1;
        std::string l2;

        std::getline(std::cin, l1);
        std::getline(std::cin, l2);
        input(L1, l1 );
        input(L2, l2 );
        break;

    
    }
  }

}

void input(CyA::lenguaje_t& Leng, std::string L1){
  std::string aux;
  std::set<std::string> aux_leng;

  if((L1[0]=='{')&&(L1[L1.size()-1]=='}')){
    for(int i=0; i<L1.size(); i++){
      if((L1[i]==',')||(L1[i]=='}')){
        Leng.insertar_cadena(aux);
        aux="";
      }
      else if((L1[i]!=' ')&&(L1[i]!='{'))
        aux+=L1[i];
    }
  }
}
