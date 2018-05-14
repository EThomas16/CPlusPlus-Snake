/*This header file is used for initialising the drawing methods in the draw_snake.cpp file*/

#include <iostream>

class Draw {
public:
	void drawInit();
	void drawBoard();
	void drawCall(int xCoord, int yCoord);

	const int height = 20;
	const int width = 40;

	struct food {
		int xCoord;
		int yCoord;
		char shape;
	};
	struct snake {
		int xCoord;
		int yCoord;
		char bodyShape;
		char headShape;
	};
};