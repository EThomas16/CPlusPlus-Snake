/*This header file is for use with logic.cpp to provide the methods for calculating the position
and direction of the snake*/

#include <iostream>
#include <vector>

class Logic {
public:
	void initPosition();
	void newPosition();
	void seedRandom();

	std::vector<int> getRandomCoords();
	int boardHeight, boardWidth;
};