#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>


using namespace std;

class listaficheros {

  private: 
  vector<string> fileVector_;
  string path_;
  ifstream inFile;


  public:
  //Constructors.
  listaficheros(string path, std::string key );

  //Destructors.
  ~listaficheros(void) {};

  void set_path(string path);
  void update( std::string key );
  string operator[] (unsigned index);
  ostream& write_file(ostream &os); 
  

};


