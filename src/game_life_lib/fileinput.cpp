#include <../src/game_life_lib/display.h>
#include <../src/game_life_lib/fileinput.h>

void file_input(bool grid[gridsize + 1][gridsize2 + 1], int counter_)
{
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
    int* arr = new int(str.length());
    for (size_t i = 0; i < str.length(); i++) {
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
    delete arr;
}
