#include <../src/game_life_lib/countlife.h>
#include <../src/game_life_lib/display.h>

void count_life(
        int& life, int& a, int& b, bool grid2[gridsize + 1][gridsize2 + 1])
{
    for (int c = -1; c < 2; c++) {
        for (int d = -1; d < 2; d++) {
            if (c == 0 && d == 0) {
                continue;
            }
            if (grid2[a + c][b + d]) {
                life++;
            }
        }
    }
}