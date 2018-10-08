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

	//Create single event queue
	EventQueue *Bank = new EventQueue();
	//Create single teller queue
	TellerQueue *teller = new TellerQueue();



	}
	std::cout<<Bank->getQueueSize()<<std::endl;
	Bank->removeEvent();
	std::cout<<Bank->getQueueSize()<<std::endl;
	return 0;
}
