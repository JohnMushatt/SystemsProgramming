#include "TellerQueue.h"
#include "EventQueue.h"
#include "CustomerEvent.h"
#include "Teller.h"
#include "TellerEvent.h"
#include <stdlib.h>
#include <array>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Customer.h"

void runSim(float simTime, TellerEvent** tellerEvents, TellerQueue** queues,
		int numCustomers, int numTellers, CustomerEvent** customerEvents,
		EventQueue *simulationQueue, int whichSim);
/**
 * Run the simulation with the given arguments, one for common queue and one for multi-queue
 * @param simTime Total time to run the sim
 * @param teller 2D Events Array to hold tellerEvents from initialization phase
 * @param queues 2D of teller queues
 * @param numCustomers # of customers for the simulation
 * @param
 */
void runSim(float simTime, TellerEvent** tellerEvents, TellerQueue** queues,
		int numCustomers, int numTellers, CustomerEvent** customerEvents,
		EventQueue *simulationQueue, int whichSim) {
	float currentTime = 0;
	while (currentTime <= simTime) {
		if (simulationQueue->getQueueSize() > 0) {
			Event *event = simulationQueue->getHead();
			float nextEventTime = 0;
			nextEventTime = simulationQueue->getHead()->getTime();

			bool correctTime = true;
			if (nextEventTime > simTime) {
				correctTime =false;
				currentTime=simTime+1;
			}
			if(correctTime){
				currentTime = nextEventTime;
				if (whichSim == 1) {
					event->action(currentTime, queues, 1, simulationQueue);
				} else if (whichSim == 0) {
					event->action(currentTime, queues, numTellers,
							simulationQueue);
				}
			}
		} else {
			break;
		}
	}
	int totalCustomersServed = 0;
	for (int i = 0; i < numCustomers; i++) {
		if (customerEvents[i]->getServicing()) {

			totalCustomersServed++;
		}
	}
	float waitTimerPerCustomer = 0;
	int served = 0;
	float sum = 0;
	float totalTime = 0;
	for (int i = 0; i < numCustomers; i++) {
		if (customerEvents[i]->getServicing()) {
			if (customerEvents[i]->getEndTime() > 0) {
				served++;
				sum += customerEvents[i]->getEndTime()
						- customerEvents[i]->getStartTime();
			}
		}
	}
	waitTimerPerCustomer = sum / served;

	float tellerServiceTimeTotal = 0;
	for (int i = 0; i < numTellers; i++) {
		tellerServiceTimeTotal += tellerEvents[i]->getTotalServices()
				* tellerEvents[i]->getServiceTime();
	}
	int totalServices = 0;
	for(int i = 0;i<numTellers;i++) {
		totalServices+=tellerEvents[i]->getTotalServices();
	}
	float totalIdleTime = 0;
	for (int i = 0; i < numTellers; i++) {
		totalIdleTime += tellerEvents[i]->getIdleTime() * tellerEvents[i]->getTotalIdles();
	}
	float maxTime = 0;
	for(int i = 0; i <numCustomers; i++) {
		if(customerEvents[i]->getEndTime()>0) {
			if(maxTime <  (customerEvents[i]->getEndTime() -customerEvents[i]->getStartTime())) {
				maxTime = customerEvents[i]->getEndTime() - customerEvents[i]->getStartTime();
			}
		}
	}
	std::cout << "\nSIMULATION REPORT:\n";
	if (whichSim == 0) {
		std::cout << "QEUEUE TYPE: ONE PER TELLER:" << std::endl;
	} else {
		std::cout << "QUEUE TYPE:  COMMON :" << std::endl;

	}
	std::cout << "Number of customers served:\t\t" << totalCustomersServed
			<< std::endl;
	std::cout << "Average wait per customer:\t\t" << waitTimerPerCustomer
			<< std::endl;
	std::cout<<"Max wait time for a customer:\t\t" <<maxTime<<std::endl;
	std::cout << "Total teller service time:\t\t" << tellerServiceTimeTotal
			<< std::endl;
	std::cout<<"Number of tellers:\t\t\t"<<numTellers<<std::endl;
	std::cout << "Total idle time:\t\t\t" << totalIdleTime << std::endl;
	std::cout << "Total services:\t\t\t\t" << totalServices << std::endl;
	std::cout<<"---------------------------------------------"<<std::endl;
}

