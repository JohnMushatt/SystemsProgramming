/*
 * Doodlebug.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#include "Doodlebug.h"
#include "Board.h"

Doodlebug::Doodlebug() {

	isStarving = false;
	turnsWithoutEating = 0;

}
Doodlebug::Doodlebug(int x, int y) {

	isStarving = false;
	turnsWithoutEating = 0;
}

/**
 * Check if the doodlebug can eat
 * @param gameBoard Board to check
 * @return True if there is an ant above, below, to the right, or to the left
 */
bool Doodlebug::canEat(Board *gameBoard) {

	//if(gameBoard[xLocation][yLocation]==)
	return false;
}
void Doodlebug::move(Board *gameBoard) {

}
bool Doodlebug::eat(Board *gameBoard) {

}

bool Doodlebug::isPrey() {
	return false;
}
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

