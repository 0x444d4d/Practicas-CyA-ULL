#include "greedy_t.hpp"

#include "point_t.hpp"

#include <set>


namespace CyA {

double greedy_t::NN(vector<point_t>& sequence)
{
    set<point_t> pending;
 
    for(const point_t& p: sky_) //Inserta todos los elementos de sky_ en pending.
        pending.insert(p);
    
    //MODIFICACION 1.
    //point_t last = sky_[0];  //Inicializa el ultimo punto a al primero de sky_.
    point_t last = sky_[-1];

    //MODIFICACION 2.
    unsigned int min_dist = -1;
    unsigned int curr_dist = -1;

    point_t origin(0,0);

    for (int index = 0; index < 10 ; ++index) {
      curr_dist = point_t(sky_[index]).distance(origin);

      if (min_dist > curr_dist) {
        last = sky_[index];
        min_dist = curr_dist;
      }

    }   
    
    pending.erase(last);  //saca last de la lista pending.
    sequence.push_back(last);  //mete last en la lista sequence.   
    
    double tour_length = 0;  //inicializa tour_length a 0 ya que todavia solo hay un punto en la lista.
    
    do {
        point_t best_point    = *pending.begin(); //asigna el primer elemento de pending a best_point.
        double  best_distance = last.distance(best_point);  //calcula la distancia desde el ultimo punto a best_point y la guarda en best_distance.
        
        for(const point_t& current: pending) { //Comienza un bucle desde el punto actual hasta que termina pending.
            
            const double current_distance = last.distance(current); //Raliza lo mismo que la linea 26 pero guarda en current_distance.
            
            if (current_distance < best_distance) {  //Ahora si la ultima distancia es mejor que la ultima mejor distancia se actualizan la mejor distancia y el mejor punto.
                
                best_distance = current_distance;
                best_point    = current;
            }
        }
        
        tour_length += best_distance; //Se añade la ultima distancia calculada a el total.
        
        last = best_point; //El ultimo punto coincide con el mejor punto calculado.
        
        pending.erase(last); //Se borra last de la lista.
        sequence.push_back(last);  //Se añade last a sequence.           

    } while(!pending.empty());  //Una vez se han comprobado todas las posiciones de la lista pending termina el bucle.
    
    tour_length += last.distance(sequence[0]); 
    
    return tour_length;
} 

}
