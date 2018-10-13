//============================================================================
// Name        : qSim.cpp
// Author      : Tyler Ferrara
// Version     :
// Copyright   : Open Source
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include "TellerQueue.h"
#include "TellerQueueNode.h"
#include "Event.h"
#include "TellerEvent.h"
#include "CustomerEvent.h"
#include "EventQueue.h"



void printEQ(EventQueue* eventQueue);
void runSimulation(float simulationTime, EventQueue* eventQueue, CustomerEvent** customersCollection, int customers, TellerEvent** tellersCollection, int tellers, TellerQueue** tellerLines, bool shareLines);
int findServedCustomers(CustomerEvent** customers, int numCustomers);
float findAvgCustomerTime(CustomerEvent** customers, int numCustomers);
float findMaxWait(CustomerEvent** customers, int numCustomers);
float findTotalServiceTimes(TellerEvent** tellers, int numTellers);
float findTotalIdleTimes(TellerEvent** tellers, int numTellers);



using namespace std;

int main(int argc, char** argv) {

	int customers;
	int tellers;
	float simulationTime;
	float averageServiceTime;
	int seed = 1;

	// Collecting Arguments
	if (argc > 6 || argc < 5) {
		cerr << "ERROR: Invalid number of arguments!\nCorrect format: ./qSim #customers #tellers simulationTime averageServiceTime <seed>";
		return 1;
	}
	customers = atoi(argv[1]);
	tellers = atoi(argv[2]);

	simulationTime = 60 * strtof(argv[3], NULL); // x 60 to convert minutes to seconds
	averageServiceTime = strtof(argv[4], NULL);
	if (argc == 6) {
		seed = atoi(argv[5]);
	}

	// Setting 'Random' Number Generator
	srand(seed);

	printf("*****************************************\n");
	printf("\tBUILD CONFIGURATION\n");
	printf("Customers: \t\t%d\n", customers);
	printf("Tellers: \t\t%d\n", tellers);
	printf("Simulation_Time: \t%f\n", simulationTime);
	printf("AVG_Service_Time: \t%f\n", averageServiceTime);
	printf("Seed: \t\t\t%d\n", seed);
	printf("*****************************************\n");


	// Generating Events Queue
	EventQueue* eventQueue = new EventQueue();

	// Create Teller Lines
	TellerQueue* tellerLines[tellers];

	// Collection Customers for report
	CustomerEvent* customersCollection[customers];

	// Collection Tellers for report
	TellerEvent* tellersCollection[tellers];

	float idleMax = 600;

	for (int i = 0; i < 2; i++) { // RUN PROGRAM TWICE

		if (i == 0) { // First Run has teller with seperate lines

			// Add Tellers Arriving to Events Queue
				for (int i = 0; i < tellers; i++) {
					// Generating Random Service Time
					float serviceTime = 2*averageServiceTime*rand()/float(RAND_MAX);
					// Generating Random Idol Time
					float idleTime = idleMax*rand()/float(RAND_MAX);
					// Build New Teller Line
					tellerLines[i] = new TellerQueue();
					// Create Teller
					TellerEvent* newTeller = new TellerEvent(serviceTime, idleTime, tellerLines[i]);
					// Add Teller to Collection
					tellersCollection[i] = newTeller;
					// Add Teller to Event Queue
					eventQueue->push(newTeller);
				}

				// Add Customers Arriving to Events Queue
				for (int i = 0; i < customers; i++) {
					// Generating Random Arrival Time
					float arrTime = simulationTime*rand()/float(RAND_MAX);
					// Create New Customer
					CustomerEvent* newCustomer = new CustomerEvent(arrTime);
					// add customer to collection
					customersCollection[i] = newCustomer;
					// Push customer to Event Queue
					eventQueue->push(newCustomer);
				}

				runSimulation(simulationTime, eventQueue, customersCollection, customers, tellersCollection, tellers, tellerLines, false);

		} else {	// Second Run has tellers sharing a line

			// Create Teller Line
			TellerQueue* onlyTellerLine[1];
			// Build New Teller Line
			onlyTellerLine[0] = new TellerQueue();

			// Add Tellers Arriving to Events Queue
			for (int i = 0; i < tellers; i++) {
				// Generating Random Service Time
				float serviceTime = 2*averageServiceTime*rand()/float(RAND_MAX);
				// Generating Random Idol Time
				float idleTime = idleMax*rand()/float(RAND_MAX);
				// Create Teller
				TellerEvent* newTeller = new TellerEvent(serviceTime, idleTime, onlyTellerLine[0]);
				// Add Teller to Collection
				tellersCollection[i] = newTeller;
				// Add Teller to Event Queue
				eventQueue->push(newTeller);
			}

			// Add Customers Arriving to Events Queue
			for (int i = 0; i < customers; i++) {
				// Generating Random Arrival Time
				float arrTime = simulationTime*rand()/float(RAND_MAX);
				// Create New Customer
				CustomerEvent* newCustomer = new CustomerEvent(arrTime);
				// add customer to collection
				customersCollection[i] = newCustomer;
				// Push customer to Event Queue
				eventQueue->push(newCustomer);
			}
			runSimulation(simulationTime, eventQueue, customersCollection, customers, tellersCollection, tellers, onlyTellerLine, true);
		}

	}

	return EXIT_SUCCESS;
}

