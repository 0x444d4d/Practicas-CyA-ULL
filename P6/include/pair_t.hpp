#pragma once

#include <iostream>
#include <iomanip>

using namespace std;
namespace cya {

template <class T >
class pair_t
{
private:
	unsigned    inx_;
	T      val_;
public:
	pair_t(void):
		inx_(-1),
		val_(){} 

	pair_t(unsigned inx, T val):
		inx_(inx),
		val_(val){}

	~pair_t(void) {}

	void set(unsigned inx, T val){
	
		inx_ = inx;
		val_ = val;
	}

	unsigned&   get_inx(void)       {return inx_;}
	unsigned    get_inx(void) const {return inx_;}
	T&     get_val(void)       {return val_;}
	T      get_val(void) const {return val_;}

	ostream& write(ostream& os) {
	
		os << "("<< setw(3) << inx_ << ", " ;
    os << val_;
		os << ")";
		return os;
	}

	istream& read(istream& is){
	
		is >> inx_ >> val_;
		return is;
	}

};
}
