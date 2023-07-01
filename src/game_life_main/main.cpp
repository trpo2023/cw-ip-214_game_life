#include <../src/game_life_lib/display.h>
#include <../src/game_life_lib/fileinput.h>
#include <../src/game_life_lib/liveordie.h>
#include <../src/game_life_lib/randominput.h>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

int main()
{
    std::cout << "\n-------------------Welcome to the game - "
                 "life----------------------\n";
    const int gridsize = 30;
    const int gridsize2 = 80;
    bool grid[gridsize + 1][gridsize2 + 1] = {};
    char game_option[3];
    int rn = 0, counter_ = 0;
    do {
        for (int i = 0; i < gridsize + 1; i++) {
            for (int j = 0; j < gridsize2 + 1; j++) {
                grid[i][j] = 0;
            }
        }
        print_menu();
        std::cin >> game_option;
        if (strcmp(game_option, "r") == 0) {
            random_input(rn, grid);
        } else if (strcmp(game_option, "f") == 0) {
            file_input(grid, counter_);
        } else if (strcmp(game_option, "0") == 0) {
            exit(0);
        } else {
            std::cout << "Your input is not defined\n\n";
            continue;
        }
        time_t start_time = time(NULL);
        char continue1[3];
        do {
            time_t current_time = time(NULL);
            if (current_time - start_time >= 30) {
                start_time = current_time;
                std::cout << "Continue? Input any value, m to menu, or 0 to "
                             "exit: ";
                std::cin >> continue1;
                if (strcmp(continue1, "0") == 0) {
                    exit(0);
                } else if (strcmp(continue1, "m") == 0) {
                    break;
                }
            }
            display(grid);
            live_or_die(grid);
            unsigned int nanoseconds = 150000;
            usleep(1 * nanoseconds);
            system("clear");
        } while (1);
    } while (1);

    return 0;
}
