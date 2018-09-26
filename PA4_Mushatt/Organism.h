/*
 * Organism.h
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Organism {

	int turnsAlive, xLocation, yLocation;


public:
	Organism();
	Organism(int x, int y);
	virtual ~Organism();

	void move();
	void breed();
};

#endif /* ORGANISM_H_ */
