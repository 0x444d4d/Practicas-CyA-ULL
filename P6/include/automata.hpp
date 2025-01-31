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
  int size_;
  unsigned init_;
  std::set< char > languaje_;
  std::set<node_t, SortOrder> nodes_;
  std::vector<std::set<node_t>::iterator> set_index_;

  public:
  automata_t( void ) {}
  ~automata_t( void ) {}

  inline int get_size( void ) { return size_; };
  bool evaluate( std::string input );
  bool evaluate_nfa( std::string input );
  bool is_dfa( void ) const;
  void important_nodes( void );
  void load_data( std::string file_name );
  void index_set( void );
  void evaluate_nfa( std::string input, std::vector<unsigned>& last, int inx );
  void death_states( void );
  ostream& write_set( std::ostream& os );


};


}

