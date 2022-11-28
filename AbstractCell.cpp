#include <stdlib.h>
#include <string>

using namespace std;

class AbstractCell {
    private: 
        bool alive;
        int num_neighbors;

    public: 
        AbstractCell() { 
            alive = false;
            num_neighbors = 0;
        }
        
        bool get_alive () {
            return alive; 
        }
        
        int get_neighbors(){
            return num_neighbors;
        }
    
        void update_alive(bool status) {
            status ? alive = true : alive = false; 
        }
    
        void update_neighbors(int n){
            num_neighbors = n;
        }
    
        virtual string toString() = 0;

        virtual ~AbstractCell(){};
};
