#include "../include/grammar.hpp"

using namespace cya;

char grammar_t::int_to_case( unsigned number ) {
  if (number == init_) return 'S';
  if (number < init_) ++number;
  if ( number < 28 ) return char( 'A' + (--number));
  return int(0);
}

char grammar_t::int_to_char( unsigned number ) {
  if ( number < 28 ) return char( 'a' + number );
  return int(0);
}

grammar_t::grammar_t( automata_t dfa ) {

  /*
  std::vector< char > aux;
  for (unsigned inx; inx < dfa.get_size(); ++inx ) {
    for ( auto list : dfa[inx].get_succesors() ) {
      aux.push_back( list.get_val() );
    }   
    term_.insert( std::make_pair( int_to_case( inx ), aux ));
    ++size_;
    aux.clear();
  }   
  */

  build_from_dfa( dfa );
}

void grammar_t::build_from_dfa( automata_t dfa ) {

  if (!dfa.is_dfa()) {
    std::cerr << "El automata no es dfa" << std::endl;
    return;
  }

  alphabet_ = dfa.get_alphabet();
  unsigned next;
  std::vector<std::pair<unsigned, char> > aux;

  states_ = dfa.get_size();
  for (unsigned inx = 0; inx < states_; ++inx ) {
    if (inx == dfa.get_init()) init_ = inx;
    for (auto caracter : alphabet_ ) {
      next = dfa[inx].get_next(caracter);
      aux.push_back( make_pair( next, caracter ) );
      ++size_;
    }   
    if ( dfa[inx].is_last() ) aux.push_back( make_pair( inx, '~' ) );
    term_.insert( transicion_t( inx, aux));
    aux.clear();
  }   
}


std::ostream& grammar_t::write( std::ostream& os ) {

  //No de simbolos terminales;
  os << alphabet_.size() << std::endl;

  //Simbolos terminales;
  for (char c : alphabet_)
    os << c << " ";
  os << std::endl;

  //No de simbolos no terminales;
  os << states_ << std::endl;

  //Simbolos no terminales;
  for (unsigned inx = 0; inx < states_; ++inx)
    os << int_to_case(inx) << " ";
  os << std::endl;

  for ( auto iter : term_ ) {
    os << int_to_case( iter.from() );
    os << " " << "-> " ;
    for ( auto tran : iter.to() ) {
      os << tran.second;
      if ( tran.second != '~' )
        os  << int_to_case( tran.first );
      os << " | ";
      
    }
    os << std::endl;
  }

  return os;
}
