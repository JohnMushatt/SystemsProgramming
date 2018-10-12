/*
 * CustomerEvent.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "CustomerEvent.h"

CustomerEvent::CustomerEvent(int time):Event(time) {
	isTellerEvent=false;

}
Event *CustomerEvent::action(TellerQueue *tQueue) {

	tQueue->addCustomer(new Customer(time));
	TellerEvent *event = new TellerEvent(time + tQueue->teller->getIdleTime());
	return event;
}
CustomerEvent::~CustomerEvent() {
	// TODO Auto-generated destructor stub
}

