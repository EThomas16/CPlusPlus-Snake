/*This header file is used for initialising the drawing methods in the draw_snake.cpp file*/

#include <iostream>
#include <vector>

class Draw {
public:
	int drawBoard(int snakeX, int snakeY, int foodX, int foodY, std::vector<int> tailX, std::vector<int> tailY, int tailLength);

	const int height = 20;
	const int width = 40;

	struct food {
		int xCoord;
		int yCoord;
		char shape = 'o';
	};
	struct snake {
		int xCoord;
		int yCoord;
		char shape = 'x';
	};

	Draw::snake _snake;
};