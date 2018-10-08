#include "TellerQueue.h"
#include "EventQueue.h"
#include "Customer.h"
#include "CustomerEvent.h"
#include "Teller.h"
#include "TellerEvent.h"
#include <stdlib.h>
#include <array>
#include <iostream>

int main(int argc, char **argv) {
	std::cout<<"Program starting"<<std::endl;
	//Create single event queue
	EventQueue *Bank = new EventQueue();
	//Create single teller queue
	TellerQueue *teller = new TellerQueue();

	std::array<Customer *,25> customers;
	for(int i = 0; i < 25;i++) {
		customers.at(i)=new Customer();
	}


	return 0;
}
