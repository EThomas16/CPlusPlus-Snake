#include "draw_snake.h"
#include "logic.h"
//required for sleep method
#include <windows.h>
#include <iostream>
#include <vector>

int main() {
	//TODO: implement methods from logic and drawing classes
	//initialise snake position and random number generation
	Draw draw;
	Logic logic;
	std::vector<int> test;

	logic.seedRandom();
	test = logic.getRandomCoords();

	std::cout << "first random number: " << test[0] << std::endl;
	std::cout << "second random number: " << test[1] << std::endl;
	//halts the console closing to see results (for testing)
	std::getchar();
	//commented out since not completed, uncomment once completed
	//draw.drawInit();
	//logic.initPosition();

	//while (true) {
		//call logic and then draw the snake at returned coords
		//draw.drawBoard();
		
		//Sleep(100);
	//}
	return 0;
}