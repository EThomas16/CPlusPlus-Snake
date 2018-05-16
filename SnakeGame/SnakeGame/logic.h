/*This header file is for use with logic.cpp to provide the methods for calculating the position
and direction of the snake*/

#include <iostream>
#include <vector>

class Logic {
public:
	std::vector<int> initPosition();
	std::vector<int> updatePosition(int snakeX, int snakeY, int direction);
	void foodCheck(int snakeX, int snakeY, int foodX, int foodY);
	void updateTail();
	std::vector<int> getRandomCoords();
	void seedRandom();
	int inputHandler();

	const int height = 20;
	const int width = 40;
	//defined as -1 to prevent movement before a key has been pressed
	int direction = -1;
	int tailLength = 0;
	int snakeX, snakeY;
	int foodX, foodY;

	struct snakeTail {
		std::vector<int> tailX;
		std::vector<int> tailY;
	};

	Logic::snakeTail _snakeTail;
};