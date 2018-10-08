CLFAGS= -g -Wall
PA4_Mushatt: Organism.o Board.o Ant.o Doodlebug.o testFile.o
	g++ Organism.o Board.o Ant.o Doodlebug.o testFile.o -o PA4_Mushatt
Organism.o:Organism.cpp Organism.h
	g++ -c Organism.cpp
Board.o: Board.cpp Board.h
	g++ -c Board.cpp
Ant.o: Ant.cpp Ant.h
	g++ -c Ant.cpp
Doodlebug.o: Doodlebug.cpp Doodlebug.h
	g++ -c Doodlebug.cpp
testFile.o: testFile.cpp
	g++ -c testFile.cpp
docs:
	Doxygen
clean:
	rm -f *.o Organism Ant Board Doodlebug testFile