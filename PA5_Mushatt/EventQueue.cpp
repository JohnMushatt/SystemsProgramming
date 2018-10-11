/*
 * EventQueue.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "EventQueue.h"
#include "Event.h"
#include <iostream>
EventQueue::EventQueue(int nTellers) {
	// TODO Auto-generated constructor stub
	head = nullptr;
	tail = nullptr;
	size = 0;
	lastQueueUsed = -1;
	for (int i = 0; i < nTellers; i++) {
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
 * Prints out the EventQueue
 */
void EventQueue::printEventQueue() {
	int i = 0;
	Event *event = head;
	std::cout << "EventQueue size: " << getQueueSize() << std::endl;
	while (i < size) {
		std::cout << "Event at position: " << i << " Event time: "
				<< event->time << std::endl;
		event = event->nextEvent;
		i++;
	}
}
/**
 * Prints the teller queues maintained by the eventqueue
 *
 */
void EventQueue::printTellerQueues() {
	for (unsigned int i = 0; i < tellers.size(); i++) {
		std::cout << "Teller #: " << i << " ";
		tellers.at(i)->printQueue();
	}
}
/**
 * Adds an event in an ordered Linked-list, while maintaining order
 * @param *event Pointer to event to add
 * @return True if event added successfully , false if not added
 */
void EventQueue::addEvent(Event *event) {
	Event *current;
	if ((head == nullptr) or (head->time >= event->time)) {
		event->nextEvent = head;
		head = event;
		size++;
	} else {

		current = head;
		while ((current->nextEvent != nullptr)
				and (current->nextEvent->time < event->time)) {
			current = current->nextEvent;
		}
		event->nextEvent = current->nextEvent;
		current->nextEvent = event;
		size++;
	}
}
/**
 * Remove head of queue and set next event to be the head
 * @return Pointer to recently removed event, if nullptr it means queue is empty
 */
Event *EventQueue::removeEvent() {

	//If we can remove the head
	if (size > 0) {
		//Maintain head
		Event *event = head;
		//Set head to the the nextEvent
		head = head->nextEvent;
		//Decrease size
		size--;
		//Add or remove customer from a teller queue
		TellerQueue *tQueue;
		int tellerIndex = 0;
		unsigned int allSame = 0;
		//If there is only 1 teller
		if (tellers.size() == 1) {
			event->action(tellers.at(0));
		} else {
			//Compare ith teller to jth teller, if i is smaller than rest use i
			for (unsigned int i = 0; i < tellers.size(); i++) {
				//If the current smallest queue and the ith queue are the same, keep allSame True
				if (tellers.at(i)->getQueueSize()
						== tellers.at(tellerIndex)->getQueueSize()) {
					allSame++;
				} else if (tellers.at(i)->getQueueSize()
						< tellers.at(tellerIndex)->getQueueSize()) {
					//New smallest queue index
					tellerIndex = i;
					tQueue= tellers.at(tellerIndex);
					allSame = false;
				}
			}
			if(allSame==tellers.size()) {
				event->action(tellers.at(rand() % (tellers.size())));
				delete event;
			}
			else {
				event->action(tQueue);
				delete event;
			}
		}
	}
	return nullptr;
}
EventQueue::~EventQueue() {
	// TODO Auto-generated destructor stub
}

