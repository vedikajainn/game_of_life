# game_of_life

This is my simple implementation of Conway's Game of Life. More information [here](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

## Rules 

1) Any live cell with two or three live neighbors survives;
2) Any dead cell with three live neighbors becomes a live cell;
3) All other live cells die in the next generation. Similarly, all other dead cells stay dead.

## To run the code:

```
$ g++ RunLife.cpp -o life
$ ./life
```

**_NOTE!! 
I have animated the terminal visualization by moving up the terminal cursor by grid height. Make sure the terminal window is large enough for the entire grid(about 30 lines) to print out otherwise the animation will not print out correctly._**

You may also write to a file by running the command below instead. However the output will not be animated.

```
$ ./life > output.txt
```

## Glider Gun Output

https://user-images.githubusercontent.com/119287665/204223212-a4700a2e-abbb-4418-a4b3-127406740a78.mov


## Design Choices 

* AbstractCell - Although I have not used the AbstractCell Class in this implementation, I have included it to demonstrate how I would extend it in the case we has multiple cell classes each with a different set of rules. I have also set up the grid in the Life class to allow it to be instantiated with whichever cell class we would like. Right now it uses ConwayCell.

* ConwayCell and Life - I have tried to limit the information sharing between main, the Life class and the Cell class. As such Life is the only class that should call the ConwayCells methods. The ConwayCells also do not have information of the whole Life grid. Instead they only have access to num_nieghbors which is enough to determine if the cell should be alive or dead.


## Inputs
Currently main reads from the file input_glider_gun.txt but you can replace line 17 in RunLife.cpp with input_glider.txt to just get the glider animation.


