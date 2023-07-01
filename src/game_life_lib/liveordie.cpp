#include <../src/game_life_lib/copygrid.h>
#include <../src/game_life_lib/countlife.h>
#include <../src/game_life_lib/display.h>
#include <../src/game_life_lib/liveordie.h>

void live_or_die(bool grid[gridsize + 1][gridsize2 + 1])
{
    bool grid2[gridsize + 1][gridsize2 + 1] = {};
    copy_grid(grid, grid2);
    for (int a = 1; a < gridsize; a++) {
        for (int b = 1; b < gridsize2; b++) {
            int life = 0;
            count_life(life, a, b, grid2);
            bool isAlive = false;
            if (life == 3)
                isAlive = true;
            else if (life == 2 && grid[a][b])
                isAlive = true;
            grid[a][b] = isAlive;
        }
    }
}
