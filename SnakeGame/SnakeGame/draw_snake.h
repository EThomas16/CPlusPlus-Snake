/*This header file is used for initialising the drawing methods in the draw_snake.cpp file*/

#include <iostream>

class Draw {
public:
	void drawInit();
	void drawCall();
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