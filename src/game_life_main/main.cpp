#include <iostream>
#include <cstring>

int main(){
	std::cout << "\n-----------Welcome to the game - life---------\n"
			  << "----------Please, select start game option----------\n"
			  << "----Input 'r', if random, input 'f', if from file---\n";
			  
	char game_option[3];
	int rn;
	std::cin >> game_option;
	
	srand(time(NULL));
	if (strcmp(game_option, "r") == 0) {
		std::cout << "Program is running";
	} else if (strcmp(game_option, "f") == 0) {
		std::cout << "file not found\n";
		exit(1);
	} else {
		std::cout << "Your input is not defined";
		exit(1);
	}
}