/*
 * Board.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#include "Board.h"
#include <vector>
#include <iostream>
#include <time.h>
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
#define ANT 1
#define DOODLEBUG 2
#define NULL_OBJECT 0

/**
 * Default constructor
 */
Board::Board() {
	rows = 20;
	cols = 20;
	numDoodlebugs = 5;
	numAnts = 100;
	totalTurns = 10;
	seed = 1;
	srand(seed);
	currentTurn = 0;
	pauseGame = 0;
	initializeBoard();
	buildBoard();
	printBoard();
	for (; currentTurn != totalTurns;) {
		computeTurn();

	}
	std::cout << "Current Turn: " << currentTurn << std::endl;

	std::cout<<"Total ants: " <<numAnts <<" Total bugs: " <<numDoodlebugs <<std::endl;

	printBoard();
}

/**
 * Constructor with multiple parameters
 */
Board::Board(int numRows, int numCols, int bugs, int ants, int turns,
		int randSeed, int pause) {

	rows = numRows;
	cols = numCols;
	numDoodlebugs = bugs;
	numAnts = ants;
	totalTurns = turns;
	seed = randSeed;
	srand(seed);
	initializeBoard();
	buildBoard();
	for (; currentTurn != totalTurns;) {
		std::cout << "Current Turn: " << currentTurn<< std::endl;
		computeTurn();
		if(currentTurn<pause) {
			printBoard();
		}
		else if ((currentTurn == pause)) {
			char input;
			std::cout << "Press 'y' to continue: ";
			std::cin >> input;
		}
	}
	printBoard();

}

/**
 * Prints board
 */
void Board::printBoard() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (gameBoard.at(i).at(j) != nullptr) {
				if (gameBoard.at(i).at(j)->isPrey()) {
					//If ant print o
					std::cout << "o ";
					//If predator choose x
				} else if (gameBoard.at(i).at(j)->isPrey() == false) {

					std::cout << "x ";
				}
				//If empty print blank
			} else {
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}
/**
 * Compute 1 whole board turn
 */
void Board::computeTurn() {
	computeDoodlebugTurn();
	computeAntTurn();
	resetOrganismHasMoved();
	currentTurn++;
	updateBoard();
	std::cout << "\nBugs left: " << numDoodlebugs << " Ants left: " << numAnts
			<< std::endl;

}
/**
 * Update the number of bugs and ants on the board
 */
void Board::updateBoard() {
	//counters to hold number of pieces
	int antsLeft = 0, doodlebugsLeft = 0;

	//Loop through row
	for (int i = 0; i < rows; i++) {
		//Loop through col
		for (int j = 0; j < cols; j++) {

			//Check if not nullptr
			if ((gameBoard.at(i).at(j) != nullptr)) {

				//Check if preyy
				if (gameBoard.at(i).at(j)->isPrey()) {
					antsLeft++;
					gameBoard.at(i).at(j)->turnsAlive++;
					//Check if not predator
				} else if (gameBoard.at(i).at(j)->isPrey() == false) {
					doodlebugsLeft++;
					gameBoard.at(i).at(j)->turnsAlive++;

				}
			}
		}
	}
	//Update vars
	numAnts = antsLeft;
	numDoodlebugs = doodlebugsLeft;
}
void Board::computeAntTurn() {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			Organism* p = gameBoard.at(i).at(j);

			if ((p != nullptr) && (p->isPrey()) && !(p->hasMoved)) {

				while ((p != nullptr) and !(p->hasMoved)) {

					std::array<int, 4> moves = { 0, 1, 2, 3 };
					std::vector<int> validMoves;
					for (size_t currentMove = 0; currentMove < moves.size();
							currentMove++) {

						int tempMove = moves.at(currentMove);
						if (isValidMove(tempMove, p)) {
							validMoves.push_back(tempMove);
						}
					}
					if (validMoves.size() != 0) {
						int index = rand() % validMoves.size();
						int move = validMoves[index];
						if (isValidMove(move, p)) {

							p->move(move, this);

						}
					} else {
						p->hasMoved = true;
					}

				}
				breedAnt(p);
			}
		}
	}
}
/**
 * Compute a doodlebugs turn, checking to move, breed, eat, and starve
 */
