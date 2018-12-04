#include "../include/filelist.hpp"


listaficheros::listaficheros(string path, std::string key): path_(path){
  update( key );
}


void listaficheros::set_path(string path) {
  path_ = path;
}


void listaficheros::update( std::string key) {  
  string aux;

  fileVector_.clear();

  system((string("ls ") + path_ + string(" > ") + path_ + string("filelist.txt")).c_str());
  inFile.open( ( path_ + string("filelist.txt") ).c_str() );

  while(inFile >> aux) {
    if ( aux.rfind( key ) != string::npos ) 
      fileVector_.push_back(aux);
  }
  inFile.close();
}


string listaficheros::operator[](int index) { 
  if (--index < fileVector_.size()) {
    return fileVector_[index];
  } else return "0";
}


ostream& listaficheros::write_file(ostream &os) {
  int pos = 1;
  
  for ( auto inx : fileVector_ ) {
    os << pos++ << ": " << inx;
    os << std::endl;
  }
  return os;
}
