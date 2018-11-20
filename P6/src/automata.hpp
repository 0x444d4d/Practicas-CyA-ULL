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
  std::set<node_t, SortOrder> nodes_;
  std::vector<std::set<node_t>::iterator> set_index_;
  int size_;

  public:
  automata_t( void ) {}
  ~automata_t( void ) {}

  inline int get_size( void ) { return size_; };
  void load_data( std::string file_name );
  void index_set( void );
  bool evaluate( std::string input );
  void death_states( void );
  ostream& write_set( std::ostream& os );


};


}

