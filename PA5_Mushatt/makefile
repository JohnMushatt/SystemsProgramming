CFLAGS = -g -Wall

all: qSim 

qSim: Customer.o Event.o EventQueue.o Teller.o TellerQueue.o CustomerEvent.o	TellerEvent.o main.o Actor.o
	g++	$(CFLAGS) Customer.o Event.o EventQueue.o Teller.o TellerQueue.o CustomerEvent.o TellerEvent.o	main.o Actor.o -o qSim
Customer.o:	Customer.cpp Customer.h
	g++ $(CFLAGS) -c	Customer.cpp
Event.o: Event.cpp Event.h
	g++	$(CFLAGS) -c	Event.cpp
EventQueue.o: EventQueue.cpp EventQueue.h
	g++ $(CFLAGS) -c	EventQueue.cpp
Teller.o: Teller.cpp	Teller.h
	g++ $(CFLAGS) -c	Teller.cpp
TellerQueue.o: TellerQueue.cpp TellerQueue.h
	g++ $(CFLAGS) -c	TellerQueue.cpp
CustomerEvent.o: CustomerEvent.cpp CustomerEvent.h
	g++ $(CFLAGS) -c	CustomerEvent.cpp
TellerEvent.o: TellerEvent.cpp TellerEvent.h
	g++ $(CFLAGS) -c	TellerEvent.cpp
main.o:	main.cpp
	g++	$(CFLAGS) -c	main.cpp
Actor.o: Actor.cpp Actor.h
	g++	$(CFLAGS) -c	Actor.cpp
docs:
	Doxygen 
clean:
	rm -f *.o qSim	
