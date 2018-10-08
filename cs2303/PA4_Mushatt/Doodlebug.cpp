/*
 * Doodlebug.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#include "Doodlebug.h"
#include "Board.h"
#include <iostream>
Doodlebug::Doodlebug() {

	turnsWithoutEating = 0;
	hasMoved = false;

}
Doodlebug::Doodlebug(int x, int y) :
		Organism(x, y) {
	turnsWithoutEating = 0;
	hasMoved = false;
}
bool Doodlebug::readyToBreed() {
	if(turnsAlive >=8) {
		return true;
	}
	return false;
}
/**
 * Attempt to eat surrounding ants, and then move
 * @param gameBoard Board to check and edit
 */
void Doodlebug::move(int move, Board *gameBoard) {

	//While we have not made a move
	while (!hasMoved) {

		//Generate a random move

		//Check if the randomly generated move is valid

		//If the move is valid and is up, move in the corresponding fashion
		if (move == UP) {
			if (gameBoard->gameBoard.at(row - 1).at(col) != nullptr) {
				if (gameBoard->gameBoard.at(row - 1).at(col)->isPrey()) {

					eat();
					delete gameBoard->gameBoard.at(row - 1).at(col);
					gameBoard->gameBoard.at(row - 1).at(col) = nullptr;

					//PROBABLY NEED TO COPY OBJECT OVER DIFFERENTLY
					gameBoard->gameBoard.at(row-1).at(col) = new Doodlebug(row-1,col);
					gameBoard->gameBoard.at(row).at(col) = nullptr;
				}

			} else {
				gameBoard->gameBoard.at(row-1).at(col) = new Doodlebug(row-1,col);
				gameBoard->gameBoard.at(row).at(col) = nullptr;
			}

		}

		//If the move is valid and is right, move in the corresponding fashion
		else if (move == RIGHT) {
			if (gameBoard->gameBoard.at(row).at(col + 1) != nullptr) {
				if (gameBoard->gameBoard.at(row).at(col + 1)->isPrey()) {

					eat();
					delete gameBoard->gameBoard.at(row).at(col + 1);
					gameBoard->gameBoard.at(row).at(col + 1) = nullptr;

					//PROBABLY NEED TO COPY OBJECT OVER DIFFERENTLY
					gameBoard->gameBoard.at(row).at(col+1) = new Doodlebug(row,col+1);
					gameBoard->gameBoard.at(row).at(col) = nullptr;
				}

			} else {
				gameBoard->gameBoard.at(row).at(col+1) = new Doodlebug(row,col+1);
				gameBoard->gameBoard.at(row).at(col) = nullptr;
			}
		}

		//If the move is valid and is down, move in the corresponding fashion
		else if (move == DOWN) {

			if (gameBoard->gameBoard.at(row + 1).at(col) != nullptr) {

				if (gameBoard->gameBoard.at(row + 1).at(col)->isPrey()) {

					eat();
					delete gameBoard->gameBoard.at(row + 1).at(col);
					gameBoard->gameBoard.at(row + 1).at(col) = nullptr;

					gameBoard->gameBoard.at(row+1).at(col) = new Doodlebug(row+1,col);
					gameBoard->gameBoard.at(row).at(col) = nullptr;
				}

			} else {
				gameBoard->gameBoard.at(row+1).at(col) = new Doodlebug(row+1,col);
				gameBoard->gameBoard.at(row).at(col) = nullptr;
			}
		}

		//If the move is valid and is left, move in the corresponding fashion
		else if (move == LEFT) {

			//If we aren't a nullptr
			if (gameBoard->gameBoard.at(row).at(col - 1) != nullptr) {
				//If the adjacent cell is an ant, eat it, delete it, and replace it with a nullptr
				if (gameBoard->gameBoard.at(row).at(col - 1)->isPrey()) {
					eat();
					delete gameBoard->gameBoard.at(row).at(col-1);
					gameBoard->gameBoard.at(row).at(col - 1) = nullptr;
					//Then move the doodlebug into that cell
					gameBoard->gameBoard.at(row).at(col - 1) = new Doodlebug(row,col-1);
					gameBoard->gameBoard.at(row).at(col) = nullptr;
				}

			} else {
				gameBoard->gameBoard.at(row).at(col - 1) = new Doodlebug(row,col-1);
				gameBoard->gameBoard.at(row).at(col) = nullptr;
			}
		}
		hasMoved = true;

	}

}
/**
 * If called then set set turnswithouteating to 0 so that it doesn't starve
 */
void Doodlebug::eat() {
	turnsWithoutEating = 0;
}

/**
 * Checks whether or not the doodlebug is starving
 * @return True/false if doodlebug is starving
 */
bool Doodlebug::isStarving() {
	return turnsWithoutEating == 3;
}
bool Doodlebug::isPrey() {
	return false;
}
Doodlebug::~Doodlebug() {

}

