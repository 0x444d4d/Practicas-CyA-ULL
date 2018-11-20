#include "automata.hpp"

using namespace cya;

typedef std::set<node_t>::iterator iter;


void automata_t::load_data( std::string file_name ) {
  unsigned size, start, end, tran; 
  unsigned node = 0;
  vector_n suc;
  pair_t<char> aux;
  ifstream file;
  
  file.open( file_name );
  if ( file.is_open() && file ) std::cout << "Fichero abierto" << std::endl;

  file >> size >> start;
  //std::cout << size << " " << start << std::endl;
  size_ = size;

  while ( node < ( size - 1 ) ) {
    file >> node >> end >> tran;

    for ( int inx = 0; inx < tran ; ++inx ) {
      file >> aux.get_val() >> aux.get_inx();
      suc.push_back(aux);
    }   

    nodes_.insert( node_t( start, end, node, suc ) );
    suc.clear();
  }

  index_set();
}


void automata_t::index_set( void ) {
  auto it = nodes_.begin();

  for ( it; it != nodes_.end() ; ++it) {
    set_index_.push_back( it );
  }   
}


bool automata_t::evaluate( std::string input ) {
  int inx = 0;

  std::cout << std::left << std::setw(17) << "Estado actual";
  std::cout << std::left << std::setw(10) << "Entrada";
  std::cout << std::left << std::setw(20) << "Siguiente estado" << std::endl;

  for(auto character: input) {
    auto it = set_index_[inx];
    inx = node_t(*it).get_next( character );

    std::cout << std::left << std::setw(17) << node_t(*it).get_node();
    std::cout << std::left << std::setw(10) << character;
    std::cout << std::left << std::setw(20) << inx << std::endl;

    if ( inx == unsigned( -1 ) || node_t(*( set_index_[inx] ) ).is_death() ) return false;
  }
  return node_t( *set_index_[inx] ).is_last();
}


void automata_t::death_states( void ) {
  node_t node;

  for ( auto nod: set_index_ ) {
    node = node_t( *nod );
    if ( node.is_death() )
      std::cout << "Es nodo: " << node.get_node() << " es un estado de muerte" <<  std::endl;
  }   

}


std::ostream& automata_t::write_set( std::ostream& os ) {
  os << "Numero de nodos " << nodes_.size() << std::endl;
  for( iter iterator = nodes_.begin(); iterator != nodes_.end(); ++iterator) {
    node_t(*iterator).write_node( os );
  }
  return os;
}

