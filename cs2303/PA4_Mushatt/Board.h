/*
 * Board.h
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Organism.h"
#include <vector>
#include <array>
class Organism;
class Board {
public:

	Board();
	Board(int numRows, int numCols, int bugs, int ants, int turns, int randSeed);
	virtual ~Board();

	int getRow();

	int getCol();

	int getTotalTurns();

	void buildBoard();

	void printBoard();

	void initializeBoard();

	bool isValidMove(int row, int col);

	std::vector< std::vector<Organism *> > gameBoard;


private:
	int rows, cols, totalTurns,numDoodlebugs,numAnts,seed;

};

#endif /* BOARD_H_ */
