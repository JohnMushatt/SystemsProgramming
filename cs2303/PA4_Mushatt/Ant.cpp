/*
 * Ant.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#include "Ant.h"
#define BREED_TIMER 3
Ant::Ant() {
}

Ant::Ant(int x, int y):Organism(x,y ) {
}
/**
 * Moves the ant in a random direction
 * @param gameBoard Board passed in as a parameter
 */
void Ant::move(int move, Board *gameBoard) {

	//While we have not made a move
	while (!hasMoved) {

		//Generate a random move

		//Check if the randomly generate move is valid

			//If the move is valid and is up, move in the corresponding fashion
			if (move == UP) {
				Organism *up = gameBoard->gameBoard.at(row-1).at(col);
				if((up==nullptr)) {
					//PROBABLY NEED TO COPY OBJECT OVER DIFFERENTLY
					gameBoard->gameBoard.at(row - 1).at(col) = new Ant(row-1,col);
					gameBoard->gameBoard.at(row).at(col) = nullptr;
				}
			//If the move is valid and is right, move in the corresponding fashion
			} else if (move == RIGHT) {
				Organism *right = gameBoard->gameBoard.at(row).at(col+1);
				if(right==nullptr) {
					//PROBABLY NEED TO COPY OBJECT OVER DIFFERENTLY
					gameBoard->gameBoard.at(row).at(col+1) = new Ant(row,col+1);
					gameBoard->gameBoard.at(row).at(col) = nullptr;
				}
			//If the move is valid and is down, move in the corresponding fashion
			} else if (move == DOWN) {
				Organism *down = gameBoard->gameBoard.at(row+1).at(col);
				if(down==nullptr) {
					//PROBABLY NEED TO COPY OBJECT OVER DIFFERENTLY
					gameBoard->gameBoard.at(row +1).at(col) = new Ant(row+1,col);
					gameBoard->gameBoard.at(row).at(col) = nullptr;
				}
			}

			//If the move is valid and is left, move in the corresponding fashion
			else if (move == LEFT) {
				Organism *left = gameBoard->gameBoard.at(row).at(col-1);
				if(left==nullptr) {
					//PROBABLY NEED TO COPY OBJECT OVER DIFFERENTLY
					gameBoard->gameBoard.at(row).at(col-1) = new Ant(row,col-1);
					gameBoard->gameBoard.at(row).at(col) = nullptr;
				}
			}
			hasMoved = true;
		}

}
bool Ant::isPrey() {
	return true;
}
bool Ant::isStarving() {
	return false;
}
bool Ant::readyToBreed() {
	return turnsAlive >=3;
}
Ant::~Ant() {
}

