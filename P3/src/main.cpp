#include <cstdio>
#include <vector>
#include <random>
#include <iostream>

#include "sorted_vector_t.hpp"

#define LIMIT 999
#define SIZE   80

using namespace std;

int main(void)
{	
    bool mode = false;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(-LIMIT, LIMIT);    
    
    CyA::sorted_vector_t v;
    
    for(int i = 0; i < SIZE; i++)
        v.push_back(distribution(generator));
        
    cout << v << endl;
    
    cout << "0: merge sort recursivo" << endl << "1: merge sort iterativo" << endl;
    cin >> mode;
    cin.get();

    v.merge_sort(mode);
    
    cout << v << endl;
    
	return 0;
}
