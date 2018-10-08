/*
 * Organism.h
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
#include "Board.h"
#include <time.h>
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
class Board;
class Organism {
private:
	bool canBreed;


public:
	//Defualt constructor
	Organism();

	Organism(int x, int y);
	//Deconstructor
	virtual ~Organism();

	void resetHasMoved();

	virtual void move(int move, Board *gameBoard) = 0;


	virtual bool isPrey() = 0;

	virtual bool readyToBreed()=0;

	bool hasMoved;
	int turnsAlive;
	int randomMove();
	virtual bool isStarving()=0;
	int row, col;
};

#endif /* ORGANISM_H_ */
