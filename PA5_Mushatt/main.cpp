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
	TellerQueue *teller = new TellerQueue();
	int lastTime = 0;
	std::array<Customer *, 10> customers;
	for (int i = 0; i < 10; i++) {
		bool numChanged = false;
		while (!numChanged) {
			int num = time(NULL);

			if (num > lastTime) {
				customers.at(i) = new Customer(num);
				std::cout << "Last in line: " << teller->getLastCustomer()
						<< std::endl;
				teller->addCustomer(customers.at(i));
				numChanged = true;
			}
			lastTime = num;

		}
		std::cout << "Customer added to line to teller queue" << std::endl;

	}
	teller->printQueue();
	teller->processCustomer();
	teller->printQueue();
	std::cout << "Program Finished" << std::endl;
	return 0;
}
