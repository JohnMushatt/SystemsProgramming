John Mushatt Assignment 5: Event Driven Simulation:

To run this program, enter in the command line: make clean, make, 
then enter in ./qSim #ofCustomers #ofTellers simulationTime AverageTellerServiceTime Seed

#ofCustomers = An integer amount of customers
#ofTellers = An integer amount of tellers
simulationTime = Running time of simulation
AverageTellerServiceTime = Time it takes a teller to process a customer
Seed = integer seed for the rand() functions

Problems: The biggest problems I had designing this program  occurred when having the events, teller queues, and the event queue interact.
I went through multiple design styles from the Event Queue maintaining a collection of queues, to now having the events maintain more of the information
and have the EventQueue merely receiving and process these events as they come.

Structure: I structured the program into Teller and Customer Events, Customers, the EventQueue, TellerQueues, Events, and a main file. Events were used as 
a general structure that the EventQueue would interact with, these could either be Teller or Customer events. It would then call their respective action()
methods using dynamic binding and thus either teller or customer actions would fire off. Customers can be interpreted as a linked-list node for the TellerQueues.
TellerQueues act similar to the EventQueue as in they process customers by time.

Results: The common teller method is slightly faster as there are more queues thus 
PProgram starting
Simulation will run with: 100 Customer(s) 3 Teller(s) Sim Time: 3600 Seconds 2 is the average service time in seconds  0 Is the seed
Beginning Simulation!

SIMULATION REPORT:
QUEUE TYPE:  COMMON :
Number of customers served:		99
Average wait per customer:		48.3737
Max wait time for a customer:	120
Total teller service time:		176.019
Number of tellers:				3
Total idle time:				11174.5
Total services:					99
---------------------------------------------

SIMULATION REPORT:
QEUEUE TYPE: ONE PER TELLER:
Number of customers served:		97
Average wait per customer:		50.567
Max wait time for a customer:	155
Total teller service time:		130.541
Number of tellers:				3
Total idle time:				10859.3
Total services:					97
---------------------------------------------
Simulation Ending!
Program Finished