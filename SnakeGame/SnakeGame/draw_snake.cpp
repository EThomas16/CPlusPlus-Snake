#include "draw_snake.h"
#include "logic.h"
#include <iostream>
#include <vector>

void Draw::drawInit() {
	Draw::food food;
	Draw::snake snake;
	Logic logic;
	std::vector<int> foodCoords;
	std::vector<int> snakeCoords;

	food.shape = 'o';
	foodCoords = logic.getRandomCoords();
	food.xCoord = foodCoords[0];
	food.yCoord = foodCoords[1];

	snakeCoords = logic.getRandomCoords();
	snake.xCoord = snakeCoords[0];
	snake.yCoord = snakeCoords[1];
}

void Draw::drawBoard() {
	system("cls");
	//Draws the top wall of the board
	for (int i = 0; i < width; i++) {
		std::cout << '#';
	}
	std::cout << std::endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			//Draws the close edge of the board
			if (j == 0) {
				std::cout << '#';
			}
			//Creates gaps in between the edges to fill out the board
			else {
				std::cout << " ";
			}
			//Draws the far edge of the board
			if (j == width - 1) {
				std::cout << "#";
			}
		}
		//Moves down to draw the next line
		std::cout << std::endl;
	}
	//Draws the bottom wall of the board
	for (int i = 0; i < width; i++) {
		std::cout << '#';
	}
	std::cout << std::endl;
}

void Draw::drawCall(int xCoord, int yCoord) {
	//insert code to draw snake to screen based on coords
	//call logic and take values from the calculations performed there
}