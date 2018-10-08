/*
 * CustomerEvent.h
 *
 *  Created on: Oct 7, 2018
 *      Author: jemushatt
 */

#ifndef CUSTOMEREVENT_H_
#define CUSTOMEREVENT_H_

#include "Event.h"

class CustomerEvent: public Event {
public:
	CustomerEvent();
	virtual ~CustomerEvent();
};

#endif /* CUSTOMEREVENT_H_ */
