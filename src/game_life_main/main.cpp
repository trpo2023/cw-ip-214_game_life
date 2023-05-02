#include <../src/game_life_lib/display.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::cout << "\n-------------------Welcome to the game - "
                 "life----------------------\n"
              << "-----------------Please, select start game "
                 "option------------------\n"
              << "----------Input 'r', if random, input 'f', if from "
                 "file------------\n"
              << "---------------Then the program will run for 30 "
                 "seconds------------\n"
              << "---You can end the program by entering '0' or by pressing "
                 "CTRL+Z---\n";
    const int gridsize = 30;
    const int gridsize2 = 80;
    bool grid[gridsize + 1][gridsize2 + 1] = {};
    char game_option[3], strings[gridsize + 1][gridsize2 + 1], str[gridsize];
    int rn, k = 0, k2 = 0, n = 0, counter_ = 0;
    do {
        std::cin >> game_option;
        srand(time(NULL));
        if (strcmp(game_option, "r") == 0) {
            for (int a = 1; a < gridsize; a++) {
                for (int b = 1; b < gridsize2; b++) {
                    rn = rand() % 2;
                    if (rn == 0)
                        grid[a][b] = false;
                    if (rn == 1)
                        grid[a][b] = true;
                }
            }
        } else if (strcmp(game_option, "f") == 0) {
            std::ifstream ifs("../../input_life.txt");
            char ch;
            std::string str;
            for (; ifs;) {
                ifs.get(ch);
                if (ifs.eof())
                    break;
                str += ch;
            }
            std::string s1 = "#";
            int* arr = (int*)malloc(str.length() * sizeof(int));
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == s1[0]) {
                    arr[i] = 1;
                } else {
                    arr[i] = 0;
                }
            }
            puts("\n");
            for (int a = 1; a < gridsize + 1; a++) {
                for (int b = 1; b < gridsize2 + 1; b++) {
                    if (arr[a] == 0) {
                        grid[a][b] = false;
                    }
                    counter_++;
                    if (arr[counter_ + a] == 1) {
                        grid[a][b] = true;
                    }
                }
            }
            free(arr);
        } else {
            std::cout << "Your input is not defined";
        }
        Display(grid);
    } while (strcmp(game_option, "0") != 0);
    return 0;
}
