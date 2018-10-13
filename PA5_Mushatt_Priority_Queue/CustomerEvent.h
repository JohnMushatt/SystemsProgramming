/*
 * CustomerEvent.h
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#ifndef CUSTOMEREVENT_H_
#define CUSTOMEREVENT_H_

#include "Event.h"
#include <cstdlib>
class CustomerEvent: public Event{

public:
	CustomerEvent(float startTime);
	virtual ~CustomerEvent();
	void action(float currentTime, TellerQueue** queues,int numTellers,EventQueue *simulationQueue);
	float getTime();
	void setService();
	void setTime(float t);
	bool getServicing();
	int getEndTime();
	int getStartTime();
	TellerQueue *findShortestLine(TellerQueue** q, int numTellers);
private:
	float startTime,time,endTime;
	bool receivingService;
};

#endif /* CUSTOMEREVENT_H_ */
