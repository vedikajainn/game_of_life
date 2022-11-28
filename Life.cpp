#include <iostream> // cin, cout
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cassert>
#include <unordered_map>
#include <stdio.h>
#include <unistd.h>

template <typename T>
class Life {
    private:
        // uses template so grid can be initialized with different cells in the future
        vector<vector<T> > grid;
    
    public:
        Life(int rows, int cols, int cells){  
            grid = vector<vector<T> >(rows, vector<T>(cols));
            for(int i = 0; i<rows; i++){
                for(int j = 0; j<cols; j++){
                    T curCell = T();
                    grid[i][j] = curCell;
                }
            }
        }

        // used in RunLife to set initial cells in grid. Use this instead of allowing 
        // main to call methods in ConwayCell class. Only the Life class should be calling
        // methods for the cell. 
        void update_alive (unsigned cell_row, unsigned cell_col) {
            grid[cell_row][cell_col].alive = true; 
        }

        void print_grid() {
            cout << endl;
            for (unsigned r = 0; r < grid.size(); r++) {
                for (unsigned c = 0; c < grid[0].size(); c++) {
                    cout << grid[r][c].toString(); 
                }
                cout << endl;
            } 
        }

        // calculates neighbours
        void update_neighbors(unsigned row, unsigned col) {
            int neighbors = 0; 

            // to check for outof bounds error
            bool n = row > 0; 
            bool s = row < grid.size() -1;
            bool e = col < grid[0].size() -1;
            bool w = col > 0;

            // check n/ne/nw
            if (n && grid[row - 1][col].alive)
                neighbors++;
     
            if (n && e && grid[row - 1][col + 1].alive) 
                neighbors++;
            
            if (n && w && grid[row - 1][col - 1].alive) 
                neighbors++;
            
            // check s/se/sw
            if (s && grid[row + 1][col].alive) 
                neighbors++;

            if (s && e && grid[row + 1][col + 1].alive) 
                neighbors++;
               
            if (s && w && grid[row + 1][col - 1].alive) 
                neighbors++;

            // check e
            if (e && grid[row][col + 1].alive) 
                neighbors++; 

            // check w
            if (w && grid[row][col - 1].alive)  
                neighbors++; 

            grid[row][col].num_neighbors = neighbors; 
        }
    
        void make_changes() {
            for (unsigned row = 0; row< grid.size(); row++) {
                for (unsigned col = 0; col < grid[0].size(); col++) {
                    grid[row][col].update();
                }
            }
        }
    
        void run_sim() {
            while(true) {
                // iterate over the grid and check each cell
                for (unsigned row = 0; row < grid.size(); row++) {
                    for (unsigned col = 0; col < grid[0].size(); col++) {
                        update_neighbors(row, col);
                    }
                }
                make_changes();                 
                print_grid();
                cout<<"\r\x1b[31A"<<flush;
                usleep(100000);
            }
        }
};
        