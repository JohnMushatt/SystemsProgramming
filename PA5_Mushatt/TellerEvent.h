/*
 * TellerEvent.h
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#ifndef TELLEREVENT_H_
#define TELLEREVENT_H_

#include "Event.h"

class TellerEvent: public Event {
public:
	TellerEvent(int time);
	Event *action(TellerQueue *tQueue);
	virtual ~TellerEvent();
};

#endif /* TELLEREVENT_H_ */
