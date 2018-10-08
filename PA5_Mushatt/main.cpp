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


	EventQueue *Bank = new EventQueue();

	for(int i = 0; i < 10; i++) {
		Bank->addEvent(new CustomerEvent());
		std::cout<<"Customer Event Added"<<std::endl;
		std::cout<<Bank->getQueueSize()<<std::endl;


	}
	std::cout<<Bank->getQueueSize()<<std::endl;
	Bank->removeEvent();
	std::cout<<Bank->getQueueSize()<<std::endl;
	return 0;
}
