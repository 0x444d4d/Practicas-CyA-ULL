#pragma once

#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <iterator>
#include "nodo.hpp"
#include "pair_t.hpp"

namespace cya {

struct SortOrder {
  bool operator() ( const node_t& first, const node_t& second ) {
    return ( first.get_node() < second.get_node() );
  }
};

class automata_t {
  
  private:
  unsigned size_;
  unsigned init_;
  std::set< char > alphabet_;
  std::set<node_t, SortOrder> nodes_;
  std::vector<std::set<node_t>::iterator> set_index_;

  public:
  automata_t( void ) {}
  ~automata_t( void ) {}

  //Getters
  //inline std::set<node_t, SortOrder>& get_nodes( void ) const { return nodes_; }
  inline std::set<node_t, SortOrder>& get_nodes( void ) { return nodes_; }
  inline unsigned get_init( void ) const { return init_; }
  inline unsigned get_size( void ) const { return size_; }
  inline unsigned get_size( void ) { return size_; };
  inline std::set<char> get_alphabet( void ) const { return alphabet_; }

  //Metodos
  bool evaluate( std::string input ); //Comprueba si la cadena introducida es compatible con un dfa;
  bool evaluate_nfa( std::string input ); //Comprueba si la cadena introducida es compatible con un nfa;
  bool is_dfa( void ) const; //Comprueba si el automata es o no determinista;
  void important_nodes( void ); //Muestra los nodos importantes;
  void load_data( std::string file_name ); //carga un fichero "automata".aut;
  void death_states( void ); //Mustra los estados de muerte;
  ostream& write_set( std::ostream& os ); //imprime el automata;

  //Sobrecargas de operadores
  
  //Acceder a un nodo concreto del automata;
  node_t operator[] ( unsigned pos ) { return node_t( *set_index_[ pos ] ); }
  node_t operator[] ( unsigned pos ) const { return node_t( *set_index_[ pos ] ); }

  //Insertar nodos en el automata;
  automata_t& operator+= ( const node_t& b ) { 
    this->get_nodes().insert(b); 
    return *this;
  }

  private:
  void evaluate_nfa( std::string input, std::vector<unsigned>& last, int inx );
  void index_set( void ); //Metodo que indexa el set para evitar iteraciones;

};


}

