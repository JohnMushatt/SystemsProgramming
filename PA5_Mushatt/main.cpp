#include "TellerQueue.h"
#include "EventQueue.h"
#include "Customer.h"
#include "CustomerEvent.h"
#include "Teller.h"
#include "TellerEvent.h"
#include <stdlib.h>
#include <array>
#include <iostream>
#include <cstdlib>
int main(int argc, char **argv) {
	std::cout << "Program starting" << std::endl;
	// ./qsim #customers #tellers simulationTime(in mins) averageServiceTime <seed>
	// ./qsim 100 4  60 2.3
	//        100 customers 4 tellers 60 simulated mins 2.3 mins per customer
	if ((argc < 5) or (argc > 6)) {
		std::cout << "Program Finished!" << std::endl;
		return EXIT_FAILURE;
	}
	int numCust = atoi(argv[1]);
	int numTeller = atoi(argv[2]);
	int simTime = atoi(argv[3]) * 60;
	int serviceTime = atoi(argv[4]) * 60;
	//Create a teller
	Teller *teller = new Teller();
	int seed;
	if (argc == 6) {
		seed = atoi(argv[5]);
	} else {
		seed = time(NULL);
	}
	std::cout << "Simulation will run with: " << numCust << " Customers "
			<< numTeller << " Tellers " << simTime << " Seconds " << serviceTime
			<< " is the average service time  " << seed << " Is the seed"
			<< std::endl;

	//Create single event queue
	EventQueue *Bank = new EventQueue();

	//Create single teller queue
	TellerQueue *tellerLine = new TellerQueue();

	int custGenerated = 0;
	int currentTime = 0;
	while (currentTime < simTime) {

		//Generate customers at random times
		if (custGenerated < numCust) {
			if (rand() % 100 < 50) {

				//Create customer, add them to event queue
				Customer *cust = new Customer(rand() % simTime);
				Bank->addEvent(new CustomerEvent(cust->getTime()));
				//Increment num of generated customers
				custGenerated++;

			}
		}
		//If there are events to process
		if (Bank->getQueueSize() > 0) {


		}
		currentTime++;
	}

//Print tellerLine after customers have been added to it
	tellerLine->printQueue();

//Begin looping for simulation
	bool simulationStillRunning = true;
//Beginning time
//Loop while we are still running the simulation
	std::cout << "Beginning Simulation!" << std::endl;
	int customersLeft = numCust;
	while (currentTime < simTime) {
		if (tellerLine->getNextCustomer() == nullptr) {
			teller->updateBreakStatus(tellerLine);
		} else if (teller->onBreak == false) {
			std::cout << "Time before processing: " << currentTime << std::endl;
			while (currentTime < serviceTime) {
				currentTime++;
			}
			tellerLine->processCustomer();
			customersLeft--;
			std::cout << "Time after processing: " << currentTime << std::endl;
		}
		currentTime++;
	}
	std::cout << "Simulation Ending!" << std::endl;

	std::cout << "Program Finished" << std::endl;
	return 0;
}
