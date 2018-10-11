/*
 * TellerEvent.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "TellerEvent.h"

TellerEvent::TellerEvent(int time):Event(time) {
	// TODO Auto-generated constructor stub

}
void TellerEvent::action(TellerQueue *tQueue) {
	//If there are customers to process
	if(tQueue->getNextCustomer()!=nullptr) {
		tQueue->processCustomer();
	}
	// If there are no more customers, go on break
	else {
		tQueue->teller->updateBreakStatus(tQueue);
	}

}
TellerEvent::~TellerEvent() {
	// TODO Auto-generated destructor stub
}