int main(int argc, char **argv) {
	std::cout << "Program starting" << std::endl;
// ./qsim #customers #tellers simulationTime(in mins) averageServiceTime <seed>
// ./qsim 100 4  60 2.3
//        100 customers 4 tellers 60 simulated mins 2.3 mins per customer
	if ((argc < 5) or (argc > 6)) {
		std::cout << "Error, wrong inputs!" << std::endl;
		return EXIT_FAILURE;
	}
	int numCust = atoi(argv[1]);
	int numTeller = atoi(argv[2]);
	float simTime = atoi(argv[3]) * 60;
	float serviceTime = atoi(argv[4]);
	int seed;
	if (argc == 6) {
		seed = atoi(argv[5]);
		srand(seed);
	} else {
		seed = 0;
		srand(seed);
	}
	std::cout << "Simulation will run with: " << numCust << " Customer(s) "
			<< numTeller << " Teller(s) Sim Time: " << simTime << " Seconds "
			<< serviceTime << " is the average service time in seconds  "
			<< seed << " Is the seed" << std::endl;
	std::cout << "Beginning Simulation!" << std::endl;

	//Create single event queue
	EventQueue *Bank = new EventQueue();

	//Create set of tellers
	TellerQueue* queues[numTeller];

	//Create tellerevents
	TellerEvent* tellerEvents[numTeller];

	//Create customerevents
	CustomerEvent* customerEvents[numCust];


	float const idleMax=600;
	for (int i = 0; i < 2; i++) {

		if (i == 0) {

			//Create tellers
			for (int i = 0; i < numTeller; i++) {

				float tellerServiceTime = abs(serviceTime * rand()
						/ float(RAND_MAX));

				float tellerIdleTime = abs(
						idleMax * rand() / float(RAND_MAX));
				queues[i] = new TellerQueue();

				TellerEvent *tellerEvent = new TellerEvent(tellerServiceTime,
						tellerIdleTime, queues[i]);

				tellerEvents[i] = tellerEvent;

				Bank->addEvent(tellerEvent);
			}

			for (int i = 0; i < numCust; i++) {


				float startTime = abs(simTime * (rand() / ((float) RAND_MAX)));

				CustomerEvent *customer = new CustomerEvent(startTime);

				customerEvents[i] = customer;

				Bank->addEvent(customer);
				//std::cout<<"Customer added with start time: "<<startTime<<std::endl;

			}

			//Run sim with seperate queues
			runSim(simTime, tellerEvents, queues, numCust, numTeller,
					customerEvents, Bank, 0);

		} else {

			TellerQueue* sharedQueue[1];

			sharedQueue[0] = new TellerQueue();

			for (int i = 0; i < numTeller; i++) {

				float tellerServiceTime = serviceTime * rand()
						/ float(RAND_MAX);

				float tellerIdleTime = abs(
						idleMax * rand() / (float) (RAND_MAX));

				TellerEvent *teller = new TellerEvent(tellerServiceTime,
						tellerIdleTime, sharedQueue[0]);

				tellerEvents[i] = teller;

				Bank->addEvent(teller);
			}

			for (int i = 0; i < numCust; i++) {
				float startTime = abs(simTime * rand() / (float) (RAND_MAX));

				CustomerEvent *customer = new CustomerEvent(startTime);
				customerEvents[i] = customer;
				Bank->addEvent(customer);

			}

			runSim(simTime, tellerEvents, sharedQueue, numCust, numTeller,
					customerEvents, Bank, 1);

		}
	}

	std::cout << "Simulation Ending!" << std::endl;
	std::cout << "Program Finished" << std::endl;
	return 0;
}
