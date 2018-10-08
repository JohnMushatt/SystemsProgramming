/*
 * testFile.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */
#include "Organism.h"
#include "Board.h"
#include <iostream>
#include <stdlib.h>
int main(int argc, char **argv) {
	std::cout << "Starting Program" << std::endl;

	//./pa5 gridsize  numBugs numAnts num Turns seed pause
	int gridSize;
	int numBugs;
	int numAnts;
	int numTurns;
	int seed;
	int pause;
	if(argc ==1) {
		Board *game = new Board();
	}
	else if(argc>7) {
		std::cout <<"Usage:\n/pa5 gridsize  numBugs numAnts numTurns seed pause"<<std::endl;
		return EXIT_FAILURE;
	}
	else {
		gridSize = atoi(argv[1]);
		numBugs = atoi(argv[2]);
		numAnts = atoi(argv[3]);
		numTurns = atoi(argv[4]);
		seed = atoi(argv[5]);
		if((argc <7) or (atoi(argv[6])==0)) {
			Board *gameDefault = new Board(gridSize,gridSize,numBugs,numAnts,numTurns,seed,0);
		}
		else if(atoi(argv[6])>0) {
			Board *gameNotDefault = new Board(gridSize,gridSize,numBugs,numAnts,numTurns,seed,atoi(argv[6]));

		}
	}
	std::cout << "Program Finished" << std::endl;
	return EXIT_SUCCESS;
}

