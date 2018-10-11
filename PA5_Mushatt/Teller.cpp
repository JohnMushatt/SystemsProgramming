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
	onBreak=false;

}
/**
 * Sets idle time of teller
 */
void Teller::setIdleTime() {
	idleTime=rand() % 1+1; //FIX THIS
}
/**
 * Returns idle time of teller
 * @return Time to idle
 */
int Teller::getIdleTime(){
	return idleTime;
}
/**
 * Check if the teller has any customers in some queue before changing idle status
 * @param *line Pointer to tellerqueue
 */
void Teller::updateBreakStatus(TellerQueue *line) {
	if(line->getNextCustomer()!=nullptr) {
		onBreak=false;
	}
	else {
		onBreak = true;
	}

}
Teller::~Teller() {
	// TODO Auto-generated destructor stub
}


