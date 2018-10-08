CLFFLAGS = -g -Wall

all: PA5_Mushatt

PA5_Mushatt: Customer.o Event.o EventQueue.o Teller.o TellerQueue.o CustomerEvent.o	TellerEvent.o main.o
	g++	Customer.o Event.o EventQueue.o Teller.o TellerQueue.o CustomerEvent.o TellerEvent.o main.o -o PA5_Mushatt
Customer.o:	Customer.cpp Customer.h
	g++ -c	Customer.cpp
Event.o:	Event.cpp Event.h
	g++	-c	Event.cpp
EventQueue.o:	EventQueue.cpp EventQueue.h
	g++ -c	EventQueue.cpp
Teller.o:	Teller.cpp	Teller.h
	g++ -c	Teller.cpp
TellerQueue.o:	TellerQueue.cpp	TellerQueue.h
	g++ -c	TellerQueue.cpp
CustomerEvent.o: CustomerEvent.cpp CustomerEvent.h
	g++ -c	CustomerEvent.cpp
TellerEvent.o: TellerEvent.cpp TellerEvent.h
	g++ -c	TellerEvent.cpp
main.o:	main.cpp
	g++	-c	main.cpp
docs:
	Doxygen 
clean:
	rm -f *.o Customer Event EventQueue Teller TellerQueue CustomerEvent TellerEvent main
