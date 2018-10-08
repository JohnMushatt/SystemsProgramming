/*
 * Teller.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "Teller.h"
#include <stdlib.h>
Teller::Teller() {
	idleTime = rand() % idleTimeConst +1;
}

Teller::~Teller() {
	// TODO Auto-generated destructor stub
}


