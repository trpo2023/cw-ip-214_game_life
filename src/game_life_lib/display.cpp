#include <../src/game_life_lib/display.h>
#include <iostream>

void display(bool grid[gridsize + 1][gridsize2 + 1])
{
    for (int a = 1; a < gridsize; a++) {
        for (int b = 1; b < gridsize2; b++) {
            if (grid[a][b] == true)
                std::cout << "#";
            else
                std::cout << " ";
            if (b == gridsize2 - 1)
                std::cout << std::endl;
        }
    }
}
