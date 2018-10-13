/*
 * EventQueue.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "EventQueue.h"
#include "Event.h"
#include <iostream>

/**
 * Constructor, set head to nullptr and size to 0
 */
EventQueue::EventQueue() {

}
/**
 * Retrieve the head of the event queue
 * @return head/1st of event queue
 */
Event *EventQueue::getHead() {
	return pQueue.top();
}
/**
 * Retrieve queue size
 * @return size of event queue
 */
int EventQueue::getQueueSize() {
	return pQueue.size();
}

/**
 * Add event to the queue
 * @param event Pointer to event to add
 */
void EventQueue::addEvent(Event *event) {
	pQueue.push(event);

}

/**
 * Remove event from the event queue
 */
void EventQueue::removeEvent() {
	pQueue.pop();
}
EventQueue::~EventQueue() {
// TODO Auto-generated destructor stub
}

