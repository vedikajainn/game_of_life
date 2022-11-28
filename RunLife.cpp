#include <iostream> // cin, cout
#include <stdlib.h>
#include <sstream>
#include <string>
#include <stdio.h>

#include "ConwayCell.cpp"
#include "Life.cpp"

using namespace std;     
    
int main() {
    freopen("input_glider_gun.txt","r",stdin); // All inputs from 'input_glider_gun.txt' file
    
    // extract how large the grid should be
    string s;
    getline(cin, s);
    istringstream size(s);
    unsigned rows;
    unsigned cols;
    size >> rows >> cols;

    // extract number of initial living cells
    getline(cin, s);
    istringstream cells(s);
    unsigned num_cells;
    cells >> num_cells;
    
    // initialize grid with grid size and cells
    // The Life class is initialized with Conway Cells as the template. Later on if we construct another
    // class with a differnet set of rules it is easy to initalize the grid with those cells insteadd
    Life<ConwayCell> my_life(rows, cols, num_cells);
            
    // set initial cells as living 
    for (unsigned j = 0; j < num_cells; j++) {
        string s;
        getline(cin, s);
        istringstream position(s);
        unsigned cell_row;
        unsigned cell_col;
        position >> cell_row >> cell_col;
        my_life.update_alive(cell_row, cell_col); 
    }  
            
    //run simulation
    my_life.run_sim();
    return 0;
}
