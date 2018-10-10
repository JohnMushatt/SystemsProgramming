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
	if ((argc< 5) or (argc>6)) {
		return EXIT_FAILURE;
	}
	int numCust = atoi(argv[1]);
	int numTeller = atoi(argv[2]);
	float simTime = atoi(argv[3]);
	float serviceTime = atoi(argv[4]);
	int seed;
	if(argc==6) {
		seed = atoi(argv[5]);
	}
	else {
		seed = time(NULL);
	}
	//Create single event queue
	EventQueue *Bank = new EventQueue();
	//Create single teller queue
	TellerQueue *tellerLine = new TellerQueue();
	int lastTime = 0;
	std::array<Customer *, 3> customers;
	for (int i = 0; i < 3; i++) {
		bool numChanged = false;
		while (!numChanged) {
			int num = time(NULL);

			if (num > lastTime) {
				customers.at(i) = new Customer(num);
				tellerLine->addCustomer(customers.at(i));
				std::cout << "Last in line: " << tellerLine->getLastCustomer()
						<< std::endl;
				numChanged = true;
			}
			lastTime = num;

		}
		std::cout << "Customer added to line to teller queue" << std::endl;

	}

	//Print tellerLine after customers have been added to it
	tellerLine->printQueue();

	//Create a teller
	Teller *teller = new Teller();
	//Begin looping for simulation
	bool simulationStillRunning = true;
	//Loop while we are still running the simulation
	std::cout << "Beginning Simulation!" << std::endl;
	int customersLeft = numCust;
	while (simulationStillRunning) {
		if (tellerLine->getNextCustomer() == nullptr) {
			teller->updateBreakStatus(tellerLine);
		}
		if (teller->onBreak == false) {
			tellerLine->processCustomer(serviceTime);
			customersLeft--;
		}
		if(customersLeft==0){
			simulationStillRunning=false;
		}
	}
	std::cout << "Simulation Ending!" << std::endl;

	std::cout << "Program Finished" << std::endl;
	return 0;
}
