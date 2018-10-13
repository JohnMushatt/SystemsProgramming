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
	head = nullptr;
	size = 0;
}
/**
 * Retrieve the head of the event queue
 * @return head/1st of event queue
 */
Event *EventQueue::getHead() {
	return head;
}
/**
 * Retrieve queue size
 * @return size of event queue
 */
int EventQueue::getQueueSize() {
	return size;
}

/**
 * Add event to the queue
 * @param event Pointer to event to add
 */
void EventQueue::addEvent(Event *event) {

	//If we are a 0-sized queue
	if (size < 1) {
		//set head to event
		head = event;
		//Increase size
		size++;

	} else {
		bool addedEvent = false;
		Event *currentEvent = head;
		//Loop through the queue and place event
		for (int i = 0; i < size; i++) {
			if (event->getTime() < currentEvent->getTime()) {

				event->setNext(currentEvent);

				if (currentEvent == head) {
					head = event;
				} else {

					getEventAt(i - 1)->setNext(event);

				}
				addedEvent = true;
				break;
			} else {
				currentEvent = currentEvent->getNextEvent();
			}
		}
		//If we are at the end, retrieve tail node and set it to the new event
		if (!addedEvent) {
			getEventAt(size - 1)->setNext(event);
		}
		size++;
	}

	/*
	 Event *current;
	 if(size==0) {
	 head = event;
	 size++;
	 }
	 //If the queue is empty or we have arrived at the correct spot
	 if ((head->getTime() >= event->getTime())) {
	 event->setNext(head);
	 head = event;
	 size++;
	 } else {

	 current = head;
	 //Set i to be the current index
	 int i =0;
	 //While we are not at the end of the queue
	 while (current->getNextEvent() != nullptrptr and i <size) {

	 //If the current event is smaller than the new event
	 if (current->getNextEvent()->getTime() < event->getTime()) {
	 //Update current
	 current = current->getNextEvent();
	 //Update index
	 i++;
	 }
	 //If the new event is smaller than the current element, set it to be the event before current
	 else {
	 //Set event's next event to be current's
	 event->setNext(current);
	 //Set previous of current to point to event
	 getAt(i-1)->setNext(event);
	 break;

	 }
	 }
	 if (event->getNextEvent() == nullptrptr) {
	 getAt(i-1)->setNext(event);
	 }
	 size++;
	 }
	 */
}
/**
 * Retrieve even in the queue at a certain index
 * @param index Event to retrieve
 */
Event* EventQueue::getEventAt(int index) {
	//If not out of bounds
	if (size > index) {
		Event* next = head;
		//Loop until we get the correct index
		for (int i = 0; i < index; i++) {
			next = next->getNextEvent();
		}
		return next;
	} else {

		return nullptr;
	}
}
/**
 * Remove event from the event queue
 */
void EventQueue::removeEvent() {

	//If 0-sized queue
	if (size <= 1) {
		//Delete the head
		delete head;
		//Dereference it
		head = nullptr;
		size--;
	} else {
		Event *event = head;
		head = event->getNextEvent();
		size--;
	}
}
EventQueue::~EventQueue() {
// TODO Auto-generated destructor stub
}

