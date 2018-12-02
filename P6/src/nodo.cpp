#include "../include/nodo.hpp"

using namespace cya;

bool node_t::is_death( void ) {
  bool death = true;

  for (auto inx: succesors_) {
    if( node_ != inx.get_inx() )
      return false;
  }   
  return true;
}


std::vector<unsigned> node_t::get_succesors( char input ) const {
  std::vector<unsigned> aux;

  for (auto inx: succesors_) {
    if ( input == inx.get_val() )
      aux.push_back( inx.get_inx() );
  }   
  return aux;
}


unsigned node_t::get_next( char input ) {
  for (auto inx: succesors_) {
    if ( input == inx.get_val() )
      return inx.get_inx();
  }   
  return unsigned( -1 );
}


unsigned node_t::output_degree( char input ) const {
  unsigned int count = 0;
  for (auto inx: succesors_) {
    if ( input == inx.get_val() )
      ++count;
  }
  return count;
}


std::ostream& node_t::write_node( std::ostream& os ) {
  os << std::endl << "Numero de arcos: " << succesors_.size() << std::endl;
  for ( int inx = 0; inx < succesors_.size(); ++inx ) {
    succesors_[inx].write( os );
  }   
  return os;
}
