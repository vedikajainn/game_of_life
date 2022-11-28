# game_of_life

This is my simple implementation of Conway's Game of Life. More information [here](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

## Rules 

1) Any live cell with two or three live neighbors survives;
2) Any dead cell with three live neighbors becomes a live cell;
3) All other live cells die in the next generation. Similarly, all other dead cells stay dead.

## To run the code:

'''
$ g++ RunLife.cpp -o life
$ ./life
'''

NOTE!! 
I have animated the terminal visualization by moving up the terminal cursor by grid height. Make sure the terminal window is large enough for the entire grid to print out otherwise the animation will not print out correctly.

You may also write to a file by running the command below instead. However the output will not be animated

'''
$ ./life > output.txt
'''


## Design Choices 
-- AbstractCell


## Inputs
Currently main reads from the file input_glider_gun.txt but you can replace line 17 in RunLife.cpp with input_glider.txt to just get the glider animation.


