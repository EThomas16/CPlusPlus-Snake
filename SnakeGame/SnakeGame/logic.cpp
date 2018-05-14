#include "logic.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

void Logic::initPosition() {

}

void Logic::seedRandom() {
	srand(time(NULL));
}

std::vector<int> Logic::getRandom() {
	//Creates a vector to store the new food coordinates, then acquires a random value to store
	std::vector<int> foodCoords;
	int foodX = std::rand();
	int foodY = std::rand();
	//Random coordinates are then added to the vector
	foodCoords.push_back(foodX);
	foodCoords.push_back(foodY);

	return foodCoords;
}