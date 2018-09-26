/*
 * Ant.h
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"

class Ant: public Organism {
public:
	Ant();
	Ant(int x, int y);
	virtual ~Ant();
};

#endif /* ANT_H_ */
