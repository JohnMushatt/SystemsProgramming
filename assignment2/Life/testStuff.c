#include <stdio.h>
#include <stdlib.h>
#include "twoD.h"
void buildBoard();

int main(int argc, char **argv) {
  char *inputFileName; // Name of file containing initial grid
	FILE *input; // Stream descriptor for file containing initial grid
	int nrows; // Number of rows in the grid
	int ncolumns; // Number of columns in the grid
	int gens; // Number of generations to produce
	int doPrint; // 1 if user wants to print each generation, 0 if not
	int doPause; // 1 if user wants to pause after each generation, 0 if not
	char **grid_before; // A 2D array to hold the pattern
	char **grid_after;
  // See if there are the right number of arguments on the command line
	if ((argc < 5) || (argc > 7)) {
		// If not, tell the user what to enter.
		printf("Usage:\n");
		printf("  ./life rows columns generations inputFile [print] [pause]\n");
		return EXIT_FAILURE;
	}


  	/* Save the command-line arguments.
  	   Also need to check if print and/or pause arguments were entered,
  	   and if so, what they were.
  	   A switch statement might be handy here.
  	*/
  	nrows = atoi(argv[1]); // Convert from character string to integer.
  	ncolumns = atoi(argv[2]);
  	gens = atoi(argv[3]);
  	inputFileName = argv[4];
    if(*argv[5]=='y') {
      doPrint=1;
    }
    else {
      doPrint=0;
    }
    if(*argv[6]=='y') {
      doPause=1;
    }
    else {
      doPause=0;
    }

    printf("%d %d %d %s %d %d\n",nrows,ncolumns,gens,inputFileName,doPrint,doPause );

    grid_before = make2Dchar(nrows, ncolumns);
  	grid_after = make2Dchar(nrows,ncolumns);

    input = fopen(inputFileName, "r");
  	if (!input) {
  		printf("Unable to open input file: %s\n", inputFileName);
  		return EXIT_FAILURE;
  	}
  	else {
  		buildBoard(input, grid_before,nrows,ncolumns);
  	}

  	/*Once opened, you can read from the file one character at a time with fgetc().
  	 * You can read one line at a time using fgets().
  	 * You can read from standard input (the keyboard) with getchar().
  	*/

  	return EXIT_SUCCESS;



}
void buildBoard(FILE* file, char** board, int nrows, int ncolumns) {
	int c;
  char* current;
  printf("%d\t%d\n",nrows,ncolumns );
	for (int i =0; i < nrows; i++) {

		for(int j =0; j < ncolumns; j++) {
      current = board[i];
			if((c=fgetc(file)) != EOF) {
				current[j] = c;
			}
      else{
        current[j] = 'o';
      }
		}
		printf("\n");
	}

}
void printBoard(char** board, int nrows, int ncolumns) {

  for(int i = 0; i < nrows; i++) {

    for(int j=0; j < ncolumns,j++) {
      char* c = board[i];
      printf("%c",c[j]);
    }
    printf("\n");
  }
}
