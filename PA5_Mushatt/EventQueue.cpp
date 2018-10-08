/*
 * EventQueue.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "EventQueue.h"
#include "Event.h"
EventQueue::EventQueue() {
	// TODO Auto-generated constructor stub
	head = nullptr;
	tail= nullptr;
	size = 0;

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
bool EventQueue::addEvent(Event *event) {
	if (event != nullptr) {
		if (size == 0) {
			head = event;
			tail = event;
			event->nextEvent=nullptr;
			size++;
			return true;
		} else {
			tail->nextEvent=event;
			tail=event;
			size++;
			return true;
		}
	}
	return false;
}
/**
 * Remove head of queue and set next event to be the head
 * @return Pointer to recently removed event, if nullptr it means queue is empty
 */
Event *EventQueue::removeEvent(){

	if(size>0) {
		Event *event = head;
		head = head->nextEvent;
		size--;
		return event;
	}
	return nullptr;
}
EventQueue::~EventQueue() {
	// TODO Auto-generated destructor stub
}

