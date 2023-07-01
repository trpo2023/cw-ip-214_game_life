#include "../thirdparty/ctest.h"
#include <../src/game_life_lib/copygrid.h>
#include <../src/game_life_lib/countlife.h>
#include <../src/game_life_lib/display.h>
#include <../src/game_life_lib/fileinput.h>
#include <../src/game_life_lib/liveordie.h>
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

CTEST(check_copy, test1)
{
    bool grid[gridsize + 1][gridsize2 + 1] = {};
    bool grid2[gridsize + 1][gridsize2 + 1] = {true};
    bool expected = false;
    copy_grid(grid, grid2);
    for (int a = 0; a < gridsize; a++) {
        for (int b = 0; b < gridsize2; b++) {
            if (grid2[a][b] == grid[a][b])
                expected = true;
        }
    }
    ASSERT_TRUE(expected);
}

CTEST(check_count, test1)
{
    bool expected = false;
    bool grid[gridsize + 1][gridsize2 + 1]
            = {true, true, true, true, true, true, true, true, true};
    int life = 0;
    for (int a = 0; a < gridsize; a++) {
        for (int b = 0; b < gridsize2; b++) {
            count_life(life, a, b, grid);
            if ((life < 9) and (life >= 0))
                expected = true;
        }
    }
    ASSERT_TRUE(expected);
}

CTEST(check_life, test1)
{
    bool expected = false;
    bool grid[gridsize + 1][gridsize2 + 1]
            = {true, true, false, true, true, false, false, false, false};
    bool grid_test[gridsize + 1][gridsize2 + 1]
            = {true, true, false, true, true, false, false, false, false};
    live_or_die(grid);
    for (int a = 0; a < gridsize; a++) {
        for (int b = 0; b < gridsize2; b++) {
            if (grid[a][b] == grid_test[a][b])
                expected = true;
        }
    }
    ASSERT_TRUE(expected);
}

CTEST(check_life, test2)
{
    bool expected = false;
    bool grid[gridsize + 1][gridsize2 + 1]
            = {false, false, false, true, true, true, false, false, false};
    bool grid_test[gridsize + 1][gridsize2 + 1]
            = {false, true, false, false, true, false, false, true, false};
    live_or_die(grid);
    for (int a = 0; a < gridsize; a++) {
        for (int b = 0; b < gridsize2; b++) {
            if (grid[a][b] == grid_test[a][b])
                expected = true;
        }
    }
    ASSERT_TRUE(expected);
}

CTEST(check_life, test3)
{
    bool expected = false;
    bool grid[gridsize + 1][gridsize2 + 1]
            = {false,
               true,
               true,
               false,
               true,
               false,
               false,
               true,
               false,
               true,
               true,
               false};
    bool grid_test[gridsize + 1][gridsize2 + 1]
            = {false,
               true,
               true,
               false,
               true,
               false,
               false,
               true,
               false,
               true,
               true,
               false};
    live_or_die(grid);
    for (int a = 0; a < gridsize; a++) {
        for (int b = 0; b < gridsize2; b++) {
            if (grid[a][b] == grid_test[a][b])
                expected = true;
        }
    }
    ASSERT_TRUE(expected);
}

CTEST(check_life, test4)
{
    bool expected = false;
    bool grid[gridsize + 1][gridsize2 + 1]
            = {false,
               true,
               false,
               true,
               false,
               true,
               true,
               false,
               true,
               false,
               true,
               false};
    bool grid_test[gridsize + 1][gridsize2 + 1]
            = {false,
               true,
               false,
               true,
               false,
               true,
               true,
               false,
               true,
               false,
               true,
               false};
    live_or_die(grid);
    for (int a = 0; a < gridsize; a++) {
        for (int b = 0; b < gridsize2; b++) {
            if (grid[a][b] == grid_test[a][b])
                expected = true;
        }
    }
    ASSERT_TRUE(expected);
}

CTEST(check_life, test5)
{
    bool expected = false;
    bool grid[gridsize + 1][gridsize2 + 1]
            = {false,
               false,
               true,
               false,
               false,
               true,
               false,
               true,
               true,
               false,
               false,
               true,
               false,
               true,
               true,
               false};
    bool grid_test[gridsize + 1][gridsize2 + 1]
            = {false,
               false,
               true,
               false,
               false,
               true,
               false,
               true,
               true,
               false,
               false,
               true,
               false,
               true,
               true,
               false};
    live_or_die(grid);
    for (int a = 0; a < gridsize; a++) {
        for (int b = 0; b < gridsize2; b++) {
            if (grid[a][b] == grid_test[a][b])
                expected = true;
        }
    }
    ASSERT_TRUE(expected);
}