/*
 * Teller.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "Teller.h"
#include <stdlib.h>
Teller::Teller() {
	setIdleTime();
}
void Teller::setIdleTime() {
	idleTime=rand() % 150+1;
}
Teller::~Teller() {
	// TODO Auto-generated destructor stub
}


