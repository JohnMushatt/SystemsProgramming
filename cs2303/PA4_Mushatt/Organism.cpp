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

}

bool Organism::readyToBreed() {
	return canBreed;
}
Organism::~Organism() {

}

class Organism;

