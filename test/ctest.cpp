#include "../thirdparty/ctest.h"
#include <../src/game_life_lib/display.h>
#include <../src/game_life_lib/fileinput.h>
#include <../src/game_life_lib/randominput.h>

CTEST(check_input, random)
{
    bool grid[gridsize + 1][gridsize2 + 1] = {};
    bool expected = false;
    int rn = 0;
    random_input(rn, grid);
    for (int a = 1; a < gridsize; a++) {
        for (int b = 1; b < gridsize2; b++) {
            if (grid[a][b] == false || grid[a][b] == true)
                expected = true;
        }
    }
    ASSERT_TRUE(expected);
}

CTEST(check_input, file)
{
    bool grid[gridsize + 1][gridsize2 + 1] = {};
    bool expected = false;
    int counter_ = 0;
    file_input(grid, counter_);
    for (int a = 1; a < gridsize; a++) {
        for (int b = 1; b < gridsize2; b++) {
            if (grid[a][b] == false || grid[a][b] == true)
                expected = true;
        }
    }
    ASSERT_TRUE(expected);
}