void Board::computeDoodlebugTurn() {
	//Loop through rows
	for (int i = 0; i < rows; i++) {
		//Loop through cols
		for (int j = 0; j < cols; j++) {

			//If current element is not a nullptr, not an ant, and has not already moved
			if ((gameBoard.at(i).at(j) != nullptr)
					and (gameBoard.at(i).at(j)->isPrey() == false)
					and (gameBoard.at(i).at(j)->hasMoved == false)) {

				//Create a prt for the current gameBoard piece
				Organism *p = gameBoard.at(i).at(j);

				//If we are not a nullptr and both not a prey and not already moved //ERROR ON !p->isPrey()
				//if ((p != nullptr) && ((!(p->isPrey())) && !(p->hasMoved))) {

					//While we are not a nullptr and have not moved
					while ((p != nullptr) and !(p->hasMoved)) {

						//Create 4 moves
						std::array<int, 4> moves = { 0, 1, 2, 3 };
						//Valid move
						std::vector<int> validMoves;

						//Iterate through and add on valid moves
						for (size_t currentMove = 0; currentMove < moves.size();
								currentMove++) {

							int tempMove = moves.at(currentMove);
							if (isValidMove(tempMove, p)) {
								validMoves.push_back(tempMove);
							}
						}

						if (validMoves.size() != 0) {
							int index = rand() % validMoves.size();
							int move = validMoves[index];
							if (isValidMove(move, p)) {

								p->move(move, this);

							}
						} else {
							p->hasMoved = true;
						}

					}
			//	}
				if ((p != nullptr) && (!(p->isPrey()))) {
					Organism *d = gameBoard.at(i).at(j);
					if((d!=nullptr) and (d->isStarving())) {
						delete gameBoard.at(i).at(j);
						gameBoard.at(i).at(j)=nullptr;
					}
					else if(p!=nullptr){
						breedBug(d);
					}
				}
			}
		}
	}
}
/**
 * Checks if the current move for the given organism is valid
 * @param move Move to check
 * @param organism Organism to check if move is valid for
 * @return True if move is valid for organism
 */
bool Board::isValidMove(int move, Organism *organism) {
	if ((move == UP) and (organism->row > 0)) {
		Organism *up = gameBoard.at(organism->row - 1).at(organism->col);

		if ((organism->isPrey()) and (up == nullptr)) {
			return true;
		} else if ((organism->isPrey() == false)
				and ((up == nullptr) or (up->isPrey()))) {
			return true;
		}
	} else if ((move == RIGHT) and (organism->col < cols - 1)) {

		Organism *right = gameBoard.at(organism->row).at(organism->col + 1);
		if ((organism->isPrey()) and (right == nullptr)) {
			return true;
		} else if ((organism->isPrey() == false)
				and ((right == nullptr) or (right->isPrey()))) {
			return true;
		}
	} else if ((move == DOWN) and (organism->row < rows - 1)) {
		Organism *down = gameBoard.at(organism->row + 1).at(organism->col);
		if ((organism->isPrey()) and (down == nullptr)) {
			return true;
		} else if ((organism->isPrey() == false)
				and ((down == nullptr) or (down->isPrey()))) {
			return true;
		}
	} else if ((move == LEFT) and (organism->col > 0)) {
		Organism *left = gameBoard.at(organism->row).at(organism->col - 1);
		if ((organism->isPrey()) and (left == nullptr)) {
			return true;
		} else if ((organism->isPrey() == false)
				and ((left == nullptr) or (left->isPrey()))) {
			return true;
		}
	}
	return false;
}
int Board::randomMove() {
	return rand() % 4;
}
/**
 * If bug is ready to breed, check all spaces near and see if it can place a doodlebug
 */
