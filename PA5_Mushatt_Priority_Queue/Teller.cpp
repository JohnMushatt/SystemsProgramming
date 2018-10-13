/*
 * Teller.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "Teller.h"
#include <stdlib.h>
Teller::Teller(int num) {
	tellerNum = num;
	setIdleTime();
	onBreak=false;
	processing=false;

}
/**
 * Sets idle time of teller
 */
void Teller::setIdleTime() {
	idleTime=rand() % 1+1; //FIX THIS
}
/**
 * Returns idle time of teller
 * @return Time to idlek
 */
int Teller::getIdleTime(){
	return idleTime;
}
/**
 * Check if the teller has any customers in some queue before changing idle status
 * @param *line Pointer to tellerqueue
 */
void Teller::updateBreakStatus(TellerQueue *line) {
	if(line->getHead()!=nullptr) {
		onBreak=false;
	}
	else {
	}

}
Teller::~Teller() {
	// TODO Auto-generated destructor stub
}


