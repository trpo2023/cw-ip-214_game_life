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

void print_menu()
{
    std::cout << "\n-----------------Please, select start game "
                 "option------------------\n"
              << "----------Input 'r', if random, input 'f', if from "
                 "file------------\n"
              << "---------------Then the program will run for 30 "
                 "seconds------------\n"
              << "---You can end the program by entering '0' or by pressing "
                 "CTRL+Z---\n";
}