void Board::breedBug(Organism *d) {

	if ((d!=nullptr) and(d->readyToBreed())) {

		std::array<int, 4> moves = { 0, 1, 2, 3 };
		std::vector<int> validMoves;
		for (size_t currentMove = 0; currentMove < moves.size();
				currentMove++) {

			int tempMove = moves.at(currentMove);
			if (isValidMove(tempMove, d)) {
				validMoves.push_back(tempMove);
			}
		}
		if (validMoves.size() != 0) {
			int index = rand() % validMoves.size();
			int move = validMoves[index];
			if (isValidMove(move, d)) {

				if(move==UP) {
					gameBoard.at(d->row-1).at(d->col) = new Doodlebug(d->row-1,d->col);
				}
				else if(move==RIGHT) {
					gameBoard.at(d->row).at(d->col+1) = new Doodlebug(d->row,d->col+1);

				}
				else if(move ==DOWN) {
					gameBoard.at(d->row+1).at(d->col) = new Doodlebug(d->row+1,d->col);

				}
				else if(move==LEFT) {
					gameBoard.at(d->row).at(d->col-1) = new Doodlebug(d->row,d->col-1);

				}

			}
		}

	}

}
/**
 * Checks and breeds if possible for doodlebug
 */
void Board::breedAnt(Organism *a) {
	if ((a!=nullptr) and(a->readyToBreed())) {

			std::array<int, 4> moves = { 0, 1, 2, 3 };
			std::vector<int> validMoves;
			for (size_t currentMove = 0; currentMove < moves.size();
					currentMove++) {

				int tempMove = moves.at(currentMove);
				if (isValidMove(tempMove, a)) {
					validMoves.push_back(tempMove);
				}
			}
			if (validMoves.size() != 0) {
				int index = rand() % validMoves.size();
				int move = validMoves[index];
				if (isValidMove(move, a)) {

					if(move==UP) {
						gameBoard.at(a->row-1).at(a->col) = new Doodlebug(a->row-1,a->col);
					}
					else if(move==RIGHT) {
						gameBoard.at(a->row).at(a->col+1) = new Doodlebug(a->row,a->col+1);

					}
					else if(move ==DOWN) {
						gameBoard.at(a->row+1).at(a->col) = new Doodlebug(a->row+1,a->col);

					}
					else if(move==LEFT) {
						gameBoard.at(a->row).at(a->col-1) = new Doodlebug(a->row,a->col-1);

					}

				}
			}

		}

}
/**
 * Build board with random seed
 */
void Board::buildBoard() {
	int cAnts = 0, cDoodlebugs = 0;
	while ((cAnts < numAnts) or (cDoodlebugs < numDoodlebugs)) {

		for (int i = 0; i < rows; i++) {

			for (int j = 0; j < cols; j++) {
				int elementType = rand() % 4;

				if ((gameBoard.at(i).at(j) == nullptr) and (elementType == ANT)
						and (cAnts < numAnts)) {

					gameBoard.at(i).at(j) = new Ant(i, j);
					cAnts++;
				} else if ((gameBoard.at(i).at(j) == nullptr)
						and (elementType == DOODLEBUG)
						and (cDoodlebugs < numDoodlebugs)) {

					gameBoard.at(i).at(j) = new Doodlebug(i, j);
					cDoodlebugs++;
				}
			}
		}
	}
	std::cout << "Total ants: " << numAnts << std::endl;
	std::cout << "Total bugs: " << numDoodlebugs << std::endl;
}
/**
 * Initialize board with nullptr's
 */
void Board::initializeBoard() {

	for (int i = 0; i < rows; i++) {

		std::vector<Organism *> row;

		for (int j = 0; j < cols; j++) {

			row.push_back(nullptr);

		}
		//std::cout << "Row vector size: " << row.size() << std::endl;
		gameBoard.push_back(row);
		//std::cout << "gameBoard size: " << gameBoard.size() << std::endl;

	}
}

void Board::resetOrganismHasMoved() {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			if (gameBoard.at(i).at(j) != nullptr) {
				gameBoard.at(i).at(j)->resetHasMoved();
			}
		}
	}
}
int Board::getRows() {
	return rows;
}
int Board::getCols() {
	return cols;
}
Board::~Board() {
	// TODO Auto-generated destructor stub
}

