#include "logic.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <conio.h>

std::vector<int> Logic::initPosition() {
	std::vector<int> foodCoords;
	std::vector<int> snakeCoords;
	std::vector<int> allCoords;

	foodCoords = getRandomCoords();
	foodX = foodCoords[0];
	foodY = foodCoords[1];

	//use if random initial coords for snake wanted
	/*snakeCoords = getRandomCoords();
	snakeX = snakeCoords[0];
	snakeY = snakeCoords[1];*/

	//set coordinates to prevent issues with randomly spawning in walls
	allCoords.push_back(10);
	allCoords.push_back(10);
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

std::vector<int> Logic::foodCheck(int snakeX, int snakeY, int foodX, int foodY) {
	//checks if the food has been 'eaten' by the snake based on the coordinates of each
	std::vector<int> foodCoords;
	if (snakeX == foodX && snakeY == foodY) {
		//increases tail length for each food eaten
		tailLength++;
		//and gets a new random position for the food
		foodCoords = getRandomCoords();
	}
	else {
		//otherwise uses the previous food position to keep it consistent
		foodCoords.push_back(foodX);
		foodCoords.push_back(foodY);
	}
	return foodCoords;
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

int Logic::speedHandler() {
	//initial speed is set as the lowest possible
	//when the tail length exceeds the given value the lowest speed value will be returned
	int speed = 200;
	if (tailLength < 15) {
		speed = 500 - (tailLength * 20);
	}
	return speed;
}

void Logic::seedRandom() {
	//Seeds the RNG based on the time
	srand(time(NULL));
}

std::vector<int> Logic::getRandomCoords() {
	//Creates a vector to store the new food coordinates, then acquires a random value to store
	std::vector<int> coords;
	int xCoord = std::rand() % width;
	int yCoord = std::rand() % height;
	//Random coordinates are then added to the vector
	coords.push_back(xCoord);
	coords.push_back(yCoord);

	return coords;
}