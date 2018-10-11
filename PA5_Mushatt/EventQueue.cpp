/*
 * EventQueue.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "EventQueue.h"
#include "Event.h"
EventQueue::EventQueue(int nTellers) {
	// TODO Auto-generated constructor stub
	head = nullptr;
	tail= nullptr;
	size = 0;
	lastQueueUsed=-1;
	for(int i = 0;i<nTellers;i++) {
		this->tellers.push_back(new TellerQueue());
	}

}

Event *EventQueue::getHead() {
	if (size > 0) {
		return head;
	}
	return nullptr;
}
int EventQueue::getQueueSize() {
	return size;
}
Event *EventQueue::getTail() {
	if (size > 0) {
		return tail;
	}
	return nullptr;
}
/**
 * Add an event to the event queue
 * @param *event Pointer to event to add
 * @return True if event added successfully , false if not added
 */
void EventQueue::addEvent(Event *event) {
	Event *current;
	if((head==nullptr) or (head->time >= event->time)) {
		event->nextEvent = head;
		head = event;
	}
	else {

		current = head;
		while((current->nextEvent!=nullptr) and (current->nextEvent->time <event->time)) {
			current = current->nextEvent;
		}
		event->nextEvent = current->nextEvent;
		current->nextEvent=event;
	}

	/*	if (event != nullptr) {
		if (size == 0) {
			head = event;
			tail = event;
			event->nextEvent=nullptr;
			size++;
			return true;
		} else {
			//Link tail to new tail
			tail->nextEvent=event;
			//set tail to new tail
			tail=event;
			//Increase size
			size++;
			return true;
		}
	}*/
}
/**
 * Remove head of queue and set next event to be the head
 * @return Pointer to recently removed event, if nullptr it means queue is empty
 */
Event *EventQueue::removeEvent(){

	//If we can remove the head
	if(size>0) {
		//Maintain head
		Event *event = head;
		//Set head to the the nextEvent
		head = head->nextEvent;
		//Decrease size
		size--;
		//Add or remove customer from a teller queue
		TellerQueue *tQueue;

		//Compare ith teller to jth teller, if i is smaller than rest use i
		for(unsigned int i = 0; i<tellers.size()-1;i++) {
			bool smallQueue = false;
			for(unsigned int j = 1; j < tellers.size();j++) {
				if(tellers.at(i)->getQueueSize()<tellers.at(j)->getQueueSize()) {
					smallQueue=true;
				}
				else {
					smallQueue=false;
				}
			}
			if(smallQueue) {
				tQueue = tellers.at(i);
				i = tellers.size();
			}
		}
		return event;
	}
	return nullptr;
}
EventQueue::~EventQueue() {
	// TODO Auto-generated destructor stub
}

