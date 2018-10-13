CFLAGS = -O0 -g -Wall

all: qSim 

qSim: Event.o Customer.o EventQueue.o TellerQueue.o CustomerEvent.o TellerEvent.o main.o
	g++	$(CFLAGS) Event.o Customer.o EventQueue.o TellerQueue.o CustomerEvent.o TellerEvent.o main.o -o qSim
Customer.o:	Customer.cpp Customer.h
	g++ $(CFLAGS) -c	Customer.cpp
Event.o: Event.cpp Event.h
	g++	$(CFLAGS) -c	Event.cpp
EventQueue.o: EventQueue.cpp EventQueue.h
	g++ $(CFLAGS) -c	EventQueue.cpp
TellerQueue.o: TellerQueue.cpp TellerQueue.h
	g++ $(CFLAGS) -c	TellerQueue.cpp
CustomerEvent.o: CustomerEvent.cpp CustomerEvent.h
	g++ $(CFLAGS) -c	CustomerEvent.cpp
TellerEvent.o: TellerEvent.cpp TellerEvent.h
	g++ $(CFLAGS) -c	TellerEvent.cpp
main.o:	main.cpp
	g++	$(CFLAGS) -c	main.cpp
docs:
	Doxygen 
clean:
	rm -f *.o qSim	
