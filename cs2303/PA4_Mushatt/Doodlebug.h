/*
 * Doodlebug.h
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"
#include "Board.h"

class Doodlebug: public Organism {
public:
	Doodlebug();
	Doodlebug(int x, int y);
	virtual ~Doodlebug();
	bool checkStarving();
	bool canEat(Board *gameBoard);
	bool eat(Board *gameBoard);
	void move(Board *gameBoard);
	bool isPrey();
private:
	int turnsWithoutEating;
	bool isStarving;

};

#endif /* DOODLEBUG_H_ */
