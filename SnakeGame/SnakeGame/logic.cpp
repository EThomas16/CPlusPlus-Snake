#include "logic.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
//TODO: return values from logic to pass into draw in main.cpp
void Logic::initPosition() {
	//TODO: check if required if being drawn already (might be for calculation purposes)
}

void Logic::seedRandom() {
	srand(time(NULL));
}

std::vector<int> Logic::getRandomCoords() {
	//Creates a vector to store the new food coordinates, then acquires a random value to store
	std::vector<int> coords;
	int xCoord = std::rand();
	int yCoord = std::rand();
	//Random coordinates are then added to the vector
	coords.push_back(xCoord);
	coords.push_back(yCoord);

	return coords;
}