Assignment 4 by Tyler Ferrara

Build Program: make

Run Program: ./qSim #customers #tellers simulationTime averageServiceTime <seed>
	int 	#customers to create
	int 	#tellers to create
	float 	simulationTime (in minutes) to run Program
	float 	averageServiceTime time (in seconds) to complete service for each Teller
	int 	seed for psudo random number generator (default: 1)


Clean Project: make clean


Results:
	The results below show that the common method of having each
	Teller handle their own line was slightly more efficient and
	served more customers.

===========================================
		MULTI-LINE REPORT
Number of Customers Served: 	999
End-Time: 			3599.335449
Number of Tellers: 		3
Queuing-Type: 			common
AVG Customer Time: 		11.157519
Max Wait Time: 			76.576050
Total Teller Service-Time: 	2692.377197
Total Teller Idle-Time: 	8809.115234
===========================================
		ONE-LINE REPORT
Number of Customers Served: 	960
End-Time: 			3599.586914
Number of Tellers: 		3
Queuing-Type: 			share one line
AVG Customer Time: 		83.841576
Max Wait Time: 			154.381348
Total Teller Service-Time: 	2209.154297
Total Teller Idle-Time: 	9035.544922


Conclusions:
	This Multi-Line configuration where each Teller can have their own
	Line allows for better multitasking with a high volume of Customers,
	as apposed to each Teller sharing one Line. However, there is a drop
	in idle time with the ONE-LINE method, because Teller's rarely experience
	the one and only line to be empty.

Difficulties:
	Struggles of this lab was finding the correct way to structure the
	program in an Object Oriented fashion. Having to redo this assignment
	from poor structure made it apparent that the functionality would come
	naturally with well thought out Class Hierarchies.
