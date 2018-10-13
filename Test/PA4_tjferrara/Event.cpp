/*
 * Event.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: tjferrara
 */

#include "Event.h"
#include "stdlib.h"

/**Constructs Event Object
 */
Event::Event() {
	time = -1;
	prev = NULL;
}

/**Destructs Event Object
 */
Event::~Event() {

}

/**Placeholder function that will be overridden by CustomerEvent or TellerEvent to run some action
 * @param clock running clock of simulation
 * @param lines array of TellerQueues
 * @param numLines number of TellerQueues in lines array
 * @param eventQueue Queue being used as time-line
 */
void Event::action(float clock, TellerQueue** lines, int numLines, EventQueue* eventQueue) {

}

/**Gets Priority Time value
 * @return priority time value
 */
float Event::getTime() {
	return time;
}

/**Gets Previous Event from EventQueue
 * @return previous event
 */
Event* Event::getPrev() {
	return prev;
}

/**Sets Previous Event from EventQueue
 */
void Event::setPrev(Event* event) {
	prev = event;
}