/** Prints the times of each Event in eventQueue
 * 	@param eventQueue given Queue to print
 */
void printEQ(EventQueue* eventQueue) {
	Event* e = eventQueue->top();
	for (int i = 0; i < eventQueue->getSize(); i++) {
		printf("E%d:\t%f\n", i, e->getTime());
		if (e->getPrev() != NULL) {
			e = e->getPrev();
		}
	}
}

/** Finds number of customer's served in simulation
 * 	@param customers array of CustomerEvent
 * 	@param numCustomers number of CustomerEvents
 * 	@return number of customer's served
 */
int findServedCustomers(CustomerEvent** customers, int numCustomers) {
	int numustomerServed = 0;
	for (int i = 0; i < numCustomers; i++) {
		if (customers[i]->getServicing()) {
			numustomerServed++;
		}
	}
	return numustomerServed;
}

/** Calculates the AVG CustomerEvent wait time for all customers
 * 	@param customers array of CustomerEvent
 * 	@param numCustomers number of CustomerEvents
 * 	@return average wait time for all customers
 */
float findAvgCustomerTime(CustomerEvent** customers, int numCustomers) {
	float sum = 0;
	float timeSpent = 0;
	int numServed = 0;
	for (int i = 0; i < numCustomers; i++) {
		if (customers[i]->getServicing()) {
			if (customers[i]->getLeaveTime() > 0) { // Did the customer leave?
				numServed++;
				timeSpent = abs(customers[i]->getLeaveTime() - customers[i]->getArrivalTime());
				sum += timeSpent;
			}
		}
	}
	return sum/numServed;
}

/** Calculates the largest CustomerEvent wait time out of all customers
 * 	@param customers array of CustomerEvent
 * 	@param numCustomers number of CustomerEvents
 * 	@return largest wait time out of all customers
 */
float findMaxWait(CustomerEvent** customers, int numCustomers) {
	float max = customers[0]->getLeaveTime() - customers[0]->getArrivalTime();
	float timeSpent = 0;
	for (int i = 1; i < numCustomers; i++) {
		if (customers[i]->getLeaveTime() > 0) { // Did the customer leave?
			timeSpent = customers[i]->getLeaveTime() - customers[i]->getArrivalTime();
			if (timeSpent > max) {
				max = timeSpent;
			}
		}
	}
	return max;
}

/** Calculates sum of service times performed
 * 	@param tellers array of TellerEvent
 * 	@param numTellers number of TellerEvents
 * 	@return sum of service times
 */
