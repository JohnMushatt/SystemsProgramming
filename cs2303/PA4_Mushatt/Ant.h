/*
 * Ant.h
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"
#include "Board.h"
class Ant: public Organism {
public:
	Ant();
	Ant(int x, int y);
	~Ant();
	void move(int move, Board *gameBoard);
	bool isPrey();
	bool readyToBreed();
	bool isStarving();
};
#endif /* ANT_H_ */
