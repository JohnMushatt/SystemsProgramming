/*
 * TellerEvent.h
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#ifndef TELLEREVENT_H_
#define TELLEREVENT_H_

#include "Event.h"
#include "TellerQueue.h"
class CustomerEvent;
class TellerEvent: public Event {
public:
	TellerEvent(float tellerServiceTime, float idleTime, TellerQueue *queue);
	virtual ~TellerEvent();

	void action(float currentTime, TellerQueue** queues, int numTellers, EventQueue *simulationQueue);
	CustomerEvent *checkOtherQueues(TellerQueue** queues, int numTellers);
	TellerQueue *queue;
	void editTime(float time);
	float getTime();
	int getTotalServices();
	int getTotalIdles();
	float getIdleTime();
	float getServiceTime();
private:
	float tellerServiceTime, idleTime,totalServices,totalIdles,time;

};

#endif /* TELLEREVENT_H_ */
