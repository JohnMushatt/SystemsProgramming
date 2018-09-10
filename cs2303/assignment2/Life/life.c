/* Game of Life
*/

#include <stdio.h>
#include <stdlib.h>
#include "twoD.h"

void buildBoard();
void printBoard();
void buildBoardInitial();
void centerBoard();
/** Main function.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to character strings containing the
 *    words on the command line.
 * @return 0 if success, 1 if invalid command line or unable to open file.
 *
 */
int main(int argc, char **argv) {
	printf("Game of Life\n");

	char *inputFileName; // Name of file containing initial grid
	FILE *input; // Stream descriptor for file containing initial grid
	int nrows; // Number of rows in the grid
	int ncolumns; // Number of columns in the grid
	int gens; // Number of generations to produce
	int doPrint; // 1 if user wants to print each generation, 0 if not
	int doPause; // 1 if user wants to pause after each generation, 0 if not
	char **gridA; // A 2D array to hold the pattern
	char **gridB;

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

	printf("%d %d %d %s %d %d\n",nrows,ncolumns,gens,inputFileName,doPrint,doPause);

	/* Here is how you would allocate an array to hold the grid.
	*/
	gridA = make2Dchar(nrows, ncolumns);
	gridB = make2Dchar(nrows,ncolumns);
	// You should check that it succeeded.


	/* Eventually, need to try to open the input file.
	*/
	input = fopen(inputFileName, "r");
	if (!input) {
		printf("Unable to open input file: %s\n", inputFileName);
		return EXIT_FAILURE;
	}
	else {
		buildBoardInitial(input,gridA,nrows,ncolumns);
		printBoard(gridA,nrows,ncolumns);
		centerBoard(input,inputFileName,gridA,nrows,ncolumns);
		printBoard(gridA,nrows,ncolumns);
	}

	/*Once opened, you can read from the file one character at a time with fgetc().
	 * You can read one line at a time using fgets().
	 * You can read from standard input (the keyboard) with getchar().
	*/

	return EXIT_SUCCESS;
}


/*Build the initial board by reading from file and assiging values in array to
*	from values in the file, if there aren't enough values in the file than are specificed
* in the command line arguments add 'o's to fill the difference
*/
void buildBoardInitial(FILE* file, char** board, int rows,int columns) {
	char* current_position =  malloc(columns * sizeof(char *));

	for(int current_row=0; current_row < rows; current_row++) {
		current_position = board[current_row];
		for(int current_col = 0; current_col < columns; current_col++) {

			current_position[current_col] = 'o';
		}
	}
}

//nrow/2 - f frow/2
int getFileCol(FILE* file, char* fileName) {
	FILE* input = fopen(fileName, "r");
	int col_current= 0;
	int col_max= 0;
	char c;
	while((c=getc(input)) != EOF) {
		if(c!='\n') {
			col_current++;
		}
		else {
			if(col_current > col_max) {
				col_max=col_current;
			}
			col_current=0;
		}

	}
	fclose(input);
	return col_max;
}
int getFileRow(FILE* file,char* fileName) {
	FILE* input = fopen(fileName, "r");
	int row_current= 0;

	char c=getc(input);
	while(c!= EOF) {
		if(c=='\n') {
			row_current++;

		}
		c=getc(file);
	}
	fclose(input);
	return row_current;
}


int getFileLineX(FILE* file, char* fileName, int line_num) {
	FILE* input = fopen(fileName, "r");
	int row_current= 0;
	int num_x= 0;
	char c;
	while((c=getc(input)) != EOF) {

		if(row_current=line_num) {

			while((c=getc(input))!='\n') {

				if(c=='x') {

					num_x++;
				}
			}
			return num_x;
		}

		if(c!='\n') {
			row_current++;
		}
	}
	fclose(input);
	return num_x;
}


void centerBoard(FILE* file, char* fileName, char** board, int rows, int cols) {
	int file_col = getFileCol(file,fileName);
	int file_row = getFileRow(file,fileName);

	int start_row = rows/2 -file_row/2;
	int start_col = cols/2 -file_col/2;

	FILE* input = fopen(fileName, "r");
	char c;
	char* current =  malloc(cols * sizeof(char *));
	for(int i = start_row; i< rows; i++) {



		current = board[i];


		for(int j = start_col; j <cols; j++) {
			c=fgetc(input);
			if(c!=EOF) {
				if(c=='x') {
					current[j] = c;
				}
			}
			else {
				j = cols;
				i = rows;
			}
		}
	}
	fclose(input);
}
/*
void buildBoardInitialOld(FILE* file, char** board, int nrows, int ncolumns) {
	int c;
	char* current;
  printf("Rows: %d\tCols: %d\n",nrows,ncolumns );
	for (int current_row =0; current_row < nrows; current_row++) {

		for(int current_col =0;  current_col< ncolumns; current_col++) {
			current = board[current_row];
			c =fgetc(file);

			//If we are not end of file
			if(c!=EOF) {

				//If we are end of line, but not end of board
				if((c=='\n') && (current_col< ncolumns)) {
					//Then add remaining spaces
					int extra_spaces = ncolumns-current_col;

					while(extra_spaces>0) {
							current[ncolumns-extra_spaces] = 'o';
							printf("%c",current[ncolumns-extra_spaces]);
							extra_spaces--;

					}
					printf("\n");
				}
				else {
					if(c=='x') {
						current[current_col] = 'x';
						printf("%c", current[current_col]);
					}
					else if(c=='o') {
						current[current_col] = 'o';
						printf("%c", current[current_col]);
					}
				}
			}
		}
		//If end of file reached but still have rows to go through
		if(c==EOF && current_row < nrows) {
			current[current_col]='o';
			printf("%c", current[]);



			c=fgetc(file);
			//If we are not at end of file
			if(c!= EOF) {

				//If we have reach end of line, but still are less than col, keep adding
				if(c!='\n') {
					//If cell is occupied add 'x'
					if(c=='x') {
						current[current_col] = 'x';
					}
					else {
						current[current_col] = 'o';
					}
				}
				//If we reached end of line, but still need to add 'o's
				else if((c=='\n') &&(current_col < ncolumns)){

					int extra_spaces = ncolumns-current_col;

					while(extra_spaces + current_col <ncolumns) {
						current[current_col + extra_spaces]='o';
						extra_spaces--;
					}
				}
				printf("%c",board[current_row][current_col]);
			}
		}
		printf("\n");
	}
}*/

//Iterate through arrray and print it out
void printBoard(char** board, int nrows, int ncolumns) {
	char* current =  malloc(ncolumns * sizeof(char *));
  for(int i = 0; i < nrows; i++) {
		current = board[i];

    for(int j=0; j < ncolumns; j++) {
      printf("%c",current[j]);
    }
    printf("\n");
  }
	printf("\n\n\n");
}
