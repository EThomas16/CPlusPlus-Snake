#include "draw_snake.h"
#include "logic.h"
#include <iostream>
#include <vector>
#include <string>
/*TODO: drawing of snake icon slightly off, needs fixing*/
int Draw::drawBoard(int snakeX, int snakeY, int foodX, int foodY, std::vector<int> tailX, std::vector<int> tailY, int tailLength) {
	Draw::food _food;
	int gameOver = 0;
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
			else if (j < width - 1) {
				std::cout << " ";
			}
			//Draws the far edge of the board
			if (j == width - 1) {
				std::cout << "#";
			}
			//For when the snake hits a wall, the game over state is set to true
			if (snakeX == (width-2) || snakeX == 0 || snakeY == height || snakeY == 0) {
				gameOver = 1;
			}
			//Handles the drawing of the snake and food to the board
			else if (j == snakeX && i == snakeY) {
				std::cout << _snake.shape;
			}
			else {
				for (int k = 0; k < tailLength; k++)
					if (tailX[k] == j && tailY[k] == i) {
						std::cout << _snake.shape;
					}
			}
			if (j == foodX && i == foodY) {
				std::cout << _food.shape;
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
	//for debugging purposes
	std::string currentX = std::to_string(snakeX);
	std::string currentY = std::to_string(snakeY);
	std::string currentScore = std::to_string((tailLength*10));
	std::cout << "Snake X: " << currentX << "Snake Y: " << currentY << std::endl;
	std::cout << "Current snake shape: " << _snake.shape << std::endl;
	std::cout << "Score: " << currentScore;
	//returns the current game over state to tell the game when to end
	return gameOver;
}
