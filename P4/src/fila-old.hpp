#include <vector>
#include "ladrillo-old.hpp"

namespace CyA {

class fila {

  private:
    std::vector<int> fila_;
    std::vector<int> valores_;
    int last_;

  public:
    fila(): last_(0) {}
    ~fila() {}


    void push(ladrillo aux) { 
      fila_.push_back(aux.get_size()); 
      add_val(aux.get_size());
      last_ += aux.get_size();
    }

    void pop(ladrillo aux) { 
      fila_.pop_back(); 
      sub_val(aux.get_size());
      valores_.pop_back();
    }

    void add_val(int aux) { valores_.push_back(last_ + aux); }
    void sub_val(int aux) { last_ -= aux; }
    int size(void) { return fila_.size(); }
    void write(void) { for (int inx = 0; inx < size(); ++inx ) std::cout << fila_[inx] << " "; }

    void print(void) { 
      
      std::cout << "|";   
      for (int inx = 0; inx < size(); ++inx ) {
        if (fila_[inx] == 2) std::cout << "xx";
        if (fila_[inx] == 3) std::cout << "xxx";
        std::cout << "|"; 
      }  
    }

    int at(int pos) { return valores_[pos];}
    void write_sum(void) { for (int inx = 0; inx < size(); ++inx ) { std::cout << valores_[inx] << " ";}}

};

}
