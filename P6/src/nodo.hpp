#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "pair_t.hpp"


namespace cya {
typedef std::vector<cya::pair_t< char > > vector_n;

class node_t {
  
  private:
  bool starting_;
  bool ending_;
  vector_n succesors_;
  unsigned node_;
  
  public:
  //Constructores
  node_t( void ) {}
  node_t( bool start, bool end, unsigned node, vector_n suc):
    starting_( start ), ending_(end), node_(node), succesors_(suc) {}
  //Destructor
  ~node_t( void ) {}

  //Metodos
  unsigned get_node( void ) const { return node_; }
  vector_n get_succesors( void ) const { return succesors_; }
  bool is_last( void ) { return ending_; }


  bool is_death( void );
  unsigned get_next( char input );
  std::ostream& write_node( std::ostream& os );

};


}
