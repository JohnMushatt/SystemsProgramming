/*
 * Organism.h
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
#include "Board.h"
class Board;
class Organism {

	int turnsAlive, xLocation, yLocation;
	bool canBreed;


public:
	//Defualt constructor
	Organism();

	/**
	 * Constructor with x and y coords
	 * @param x X coordinate
	 * @param y Y coordinate
	 */
	Organism(int x, int y);


	//Deconstructor
	virtual ~Organism();

	/**
	 * Move the organism 1 space in the board
	 * Same across all subclasses
	 * @param gameBoard Board to make a random move in
	 */
	virtual void move(Board *gameBoard) = 0;

	/**
	 * Return whether the current object is an ant or not
	 * @return Return true if ant, false if doodlebug
	 */
	virtual bool isPrey() = 0;
	/**
	 * Returns true/false depending if organism can breed
	 * @return True/false depending on if organism can breed at this moment
	 */
	bool readyToBreed();
};

#endif /* ORGANISM_H_ */
