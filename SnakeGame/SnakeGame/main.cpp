#include "draw_snake.h"
#include "logic.h"
//required for sleep method
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

int tailX[100];
int tailY[100];

void updateTail(int snakeX, int snakeY, int tailLength) {
	//this method is created in the main.cpp file to ensure that the tail coordinates are correctly updated
	int prevX = tailX[0];
	int prevY = tailY[0];
	//sets the tail x and y as the old snake's head x and y
	tailX[0] = snakeX;
	tailY[0] = snakeY;

	for (int i = 1; i < tailLength; i++) {
		//loops through each element in the tail updating its position based on the relative position of the head
		int _prevX = tailX[i];
		int _prevY = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = _prevX;
		prevY = _prevY;
	}
}

int main() {
	//class initialisations to allow for usage of functions and attributes
	Draw draw;
	Logic logic;
	std::vector<int> coords;
	std::vector<int> snakeCoords;
	std::vector<int> foodCoords;
	//direction set as -1 to stop snake moving until key is pressed
	int direction = -1;
	//gameOver set to 'false'
	int gameOver = 0;
	//initial speed is set as 500 as this is the delay in ms for the sleep
	int speed = 500;
	//initialises random number generation using the time as the seed
	logic.seedRandom();
	//initialises the starting position of snake and food
	coords = logic.initPosition();
	snakeCoords.push_back(coords[0]);
	snakeCoords.push_back(coords[1]);
	foodCoords.push_back(coords[2]);
	foodCoords.push_back(coords[3]);

	std::cout << "Press w, a, s or d to start" << std::endl;
	
	while (direction == -1) {
		//loops to prevent snake from moving at the start
		direction = logic.inputHandler();
	}

	while (gameOver == 0) {
		//call logic and then draw the snake at returned coords
		//try and return game over state from logic method
		direction = logic.inputHandler();
		//the tail is updated before the position to ensure the previous snake location is correct for the tail knowing where it needs to be
		updateTail(snakeCoords[0], snakeCoords[1], logic.tailLength);
		snakeCoords = logic.updatePosition(snakeCoords[0], snakeCoords[1], direction);
		speed = logic.speedHandler();
		foodCoords = logic.foodCheck(snakeCoords[0], snakeCoords[1], foodCoords[0], foodCoords[1]);
		gameOver = draw.drawBoard(snakeCoords[0], snakeCoords[1], foodCoords[0], foodCoords[1], tailX, tailY, logic.tailLength);
		Sleep(speed);
	}
	return 0;
}