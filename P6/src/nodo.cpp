#include "nodo.hpp"

using namespace cya;

bool node_t::is_death( void ) {
    bool death = true;

    for (auto inx: succesors_) {
      if( node_ != inx.get_inx() )
        return false;
    }   
    return true;
}


unsigned node_t::get_next( char input ) {
  for (auto inx: succesors_) {
    if ( input == inx.get_val() )
      return inx.get_inx();
  }   
  return unsigned( -1 );
}


std::ostream& node_t::write_node( std::ostream& os ) {
  os << std::endl << "Numero de arcos: " << succesors_.size() << std::endl;
  for ( int inx = 0; inx < succesors_.size(); ++inx ) {
    succesors_[inx].write( os );
  }   
  return os;
}
