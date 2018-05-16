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
	std::vector<int> coords;
	std::vector<int> snakeCoords;
	std::vector<int> foodCoords;
	int direction = -1;
	int gameOver = 0;

	logic.seedRandom();

	coords = logic.initPosition();
	snakeCoords.push_back(coords[0]);
	snakeCoords.push_back(coords[1]);
	foodCoords.push_back(coords[2]);
	foodCoords.push_back(coords[3]);

	std::cout << "Press w, a, s or d to start";

	while (direction == -1) {
		//loops to prevent snake from moving at the start
		direction = logic.inputHandler();
	}

	while (gameOver == 0) {
		//call logic and then draw the snake at returned coords
		//try and return game over state from logic method
		direction = logic.inputHandler();
		snakeCoords = logic.updatePosition(snakeCoords[0], snakeCoords[1], direction);
		logic.foodCheck(snakeCoords[0], snakeCoords[1], foodCoords[0], foodCoords[1]);
		//drawBoard is called outside the conditional statement to allow the board to be drawn even when the snake is not moving
		gameOver = draw.drawBoard(snakeCoords[0], snakeCoords[1], foodCoords[0], foodCoords[1], logic._snakeTail.tailX, logic._snakeTail.tailY, logic.tailLength);
		Sleep(350);
	}
	return 0;
}