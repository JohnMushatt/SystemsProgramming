CFLAGS = -g -Wall

all: PA5_Mushatt 

PA5_Mushatt: Customer.o Event.o EventQueue.o Teller.o TellerQueue.o CustomerEvent.o	TellerEvent.o main.o Actor.o CustomerArrivalEvent.o
	g++	$(CFLAGS) Customer.o Event.o EventQueue.o Teller.o TellerQueue.o CustomerEvent.o TellerEvent.o	main.o	CustomerArrivalEvent.o Actor.o -o PA5_Mushatt
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
CustomerArrivalEvent.o: CustomerArrivalEvent.cpp CustomerArrivalEvent.h
	g++ $(CFLAGS) -c	CustomerArrivalEvent.cpp
docs:
	Doxygen 
clean:
	rm -f *.o PA5_Mushatt
