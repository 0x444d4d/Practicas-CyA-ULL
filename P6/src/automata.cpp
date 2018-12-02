#include "../include/automata.hpp"

using namespace cya;

typedef std::set<node_t>::iterator iter;


void automata_t::load_data( std::string file_name ) {
  unsigned size, start, end, tran; 
  unsigned node = 0;
  vector_n suc;
  pair_t<char> aux;
  ifstream file;

  nodes_.clear();
  set_index_.clear(); 
  
  file.open( file_name );

  file >> size >> init_;
  size_ = size;

  while ( node < ( size - 1 ) ) {
    file >> node >> end >> tran;

    for ( int inx = 0; inx < tran ; ++inx ) {
      file >> aux.get_val() >> aux.get_inx();
      languaje_.insert( aux.get_val() );
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
  int inx = init_;

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


bool automata_t::evaluate_nfa( std::string input ) {
  std::vector<unsigned> last;
  evaluate_nfa( input, last, init_ );

  for (auto pos : last ) {
    if ( node_t(*(set_index_[pos])).is_last() ) {
      return true;
    } 
  }   
  return false;
}


void automata_t::evaluate_nfa( std::string input, std::vector<unsigned>& last,  int inx ) {

  std::vector<unsigned> next;
  auto it = set_index_[inx];
  unsigned i;

  next = node_t(*it).get_succesors( input[0] );
  if ( input.size() == 0 ) last.push_back( inx );

  for (i = 0; i < next.size() ; ++i) {
    if (input.size() > 0) {
      evaluate_nfa( std::string(input.begin() +1, input.end() ) , last, next[i] );
    }
  }   
}


void automata_t::death_states( void ) {
  node_t node;

  for ( auto nod: set_index_ ) {
    node = node_t( *nod );
    if ( node.is_death() )
      std::cout << "Es nodo: " << node.get_node() << " es un estado de muerte" <<  std::endl;
  }   

}


bool automata_t::is_dfa( void ) const {
  for (int inx = 0 ; inx < set_index_.size(); ++inx) {
    for (auto it = languaje_.begin(); it != languaje_.end(); ++it )
      if ( node_t(*set_index_[inx]).output_degree( *it ) != 1) return false;
  }   
  return true;
}

void automata_t::important_nodes( void ) {
  std::vector< int > imp, notimp;
  node_t node;

  for (int inx = 0; inx < set_index_.size(); ++inx ) {
    node = node_t(*set_index_[inx]);

    if ( !node.is_death() || node.is_last() )
      imp.push_back(inx);
    else
      notimp.push_back(inx);
      
  }   

  std::cout << "Nodos importantes:";
  for (auto inx : imp )
    std::cout << " " << inx;
  std::cout << std::endl << "Nodos no importantes:";
  for (auto inx : notimp )
    std::cout << " " << inx;
}


std::ostream& automata_t::write_set( std::ostream& os ) {
  os << "Numero de nodos " << nodes_.size() << std::endl;
  for( iter iterator = nodes_.begin(); iterator != nodes_.end(); ++iterator) {
    node_t(*iterator).write_node( os );
  }
  return os;
}

