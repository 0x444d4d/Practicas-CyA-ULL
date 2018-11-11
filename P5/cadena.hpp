#pragma once

#include <iostream>
#include <string>
#include "stack.hpp"

namespace CyA {

class cadena_t {

  private:
    std::string palabra_;
      unsigned size_;

  public:
    cadena_t(void) {}
    cadena_t(std::string input) {palabra_ = input; size_ = input.size();}
    ~cadena_t(void) {}


    std::string inversa(void) {
      stack_t<char> pila_aux(size_);
      std::string palabra_aux;

      for (auto &inx : palabra_) {
        pila_aux.push(inx);
      }   

      //PENDIENTE. Cambiar push_back por un resize
      while (!pila_aux.empty()) { 
        palabra_aux.push_back(pila_aux.top());
        pila_aux.pop();
      }   

      return palabra_aux;
    }
};
}