float findTotalServiceTimes(TellerEvent** tellers, int numTellers) {
	float fullTotal = 0;
	float numServices = 0;
	float serviceTime = 0;
	for (int i = 0; i < numTellers; i++) {
		numServices = tellers[i]->getNumServices();
		serviceTime = tellers[i]->getServiceTime();
		fullTotal += numServices * serviceTime;
	}
	return fullTotal;
}

/** Calculates sum of idle times called
 * 	@param tellers array of TellerEvent
 * 	@param numTellers number of TellerEvents
 * 	@return sum of idle times
 */
float findTotalIdleTimes(TellerEvent** tellers, int numTellers) {
	float fullTotal = 0;
	float numIdles = 0;
	float idleTime = 0;
	for (int i = 0; i < numTellers; i++) {
		numIdles = tellers[i]->getNumIdles();
		idleTime = tellers[i]->getIdleTime();
		fullTotal += numIdles * idleTime;
	}
	return fullTotal;
}

/** Runs simulation and reports values
 * 	@param simulationTime time limit of simulation
 * 	@param eventQueue EventQueue to run
 * 	@param customersCollection array of CustomerEvents
 * 	@param customers number of CustomerEvents
 * 	@param tellersCollection array of TellerEvents
 * 	@param tellers number of TellerEvents
 * 	@param tellerLines array of TellerQueues
 * 	@param shareLines variable to tell if tellers are sharing one line
 */
void runSimulation(float simulationTime, EventQueue* eventQueue, CustomerEvent** customersCollection, int customers, TellerEvent** tellersCollection, int tellers, TellerQueue** tellerLines, bool shareLines) {


	// START SIMULATION
	float CLOCK = 0;

	while (CLOCK <= simulationTime) {
		if (eventQueue->getSize() > 0) {
//			printf("CLOCK: %f\n", CLOCK);
//			printf("MAX_CLOCK: %f\n", simulationTime);
//			printf("sizeOfQueue: %d\n", eventQueue->getSize());
//			printEQ(eventQueue);
			// Find next time of event
			float nextTime = eventQueue->top()->getTime();
			if (nextTime > simulationTime) { // make sure to not go over simulationTime
				break;
			}
			// Set time to clock
			CLOCK = nextTime;
			// Run Action
			if (shareLines) {
				eventQueue->top()->action(CLOCK, tellerLines, 1, eventQueue);
			} else {
				eventQueue->top()->action(CLOCK, tellerLines, tellers, eventQueue);
			}
		} else {
			break;
		}
	}


	// Generate Report
	int numCustomerServed = findServedCustomers(customersCollection, customers);
	string queuingType;
	if (shareLines) {
		queuingType = "share one line";
	} else {
		queuingType = "common";
	}
	float avgCustomerTime = findAvgCustomerTime(customersCollection, customers);
	float maxWait = findMaxWait(customersCollection, customers);
	float totalTellerService = findTotalServiceTimes(tellersCollection, tellers);
	float totalTellerIdle = findTotalIdleTimes(tellersCollection, tellers);

	printf("===========================================\n");
	if (shareLines) {
		printf("\t\tONE-LINE REPORT\n");
	} else {
		printf("\t\tMULTI-LINE REPORT\n");
	}
	printf("Number of Customers Served: \t%d\n", numCustomerServed);
	printf("End-Time: \t\t\t%f\n", CLOCK);
	printf("Number of Tellers: \t\t%d\n", tellers);
	printf("Queuing-Type: \t\t\t");
	cout << queuingType << '\n'; // to print a variable of type string
	printf("AVG Customer Time: \t\t%f\n", avgCustomerTime);
	printf("Max Wait Time: \t\t\t%f\n", maxWait);
	printf("Total Teller Service-Time: \t%f\n", totalTellerService);
	printf("Total Teller Idle-Time: \t%f\n", totalTellerIdle);
}

