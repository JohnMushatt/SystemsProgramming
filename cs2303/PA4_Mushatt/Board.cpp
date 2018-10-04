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
Board::Board() {
	rows = 20;
	cols =20;
	numDoodlebugs = 5;
	numAnts = 100;
	totalTurns = 1000;
	seed  =  1;
	initializeBoard();
	printBoard();
	buildBoard();
	std::cout <<"\n\n";
	printBoard();
}

Board::Board(int numRows, int numCols, int bugs, int ants, int turns, int randSeed) {

	rows = numRows;
	cols = numCols;
	numDoodlebugs = bugs;
	numAnts = ants;
	totalTurns = turns;
	seed = randSeed;
	initializeBoard();
	printBoard();

}
void Board::printBoard() {
	for(int i = 0; i < rows; i++) {
		std::cout <<"Vector[" <<i << "]: ";
		for(int j = 0; j < cols; j++){
			if(gameBoard.at(i).at(j)!=nullptr) {
				if(gameBoard.at(i).at(j)->isPrey()) {
					std::cout <<"o ";
				}
				else if(!(gameBoard.at(i).at(j)->isPrey())) {

					std::cout<<"x ";
				}
			}
		}
		std::cout<<"\n";
	}
}

/**
 * Build board with random seed
 */
void Board::buildBoard() {
	time_t t;

	unsigned int seed = time(&t);
	srand(seed);


	int cAnts = 0, cDoodlebugs = 0;
	while((cAnts < numAnts) and (cDoodlebugs < numDoodlebugs)) {
		for(int i = 0; i < rows; i++) {

			for(int j =0; j < cols; j++) {
				int elementType = rand()%4;
				if(elementType==ANT) {
					gameBoard.at(i).at(j)= new Ant;
				}
				else if(elementType==DOODLEBUG) {

					gameBoard.at(i).at(j) = new Doodlebug;
				}
			}
		}
	}
}
/**
 * Initialize board with nullptr's
 */
void Board::initializeBoard() {


	for(int i = 0; i < rows; i++) {

		std::vector<Organism *> row;

		for(int j = 0; j < cols; j++) {

			row.push_back(nullptr);
		}

		std::cout <<"Row vector size: " << row.size() << std::endl;
		gameBoard.push_back(row);
		std::cout <<"gameBoard size: " << gameBoard.size() << std::endl;

	}
}
/**
 * Check if the move is valid
 * @param row Row of next move
 * @param col Col of next move
 * @return True/false if the move is possible
 */
bool Board::isValidMove(int row, int col) {
	if((row > rows) or (col > cols) or (col < 0) or (row < 0)) {
		return false;
	}
	if(gameBoard[row][col]==nullptr) {
		return true;
	}
	return false;

}
Board::~Board() {
	// TODO Auto-generated destructor stub
}

