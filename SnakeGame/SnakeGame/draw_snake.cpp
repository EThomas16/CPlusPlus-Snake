#include "draw_snake.h"
#include "logic.h"
#include <iostream>
#include <vector>
#include <string>

int Draw::drawBoard(int snakeX, int snakeY, int foodX, int foodY, int tailX[100], int tailY[100], int tailLength) {
	Draw::food _food;
	int gameOver = 0;
	system("cls");
	//draws the top wall of the board
	for (int i = 0; i < width; i++) {
		std::cout << '#';
	}
	std::cout << std::endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			//draws the close edge of the board
			if (j == 0) {
				std::cout << '#';
			}
			//for when the snake hits a wall, the game over state is set to true
			if (snakeX == (width - 1) || snakeX == 0 || snakeY == height || snakeY == 0) {
				gameOver = 1;
			}
			//handles the drawing of the snake and food to the board
			else if (j == foodX && i == foodY) {
				std::cout << _food.shape;
			}
			else if (j == snakeX && i == snakeY) {
				std::cout << _snake.headShape;
			}
			//draws tail and creates gaps in between the edges to fill out the board
			else {
				gameOver = drawTail(snakeX, snakeY, i, j, tailX, tailY, tailLength);
			}
			
			//draws the far edge of the board
			if (j == width - 1) {
				std::cout << '#';
			}
		}
		//moves down to draw the next line
		std::cout << std::endl;
	}
	//draws the bottom wall of the board
	for (int i = 0; i < width; i++) {
		std::cout << '#';
	}
	std::cout << std::endl;
	debugPrint(snakeX, snakeY, tailX, tailY, tailLength);
	//returns the current game over state to tell the game when to end
	return gameOver;
}

int Draw::drawTail(int snakeX, int snakeY, int i, int j, int tailX[100], int tailY[100], int tailLength) {
	//uandles the drawing of the tail
	int gameOver = 0;
	//used to make sure the board draws properly
	bool tailPresent = false;
	if (tailLength > 0) {
		for (int k = 0; k < tailLength; k++) {
			//if the snake collides with itself, the gameOver state is set to true
			if (tailX[k] == snakeX && tailY[k] == snakeY) {
				gameOver = 1;
			}
			//otherwise, the snake's tail is drawn
			else if (tailX[k] == j && tailY[k] == i) {
				std::cout << _snake.bodyShape;
				tailPresent = true;
			}
		}
	}
	//draws the empty spaces that are left and not occupied by the snake or its tail
	if (!tailPresent) {
		std::cout << " ";
	}
	return gameOver;
}

void Draw::debugPrint(int snakeX, int snakeY, int tailX[100], int tailY[100], int tailLength) {
	//for debugging purposes, prints current position values to the console
	//casts ints to string to print to console
	std::string currentX = std::to_string(snakeX);
	std::string currentY = std::to_string(snakeY);
	std::string currentTailX = std::to_string(tailX[0]);
	std::string currentTailY = std::to_string(tailY[0]);
	std::string currentScore = std::to_string((tailLength * 10));
	std::cout << "Snake X: " << currentX << "Snake Y: " << currentY << std::endl;
	std::cout << "Current snake shape: " << _snake.bodyShape << std::endl;
	std::cout << "Score: " << currentScore << std::endl;
	std::cout << "Tail X: " << currentTailX << "Tail Y: " << currentTailX << std::endl;
}
