#include "lenguaje.hpp"

using namespace CyA;

  void lenguaje_t::insertar_cadena( std::string palabra ) {
    lenguaje_.insert( palabra );
  }


  lenguaje_t lenguaje_t::inversa(void) {
    std::set<std::string>::iterator iter;
    std::string aux;
    lenguaje_t len_aux;

    for( iter = lenguaje_.begin(); iter != lenguaje_.end(); ++iter ) {
      aux = *iter;

      reverse( aux.begin(), aux.end() );
      len_aux.insertar_cadena(aux);
    }
    return len_aux;
  }


  lenguaje_t lenguaje_t::concatenacion( lenguaje_t len2 ) {
    lenguaje_t L3;
    std::set<std::string>::iterator row;
    std::set<std::string>::iterator col;

    std::set<std::string> aux = len2.get_lenguaje();

    for ( row = lenguaje_.begin(); row != lenguaje_.end(); ++row ) {
      for ( col = aux.begin(); col != aux.end(); ++col ) {
        std::string a = *row;
        std::string b = *col;
        std::string aux = a + b;
        L3.insertar_cadena( aux );
      }
    }   
    return L3;
  }


  lenguaje_t lenguaje_t::merge( std::set<std::string> set ) {
    lenguaje_t L1;
    std::set<std::string> aux;
    std::set<std::string>::iterator iter1;
    std::set<std::string>::iterator iter2;

    //set_union( lenguaje_.begin(), lenguaje_.end(), set.begin(), set.end(), inserter( aux, aux.begin() ) );
    //L1.get_lenguaje() = aux;
    for ( iter1 = lenguaje_.begin(); iter1 != lenguaje_.end() ; ++iter1 ) { 
      L1.insertar_cadena(std::string( *iter1 ) );
    }
    for ( iter2 = set.begin(); iter2 != set.end() ; ++iter2 ) { 
      L1.insertar_cadena(std::string( *iter2 ) );
    }
    return L1;
  }


  lenguaje_t lenguaje_t::interseccion( std::set<std::string> set ) {
    lenguaje_t len_aux;
    std::set<std::string>::iterator row;
    std::set<std::string>::iterator col;

    for ( row = lenguaje_.begin(); row != lenguaje_.end(); ++row ) {
      for ( col = set.begin(); col != set.end(); ++col ) {
        if ( std::string( *row ) == std::string ( *col ) ) len_aux.insertar_cadena( std::string( *row ) );
      }   
    }   

    return len_aux;
  }


  lenguaje_t lenguaje_t::diferencia( std::set<std::string> set ) {
    lenguaje_t len_aux;
    std::set<std::string>::iterator row;
    std::set<std::string>::iterator col;
    bool insertar = true;

    for ( row = lenguaje_.begin(); row != lenguaje_.end(); ++row ) {
      for ( col = set.begin(); col != set.end(); ++col ) {
        if ( std::string( *row ) == std::string ( *col ) ) {
          insertar = false;
          break;
        }
      }   
      if (insertar) len_aux.insertar_cadena( std::string( *row ) ); 
    }   

    return len_aux;
  }


  lenguaje_t lenguaje_t::potencia( /*lenguaje_t lenguaje,*/ unsigned pot ) {
    lenguaje_t len_aux;

    if ( pot ) {  
      len_aux = *this;
      for (int inx = 0; inx < pot - 1; ++inx) {
        len_aux = len_aux.concatenacion( *this );
      }   
      return len_aux;
    } else {
      len_aux.insertar_cadena( "&" );
      return len_aux;
    }
  }

  lenguaje_t lenguaje_t::kleene( void ) {
    lenguaje_t len_aux;

    for (int i = 0; i < 5; ++i) {
      len_aux = len_aux.merge( this->potencia( i ).get_lenguaje() );
    }

    return len_aux;
  }

  bool lenguaje_t::sublenguaje( std::set<std::string> set ) {
    if ( this->diferencia( set ).get_lenguaje().size() == 0 ) return true;
    return false;
  }

  bool lenguaje_t::igualdad( std::set<std::string> set ) {
    if ( this->diferencia( set ).get_lenguaje().size() == 0 ) 
      if ( lenguaje_.size() == set.size() ) 
        return true;
    return false;
  }

  std::ostream& lenguaje_t::write( std::ostream& os ) const {
    lenguaje_t len_aux;
    std::set<std::string>::iterator row;

    for ( row = lenguaje_.begin(); row != lenguaje_.end(); ++row ) {
      std::cout << std::string(*row) << " ";
    }   
  }   
