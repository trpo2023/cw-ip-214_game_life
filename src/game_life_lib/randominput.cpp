#include <../src/game_life_lib/display.h>
#include <../src/game_life_lib/randominput.h>
#include <cstdlib>
#include <ctime>

void random_input(int rn, bool grid[gridsize + 1][gridsize2 + 1])
{
    srand(time(NULL));
    for (int a = 1; a < gridsize; a++) {
        for (int b = 1; b < gridsize2; b++) {
            rn = rand() % 2;
            if (rn == 0)
                grid[a][b] = false;
            if (rn == 1)
                grid[a][b] = true;
        }
    }
}