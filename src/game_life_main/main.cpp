#include <iostream>
#include <cstring>

const int gridsize = 30;
const int gridsize2 = 80;

void Display(bool grid[gridsize + 1][gridsize2 + 1]){
    for(int a = 1; a < gridsize; a++){
        for(int b = 1; b < gridsize2; b++){
            if(grid[a][b] == true)
                std::cout << "#";
            else
                std::cout << " ";
            if(b == gridsize2 - 1)
                std::cout << std::endl;
        }
    }
}

int main(){
	std::cout << "\n-------------------Welcome to the game - life----------------------\n"
			  << "-----------------Please, select start game option------------------\n"
			  << "----------Input 'r', if random, input 'f', if from file------------\n"
			  << "---------------Then the program will run for 30 seconds------------\n"
			  << "---You can end the program by entering '0' or by pressing CTRL+Z---\n";
			  
    bool grid[gridsize + 1][gridsize2 + 1] = {};
	char game_option[3], strings[gridsize + 1][gridsize2 + 1], str[gridsize];
	int rn, k = 0, k2 = 0, n = 0, counter_ = 0;
	std::cin >> game_option;
	srand(time(NULL));
	if (strcmp(game_option, "r") == 0) {
		for(int a = 1; a < gridsize; a++) {
	        for(int b = 1; b < gridsize2; b++){	
	        	rn = rand() % 2;
	    		if (rn == 0)
					grid[a][b] = false;
				if (rn == 1)
					grid[a][b] = true;
			}
		}
	}  else if (strcmp(game_option, "f") == 0) {
		std::cout << "file not found\n";
		exit(1);
	} else {
		std::cout << "Your input is not defined";
		exit(1);
	}

	Display(grid);

	return 0;
}