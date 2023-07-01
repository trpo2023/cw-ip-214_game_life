#include <../src/game_life_lib/copygrid.h>
#include <../src/game_life_lib/display.h>

void copy_grid(
        bool grid[gridsize + 1][gridsize2 + 1],
        bool grid2[gridsize + 1][gridsize2 + 1])
{
    for (int a = 0; a < gridsize; a++)
        for (int b = 0; b < gridsize2; b++)
            grid2[a][b] = grid[a][b];
}
