/*
 * CustomerEvent.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "CustomerEvent.h"

CustomerEvent::CustomerEvent(int time):Event(time) {

}
void CustomerEvent::action(TellerQueue *tQueue) {
	tQueue->addCustomer(new Customer(time));
}
CustomerEvent::~CustomerEvent() {
	// TODO Auto-generated destructor stub
}

