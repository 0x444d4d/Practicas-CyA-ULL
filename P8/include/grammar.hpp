#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <iterator>
#include "automata.hpp"

namespace cya {


class transicion_t {
  private:
  unsigned from_;
  std::vector< std::pair <unsigned, char > > to_;

  public:
  transicion_t (unsigned from, std::vector< std::pair <unsigned, char > > to): from_(from), to_(to) {}
  unsigned from() const { return from_; }
  std::vector<std::pair <unsigned, char> > to() const { return to_; }

};


/*
struct transicion {
  unsigned from;
  std::pair< unsigned, char > to; };
*/


struct grSort {
  bool operator() ( const transicion_t& left, const transicion_t& right ){
    if (left.from() == 20) return true;
    if (right.from() == 20) return false;
    //if (left.from() == init_) return true;
    if (left.from() < right.from()) return true;
    else return false;
  }
};


class grammar_t {

  private:
  unsigned size_;
  unsigned states_;
  unsigned init_;
  std::set<char> alphabet_;
  std::set< transicion_t, grSort > term_;


  public:
  grammar_t( void ) {}; //Constructo por defecto.
  grammar_t( automata_t dfa ); //Constructor que recibe un automata.
  ~grammar_t( void ) {}
  void build_from_dfa( automata_t dfa ); //Método que carga el dfa y lo convierte a gramatica.
  std::ostream& write( std::ostream& os );

  //Sobrecargas.
  ostream& operator<< ( ostream& os ) { return write( os ); } //Eporta la gramatica a un fichero.

  private:
  char int_to_case( unsigned number);
  char int_to_char( unsigned number);
   
};

}

