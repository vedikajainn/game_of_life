#include <stdlib.h>
#include <string>

using namespace std;

class ConwayCell {
    public:
        bool alive;
        int num_neighbors;
    
        ConwayCell() { 
            alive = false;
            num_neighbors = 0;
        }
    
        string toString() {
            if(alive) {
                return "*";
            } else {
                return " ";
            }
        }
    
        int update(){
            if (!(alive) && num_neighbors == 3) {
            // dead cell, needs 3 living neighbors to live
                alive = true; 
            } else if ((alive) && (num_neighbors < 2 || num_neighbors > 3)) { 
            // live cell, needs 2 or 3 living neighbors to live
                alive = false; 
            }
            return alive;
        }
};
