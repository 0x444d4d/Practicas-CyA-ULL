#include "wall-old.hpp"
#include <cassert>


namespace CyA
{

  wall_t::wall_t(int x, int y) {
    height = y; length = x;

    fila aux;
    generate_rows(aux);
    for (int inx = 0; inx < strings.size(); ++inx) {
      strings[inx].write_sum();
      std::cout << std::endl;
    }
    compute_compatibles();
    create_wall();

  }


  void wall_t::generate_rows(fila &aux, int len) {
    ladrillo uno(2);
    ladrillo dos(3);

    if (len >= length) {
      if (len == length){
        strings.push_back(aux);
        aux.write();
        std::cout << std::endl;
      }
    } else {
      aux.push(uno);
      generate_rows(aux, len+2);
      aux.pop(uno);

      aux.push(dos);
      generate_rows(aux, len+3);
      aux.pop(dos);
    } 
  }


  void wall_t::compute_compatibles(void) {
    int col;
    int col2;
    bool push;

    compatibles.resize(strings.size());
    
    for (int row = 0; row < strings.size(); ++row ) {
      for (int row2 = 0; row2 < strings.size(); ++row2) {

        col = 0;
        col2 = 0;
        push = true;

        while( (col < strings[row].size() - 1)  && (col2 < strings[row2].size() - 1) ) {
          
          if (strings[row].at(col) == strings[row2].at(col2)) {
            push = false;
            break;
          }else if (strings[row].at(col) < strings[row2].at(col2)) ++col;
          else if (strings[row].at(col) > strings[row2].at(col2)) ++col2;
        }
        if (push) compatibles[row].push_back(row2);
      }  
    }  

    for (int row = 0; row < compatibles.size(); ++row) {
        std::cout << std::endl;
        std::cout << "compatibles con " << row << ": ";
        for (int inx = 0; inx < compatibles[row].size(); ++inx)
          std::cout <<  compatibles[row][inx] << " ";
    }   

    std::cout << std::endl;
    std::cout << std::endl;
  }


  void wall_t::create_wall(void) {
    std::vector<int> aux;
    std::vector<bool> visited(compatibles.size());

    for(int row = 0; row < compatibles.size(); ++row)
      create_wall(aux, visited, row);

    for(int row = 0; row < muros.size(); ++row){
      for(int col = 0; col < muros[row].size(); ++col){
        strings[muros[row][col]].print();
        std::cout << std::endl;
      }

      std::cout << std::endl;
    }
  }


  void wall_t::create_wall(std::vector<int> aux, std::vector<bool> visited, int row, int height){
    if(height == get_y()){
      if (!match_last(aux)) muros.push_back(aux);
      return;
    }

    aux.push_back(row);
    for(int inx = 0; inx < compatibles[row].size(); inx++)
        create_wall(aux, visited, compatibles[row][inx], height + 1);
  }


  bool wall_t::match_last(std::vector<int> aux) {
    if (muros.size() > 0)
      return (muros[muros.size() - 1] == aux) ? true : false;
    return false;
  }


}



