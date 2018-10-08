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
	Board(int numRows, int numCols, int bugs, int ants, int turns, int randSeed, int pause);
	virtual ~Board();

	int getRows();

	int getCols();

	int getTotalTurns();




	std::vector< std::vector<Organism *> > gameBoard;


private:
	int rows, cols, totalTurns,numDoodlebugs,numAnts,seed,currentTurn,totalBugs,totalAnts;
	void buildBoard();
	bool pauseGame;
	void printBoard();

	void computeAntTurn();
	void computeDoodlebugTurn();
	void computeTurn();
	void initializeBoard();
	void resetOrganismHasMoved();
	int randomMove();
	void seedRandom();
	void updateBoard();
	bool isValidMove(int move, Organism *organism);
	void breedBug(Organism *d);
	void breedAnt(Organism *a);
};

#endif /* BOARD_H_ */
