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
	//Teller *teller = new Teller();
	int seed;
	if (argc == 6) {
		seed = atoi(argv[5]);
	} else {
		seed = time(NULL);
	}
	std::cout << "Simulation will run with: " << numCust << " Customer(s) "
			<< numTeller << " Teller(s) Sim Time: " << simTime << " Seconds "
			<< serviceTime << " is the average service time in seconds  "
			<< seed << " Is the seed" << std::endl;

	//Create single event queue
	EventQueue *Bank = new EventQueue(numTeller);

	//Create single teller queue
	TellerQueue *tellerLine = new TellerQueue();

	int custGenerated = 0;
	int currentTime = 0;
	std::cout << "Beginning Simulation!" << std::endl;

	while (currentTime < simTime) {

		//Generate customers at random times
		if (custGenerated < numCust) {
			if (rand() % 100 < 50) {
				Event *event = new CustomerEvent(rand()%100+1);
				//Create customer, add them to event queue
				Bank->addEvent(event);
				std::cout<<"CustomerEvent Added with time: "<< event->getEventTime() <<" EventQueue size: "<<Bank->getQueueSize()<<std::endl;
				//Increment num of generated customers
				custGenerated++;

			}
		}

		currentTime++;
	}
	Bank->printEventQueue();
	Bank->removeEvent();
	Bank->printTellerQueues();
	Bank->removeEvent();
	std::cout<<"\n\n";
	Bank->printTellerQueues();
	std::cout << "Simulation Ending!" << std::endl;
	std::cout << "Program Finished" << std::endl;
	return 0;
}
