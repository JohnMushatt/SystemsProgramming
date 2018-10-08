/*
 * Organism.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#include "Organism.h"
#include "Board.h"
#include <stdlib.h>
#include <time.h>
Organism::Organism() {
	row = 0;
	col = 0;
	canBreed=false;
	hasMoved = false;
	turnsAlive=0;
}
Organism::Organism(int x, int y) {
	row = x;
	col = y;
	canBreed=false;
	hasMoved = false;
	turnsAlive=0;
}
bool Organism::readyToBreed() {
	return canBreed;
}
void Organism::resetHasMoved() {
	hasMoved=false;
}
Organism::~Organism() {
}


