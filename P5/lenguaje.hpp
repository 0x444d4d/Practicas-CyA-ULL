#pragma once

#include <iostream>
#include <set>
#include "cadena.hpp"


namespace CyA {

class lenguaje_t {

  private:
  std::set<cadena_t> lenguaje;
  unsigned size_;
  bool infinito_;

  public:
  void insertar_cadena( cadena_t palabra );
  lenguaje_t inversa();
  lenguaje_t concatenacion( lenguaje_t len2 );

};

}


