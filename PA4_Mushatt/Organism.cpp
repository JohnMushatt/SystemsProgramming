/*
 * Organism.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#include "Organism.h"

Organism::Organism() {

	xLocation = 0;
	yLocation = 0;
	turnsAlive = 0;
}
Organism::Organism(int x, int y) {

	xLocation = x;
	yLocation = y;
	turnsAlive = 0;
}
void Organism::move(int x, int y) {

	xLocation = x;
	yLocation = y;
}
Organism::~Organism() {
}

