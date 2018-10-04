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
	virtual ~Ant();
	void move(Board *gameBoard);
	bool isPrey();
};
#endif /* ANT_H_ */
