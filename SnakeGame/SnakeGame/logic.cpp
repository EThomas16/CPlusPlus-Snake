#include "logic.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <conio.h>

/*TODO: return values from logic to pass into draw in main.cpp
		handle increase of score
		increase length of snake*/
std::vector<int> Logic::initPosition() {
	//TODO: check if required if being drawn already (might be for calculation purposes)
	std::vector<int> foodCoords;
	std::vector<int> snakeCoords;
	std::vector<int> allCoords;

	foodCoords = getRandomCoords();
	foodX = foodCoords[0];
	foodY = foodCoords[1];

	snakeCoords = getRandomCoords();
	snakeX = snakeCoords[0];
	snakeY = snakeCoords[1];

	allCoords.push_back(snakeX);
	allCoords.push_back(snakeY);
	allCoords.push_back(foodX);
	allCoords.push_back(foodY);

	return allCoords;
}
//check if the first two parameters are required
std::vector<int> Logic::updatePosition (int snakeX, int snakeY, int direction) {
	switch (direction) {
		//depending on the direction, the x and y coordinates of the snake are altered
		//the cases used are based on the keyboard input (WASD) for movement
		case 0:
			snakeY--;
			break;
		case 1:
			snakeY++;
			break;
		case 2:
			snakeX++;
			break;
		case 3:
			snakeX--;
			break;
	}
	std::vector<int> snakeCoords;
	snakeCoords.push_back(snakeX);
	snakeCoords.push_back(snakeY);

	return snakeCoords;
}

void Logic::foodCheck(int snakeX, int snakeY, int foodX, int foodY) {
	if (snakeX == foodX && snakeY == foodY) {
		tailLength++;
	}
}

void Logic::updateTail() {
	int prevX = _snakeTail.tailX[0];
	int prevY = _snakeTail.tailY[0];
	
	_snakeTail.tailX[0] = snakeX;
	_snakeTail.tailY[0] = snakeY;

	for (int i = 0; i < tailLength; i++) {
		int _prevX = _snakeTail.tailX[i];
		int _prevY = _snakeTail.tailY[i];
		_snakeTail.tailX[i] = prevX;
		_snakeTail.tailY[i] = prevY;
		prevX = _prevX;
		prevY = _prevY;
	}
}

int Logic::inputHandler() {
	//continuously checks keyboard input to see what the most recent key-press is
	//allows for asynchronous movement of the snake
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			direction = 0;
			break;
		case 's':
			direction = 1;
			break;
		case 'd':
			direction = 2;
			break;
		case 'a':
			direction = 3;
			break;
		}
	}
	return direction;
}

void Logic::seedRandom() {
	srand(time(NULL));
}

std::vector<int> Logic::getRandomCoords() {
	//Creates a vector to store the new food coordinates, then acquires a random value to store
	std::vector<int> coords;
	int xCoord = (std::rand() % width) - 1;
	int yCoord = (std::rand() % height) - 1;
	//Random coordinates are then added to the vector
	coords.push_back(xCoord);
	coords.push_back(yCoord);

	return coords;
}