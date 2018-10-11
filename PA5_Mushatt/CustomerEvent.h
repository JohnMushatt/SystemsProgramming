/*
 * CustomerEvent.h
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#ifndef CUSTOMEREVENT_H_
#define CUSTOMEREVENT_H_

#include "Event.h"
#include "Customer.h"
class CustomerEvent: public Event {
public:
	CustomerEvent(int time);
	void action(TellerQueue *tQueue);
	virtual ~CustomerEvent();
private:
};

#endif /* CUSTOMEREVENT_H_ */
