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
	~Doodlebug();
	void eat();
	void move(int move, Board *gameBoard);
	bool isPrey();
	bool isStarving();
	bool readyToBreed();
private:
	int turnsWithoutEating;

};

#endif /* DOODLEBUG_H_ */
