/*
 * TellerEvent.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "TellerEvent.h"

TellerEvent::TellerEvent(int time):Event(time) {
	isTellerEvent=true;
}
Event *TellerEvent::action(TellerQueue *tQueue) {
	//If there are customers to process
	if(tQueue->readyToProcess()) {

		tQueue->processCustomer();
		std::cout<<"Processing TellerEvent for teller "<<tQueue->tellerNum<<"!\n"<<std::endl;

	}
	return nullptr;
}
TellerEvent::~TellerEvent() {
	// TODO Auto-generated destructor stub
}

