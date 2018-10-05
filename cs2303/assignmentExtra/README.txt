John Mushatt: Extra Credit Assignment

Obersvations and Conclusions: In the 3 seperate tests, the sorting method using pointer arithmetic (no. 3) operated faster, especially as the # of elements in the array grew. This is odd as modern compilers optimize these kinds of 
repetive tasks very efficiently, potentialy even more efficient than pointer arithmetic.


-----------------------------------------------------------------------------------
Array size = 100000

Test 1:
Method 1 (Array Index): 	Time spent sorting: Seconds: 28 Microseconds: 51036
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 28 Microseconds: 310688
Method 3 (Pointer Arithmetic):  Time spent sorting: Seconds: 26 Microseconds: 107563

Test 2:
Method 1 (Array Index):		Time spent sorting: Seconds: 30 Microseconds: 189070 	
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 28 Microseconds: 744075
Method 3 (Pointer Arithmetic):	Time spent sorting: Seconds: 27 Microseconds: 333066

Test 3:
Method 1 (Array Index): 	Time spent sorting: Seconds: 30 Microseconds: 105583
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 28 Microseconds: 168035
Method 3 (Pointer Arithmetic):	Time spent sorting: Seconds: 27 Microseconds: 272603

Test 4:
Method 1 (Array Index): 	Time spent sorting: Seconds: 29 Microseconds: 250902	
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 28 Microseconds: 186837
Method 3 (Pointer Arithmetic):	Time spent sorting: Seconds: 26 Microseconds: 523210

Test 5:
Method 1 (Array Index): 	Time spent sorting: Seconds: 29 Microseconds: 263540
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 29 Microseconds: 451755
Method 3 (Pointer Arithmetic):	Time spent sorting: Seconds: 27 Microseconds: 566752


Average Method 1: Seconds: 29.2 Microseconds:  172026.2
Average Method 2: Seconds: 28.2 Microseconds:  372278
Average Method 3: Seconds: 26.6 Microseconds:  360638.8
-----------------------------------------------------------------------------------
Array size = 75000

Test 1:
Method 1 (Array Index):		Time spent sorting: Seconds: 16 Microseconds: 237969
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 19 Microseconds: 259852
Method 3 (Pointer Arithmetic):	Time spent sorting: Seconds: 15 Microseconds: 318644

Test 2:
Method 1 (Array Index):		Time spent sorting: Seconds: 16 Microseconds: 399136
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 15 Microseconds: 313674	
Method 3 (Pointer Arithmetic):	Time spent sorting: Seconds: 15 Microseconds: 668157

Test 3:
Method 1 (Array Index):		Time spent sorting: Seconds: 15 Microseconds: 174740
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 16 Microseconds: 124938
Method 3 (Pointer Arithmetic):	Time spent sorting: Seconds: 15 Microseconds: 749203

Test 4:
Method 1 (Array Index):		Time spent sorting: Seconds: 16 Microseconds: 67836
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 16 Microseconds: 76725
Method 3 (Pointer Arithmetic):	Time spent sorting: Seconds: 14 Microseconds: 110804

Test 5:
Method 1 (Array Index):		Time spent sorting: Seconds: 15 Microseconds: 204499
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 16 Microseconds: 72802
Method 3 (Pointer Arithmetic):	Time spent sorting: Seconds: 16 Microseconds: 19242

Average Method 1: Seconds: 15.6 Microseconds:  216836
Average Method 2: Seconds: 16.4 Microseconds:  169598.2
Average Method 3: Seconds: 15   Microseconds:  373210
-----------------------------------------------------------------------------------
Array size = 50000

Test 1:
Method 1 (Array Index): 	Time spent sorting: Seconds: 7 Microseconds: 896377
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 8 Microseconds: 649126
Method 3 (Pointer Arithmetic):  Time spent sorting: Seconds: 6 Microseconds: 900687

Test 2:
Method 1 (Array Index): 	Time spent sorting: Seconds: 7 Microseconds: 205212
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 7 Microseconds: 614108
Method 3 (Pointer Arithmetic): 	Time spent sorting: Seconds: 7 Microseconds: 177805

Test 3:
Method 1 (Array Index):		Time spent sorting: Seconds: 7 Microseconds: 681830
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 7 Microseconds: 695532
Method 3 (Pointer Arithmetic): 	Time spent sorting: Seconds: 7 Microseconds: 117892

Test 4:
Method 1 (Array Index):		Time spent sorting: Seconds: 7 Microseconds: 157614
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 7 Microseconds: 233237
Method 3 (Pointer Arithmetic): 	Time spent sorting: Seconds: 8 Microseconds: 401273

Test 5:
Method 1 (Array Index):		Time spent sorting: Seconds: 7 Microseconds: 322889
Method 2 (Pointer + Index):	Time spent sorting: Seconds: 8 Microseconds: 456107
Method 3 (Pointer Arithmetic): 	Time spent sorting: Seconds: 6 Microseconds: 130110

Average Method 1: Seconds: 7    Microseconds:  452784.4
Average Method 2: Seconds: 7.4  Microseconds:  529622
Average Method 3: Seconds: 6.8  Microseconds:  345553.4
-----------------------------------------------------------------------------------