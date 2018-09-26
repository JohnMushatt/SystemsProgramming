John Mushatt Assignment 1 README


Summary:
	PA1 is a calendar program that prompts the user to enter a valid year after 1582 and produces a 12-month calendar. The program prompts the user until a valid input is given, then it starts printing out the calendar. 

Points of interest within the program are the method of calculating the 1st day of each year, produced by a modified version of Gauss’s Algorithm. The algorithm takes a year in, then subtracts one year from because the current month the program is using is January, then it takes both the first two and last two digits of the original year, lastly it retrieves a “shifted” month value resulting  from (target-month – 2) % 12. With these variables set, it injects them into the algorithm that then computes the day of the week assuming the week begins on Sunday = 0, however for this program we offset it by -1 as our week begins on Monday. Lastly it adds 6 if the number is negative to correct the value to the proper day

Two loop invariants  are also present in the program, one involves describing the method of updating the next_day that is fed into printing the correct calendar. The other is for keeping track of the number of days processed by the program to determine if the loop has passed the required number of days required. 

