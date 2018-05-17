/*This header file is used for initialising the drawing methods in the draw_snake.cpp file*/

#include <iostream>
#include <vector>

class Draw {
public:
	int drawBoard(int snakeX, int snakeY, int foodX, int foodY, int tailX[100], int tailY[100], int tailLength);

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
		char headShape = 'X';
		char bodyShape = 'x';
	};

	Draw::snake _snake;

private:
	//these are private methods as they are only used internally in the class
	int drawTail(int snakeX, int snakeY, int i, int j, int tailX[100], int tailY[100], int tailLength);
	void debugPrint(int snakeX, int snakeY, int tailX[100], int tailY[100], int tailLength);
};