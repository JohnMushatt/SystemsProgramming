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
	//Create single event queue
	EventQueue *Bank = new EventQueue();
	//Create single teller queue
	TellerQueue *tellerLine = new TellerQueue();
	int lastTime = 0;
	std::array<Customer *, 10> customers;
	for (int i = 0; i < 10; i++) {
		bool numChanged = false;
		while (!numChanged) {
			int num = time(NULL);

			if (num > lastTime) {
				customers.at(i) = new Customer(num);
				std::cout << "Last in line: " << tellerLine->getLastCustomer()
						<< std::endl;
				tellerLine->addCustomer(customers.at(i));
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
	std::cout<<"Beginning Simulation!"<<std::endl;

	while (simulationStillRunning) {
		if (teller->onBreak == false) {
			tellerLine->processCustomer(teller->getIdleTime());
		}
	}
	std::cout<<"Simulation Ending!"<<std::endl;

	std::cout <<"Program Finished" << std::endl;
	return 0;
}
