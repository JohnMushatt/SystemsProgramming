/*
 * CustomerArrivalEvent.h
 *
 *  Created on: Oct 10, 2018
 *      Author: jemushatt
 */

#ifndef CUSTOMERARRIVALEVENT_H_
#define CUSTOMERARRIVALEVENT_H_

#include "Event.h"

class CustomerArrivalEvent: public Event {
public:
	CustomerArrivalEvent(int time);
	virtual ~CustomerArrivalEvent();
};

#endif /* CUSTOMERARRIVALEVENT_H_ */
