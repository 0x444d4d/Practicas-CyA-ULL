#pragma once

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <iterator>


namespace CyA {

class lenguaje_t {

  private:
  std::set<std::string> lenguaje_;
  unsigned size_;
  bool infinito_;

  public:

  lenguaje_t(void) {}
  ~lenguaje_t(void) {}

  //unsigned get_size(void) { size_; }

  std::set<std::string> get_lenguaje(void) { return lenguaje_; };
  void insertar_cadena( std::string palabra );
  lenguaje_t inversa(void);
  lenguaje_t concatenacion( lenguaje_t len2 );
  lenguaje_t merge( std::set<std::string> set );
  lenguaje_t interseccion( std::set<std::string> set );
  lenguaje_t diferencia( std::set<std::string> set );
  lenguaje_t potencia( /*lenguaje_t lenguaje,*/ unsigned potencia );
  lenguaje_t kleene(void);
  bool sublenguaje( std::set<std::string> set );
  bool igualdad( std::set<std::string> set );
  std::ostream& write( std::ostream& os) const;
  
  lenguaje_t operator+( lenguaje_t len2 ) {
    return this->merge( len2.get_lenguaje() );
  }

  lenguaje_t operator-( lenguaje_t len2 ) {
    return this->diferencia( len2.get_lenguaje() );
  }

  void operator +=( std::string cadena ) {
    this->insertar_cadena( cadena );
  }

  std::ostream& operator<<( std::ostream& os, const lenguaje_t& len) {
    return len.write( os );
  }


};


}


