/* Game of Life
*/

#include <stdio.h>
#include <stdlib.h>
#include "twoD.h"

void buildBoard();
void printBoard();
void buildBoardInitial();
void centerBoard();
void computeGeneration();
int checkBoardDeath();
int checkBoardSteadyState();
int checkBoardOscillates();
int checkBoardGenCount();
void generateGame();
int checkForWinCondition();
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
	//char **gridA; // A 2D array to hold the pattern
	//char **gridB;

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


	/* Here is how you would allocate an array to hold the grid.
	*/
	//gridA = make2Dchar(nrows, ncolumns);
	//gridB = make2Dchar(nrows,ncolumns);
	// You should check that it succeeded.


	/* Eventually, need to try to open the input file.
	*/
	input = fopen(inputFileName, "r");
	if (!input) {
		printf("Unable to open input file: %s\n", inputFileName);
		return EXIT_FAILURE;
	}
	else {
		/*
		buildBoardInitial(input,gridA,nrows,ncolumns);
		printBoard(gridA,nrows,ncolumns,0);
		centerBoard(input,inputFileName,gridA,nrows,ncolumns);
		printBoard(gridA,nrows,ncolumns,0);
		buildBoardInitial(input,gridB,nrows,ncolumns);
		printBoard(gridB,nrows,ncolumns,0);
		computeGeneration(gridA,gridB,nrows,ncolumns);
		printBoard(gridB,nrows,ncolumns,1);
		*/
		generateGame(input,nrows,ncolumns,inputFileName,doPrint,doPause,gens);
	}

	/*Once opened, you can read from the file one character at a time with fgetc().
	 * You can read one line at a time using fgets().
	 * You can read from standard input (the keyboard) with getchar().
	*/

	return EXIT_SUCCESS;
}

/** MAster function that organizes everything
@param input file stream
@param rows # of rows
@param columns # of cols
@param fileName location of file
@param doPrint print or no print
@param doPause pause or no pauseing
@param gens # of gens to go through 
*/
void generateGame(FILE* input,int rows,int columns,char* fileName, int doPrint, int doPause, int gens ) {

	//Three boards to be initialized
	char** boardA = make2Dchar(rows,columns);
	char** boardB = make2Dchar(rows,columns);
	char** boardC = make2Dchar(rows,columns);

	//Build the initial boards up
	buildBoardInitial(input,boardA,rows,columns);
	buildBoardInitial(input,boardB,rows,columns);
	buildBoardInitial(input,boardC,rows,columns);

	//Center the first board
	centerBoard(input, fileName, boardA, rows, columns);

	//set win condition
	int winCondition = 0;


	//Print 1st board
	printBoard(boardA,rows,columns,0);

	//Set which array to switch to
	int current_array = 0;


	/* loop invariant: current_array will never go beyond the three boards
	*/
	for(int current_gen=0; current_gen<gens;current_gen++){

		//Declare user input for pauseing
		char userInput=0;
		if(doPause==1) {
			printf("Enter y to continue");

			//Keep getting input until user enters 'y'
			do{

				scanf("%c",&userInput);

			}
			//Exit out of loop
			while(userInput!='y');
		}
		//Check if there is a win condition before doing next computation
		if(checkForWinCondition(boardA,boardB,boardC,rows,columns,current_gen,gens)) {

			//Get win condition
			winCondition = checkForWinCondition(boardA,boardB,boardC,rows,columns,current_gen,gens);
			//Exit loop
			current_gen=gens;
		}
		//Board A
		if((winCondition==0) && (current_array==0)) {

			//Compute next board
			computeGeneration(boardA,boardB,rows,columns);
			//Print if neccesary
			if(doPrint==1) {

				printBoard(boardB,rows,columns,current_gen+1);
			}
		}
		//Board B
		else if((winCondition==0) && (current_array==1)) {
			//Compute next board
			computeGeneration(boardB,boardC,rows,columns);
			//Print if neccesary
			if(doPrint==1) {

				printBoard(boardC,rows,columns,current_gen+1);
			}
		}
		//Board C
		if((winCondition==0) && (current_array==2)) {
			//Compute next board
			computeGeneration(boardC,boardA,rows,columns);
			//Print if neccesary
			if(doPrint==1) {

				printBoard(boardA,rows,columns,current_gen+1);
			}
		}
		//Set current_arrary back to boardA
		if(current_array<2) {

			current_array++;
		}
		else {

			current_array=0;
		}
	}

	printf("\n\n\nThe fine board is:\n");

	//Print proper final board
	if(current_array==0) {
		printBoard(boardA,rows,columns,gens);
	}
	else if(current_array ==1) {

		printBoard(boardB,rows,columns,gens);
	}
	else if( current_array ==2) {

		printBoard(boardC,rows,columns,gens);
	}




}
/**Check win conditions of current boards
*@param boardA 1st boardA
*@param boardB 2nd boardB
*@param boardC 3rd boardC
*@param rows # of rows
*@param columns # of columns
@param current_gen current generation of boardA
@param gen total gens to go through
*/
int checkForWinCondition(char** boardA,char** boardB, char** boardC,int rows,int columns,int current_gen, int gens) {
	if(checkBoardGenCount(boardA,current_gen,gens)) {

		return 1;
	}
	else if((checkBoardDeath(boardA,rows,columns)) ==0) {

		return 2;
	}
	else if((checkBoardSteadyState(boardA,boardB,rows,columns))) {
		return 3;
	}
	else if((checkBoardOscillates(boardA,boardB,boardC,rows,columns))) {
		return 4;
	}
	return 0;
}

/**Checks if the board oscillates
@param boardA 1st boardA
*@param boardB 2nd boardB
*@param boardC 3rd boardC
*@param rows # of rows
*@param columns # of columns
@return true or false
*/
int checkBoardOscillates(char** boardA, char** boardB,char** boardC, int rows, int columns) {

	if(checkBoardSteadyState(boardA,boardB,rows, columns)==0) {

		return checkBoardSteadyState(boardA,boardC);
	}
	return 0;
}
/**Checks if the board is in a steady state
@param boardA 1st boardA
*@param boardB 2nd boardB
*@param boardC 3rd boardC
*@param rows # of rows
*@param columns # of columns
@return true or false
*/
int checkBoardSteadyState(char** boardA, char** boardB, int rows, int columns) {


	//Get memory allocated for arrays
	char* current_row_boardA = malloc(columns * sizeof(char *));
	char* current_row_boardB = malloc(columns * sizeof(char *));

	//Loop-invariant: current_row_boardA and current_row_boardB will always contain boards A and B values
	for(int i =0;i<rows;i++) {

		//Set values for arrays
		current_row_boardA= boardA[i];
		current_row_boardB= boardB[i];

		for(int j = 0; j<columns;j++) {
			//Check if there is equality
			if(current_row_boardA[j]!= current_row_boardB[j]) {
				return 0;
			}
		}
	}
	return 1;
}
/**Checks if the board has gone through required generations
@param boardA 1st boardA
@param current_gen Curren gen the program is one
@param gen total gens to count
@return true or false
*/
int checkBoardGenCount(char** board, int current_gen, int gen) {
	return (current_gen==gen);
}
/**Checks if the board has life left
@param boardA 1st boardA
*@param rows # of rows
*@param columns # of columns
@return true or false
*/
int checkBoardDeath(char** board,int rows, int cols) {
	int organisms_left = 0;
	char* current_row =   malloc(cols * sizeof(char *));
	for(int i =0;i<rows;i++) {

		current_row=board[i];

		for(int j = 0; j<cols;j++) {

			if(current_row[j]=='x') {
				organisms_left++;
			}
		}
	}

	return (organisms_left>0);
}

/*Build the initial board by reading from file and assiging values in array to
*	from values in the file, if there aren't enough values in the file than are specificed
* in the command line arguments add 'o's to fill the difference
*/
/** Initialize boardA
@param file File to read from
@param board board to build on
@param rows # of rows
@param columns # of columns
*/
void buildBoardInitial(FILE* file, char** board, int rows,int columns) {

	//alllocate memory
	char* current_position =  malloc(columns * sizeof(char *));

	//Loop-invariant: go through array and initialze with 'o's
	for(int current_row=0; current_row < rows; current_row++) {
		//Set var to array row
		current_position = board[current_row];
		for(int current_col = 0; current_col < columns; current_col++) {

			current_position[current_col] = 'o';
		}
	}
}

//nrow/2 - f frow/2
/** Get file columns
@param file File stream to read from
@param fileName location of file
@return number of cols in file
*/
int getFileCol(FILE* file, char* fileName) {
	//File stream
	FILE* input = fopen(fileName, "r");
	//current columns
	int col_current= 0;

	//max columns so far
	int col_max= 0;
	//Char to use getc
	char c;

	//While we are still within the file
	while((c=getc(input)) != EOF) {
		if(c!='\n') {
			col_current++;
		}
		else {
			//Check to see if one is bigger
			if(col_current > col_max) {
				col_max=col_current;
			}
			col_current=0;
		}

	}
	fclose(input);
	return col_max;
}
/** Get row instead of cols
@param file get file Stream
@param fileName location of file
*/
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

/** Get total number of neighbors
 @param row # of row
 @param col # of col
 @param board board to look in
 @param rows # of rows
 @param cols # of cols
*/
int calculateNumNeighbors(int row, int col, char** board, int rows, int cols) {
	int total = 0;

	//Not edge case
	if(((row >0) && (row < rows-1)) && ((col < cols-1) && (col >0))) {
		if(board[row][col-1] =='x') {
			total++;
		}
		if(board[row][col+1] =='x') {
			total++;
		}
		if(board[row-1][col] =='x') {
			total++;
		}
		if(board[row+1][col] =='x') {
			total++;
		}
		if(board[row-1][col-1] =='x') {
			total++;
		}
		if(board[row-1][col+1] =='x') {
			total++;
		}
		if(board[row+1][col-1] =='x') {
			total++;
		}
		if(board[row+1][col+1] =='x') {
			total++;
		}
	}
	//Upper left corner
	else if((row==0) && (col==0)) {
		if(board[row+1][col]=='x') {
			total++;
		}
		if(board[row][col+1]=='x') {
			total++;
		}
 	}

	//Lower left corner
	else if((row=rows-1) && (col==0)) {
		if(board[row-1][col]=='x') {
			total++;
		}
		if(board[row][col+1]=='x') {
			total++;
		}
	}
	//Upper right corner
	else if((row==0) && (col==cols-1)) {
		if(board[row+1][col]=='x') {
			total++;
		}
		if(board[row][col-1]=='x') {
			total++;
		}
	}

	//Lower right corner
	else if((row=rows-1) && (col==cols-1)) {
		if(board[row-1][col]=='x') {
			total++;
		}
		if(board[row][col-1]=='x') {
			total++;
		}
	}
	//Left side
	else if(col==0) {
		if(board[row][col+1] =='x') {
			total++;
		}
		if(board[row-1][col]=='x') {
			total++;
		}
		if(board[row+1][col]=='x') {
			total++;
		}
	}
	//Right side
	else if(col==cols-1) {
		if(board[row][col-1] =='x') {
			total++;
		}
		if(board[row-1][col]=='x') {
			total++;
		}
		if(board[row+1][col]=='x') {
			total++;
		}
	}
	//Top side
	else if(row==0) {
		if(board[row][col+1] =='x') {
			total++;
		}
		if(board[row][col-1]=='x') {
			total++;
		}
		if(board[row+1][col]=='x') {
			total++;
		}
	}
	//Bottom side
	else if(row==rows-1) {
		if(board[row][col+1] =='x') {
			total++;
		}
		if(board[row][col-1]=='x') {
			total++;
		}
		if(board[row][col]=='x') {
			total++;
		}
	}
return total;
}

/** Compute next board and swap it
@param boardA first boardA
@param boardB 2nd board to copy onto
@param rows # of rows
@param cols # of cols
*/
void computeGeneration(char** boardA,char** boardB, int rows, int cols) {

	//memory allocation
	char* current_row_A=malloc(cols * sizeof(char *));
	char* current_row_B=malloc(cols * sizeof(char *));

	for(int i =0; i<rows; i++) {

		current_row_A= boardA[i];
		current_row_B= boardB[i];

		for(int j=0;j<cols;j++) {

			int neighbors =calculateNumNeighbors(i,j,boardA,rows,cols);

			if((current_row_A[j]=='o') && (neighbors==3)) {

				current_row_B[j] = 'x';
			}
			else if((current_row_A[j]=='x') && ((neighbors==2) || (neighbors==3))) {

				current_row_B[j] = 'x';
			}
			else if((current_row_A[j]=='x') && ((neighbors!=2) ||(neighbors!=3))) {
				current_row_B[j] = 'o';
			}


		}
	}
}

/** Center the original text design into board
@param file file stream
@param fileName location of file
@param board board to center
@param rows # of rows
@param cols # of cols
*/
void centerBoard(FILE* file, char* fileName, char** board, int rows, int cols) {
	//allocate memory
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
				if(c=='\n') {
					j=cols;
				}
				else if(c=='x' || c=='o') {
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

//Iterate through arrray and print it out

/**Print through arrays
@param board board to print
@param nrows # of rows
@param ncolumns # of cols
@param gen gen to display
 */
void printBoard(char** board, int nrows, int ncolumns, int gen) {

	printf("\t\tCURRENT GEN: %d\n",gen);
	char* current =  malloc(ncolumns * sizeof(char *));
  for(int i = 0; i < nrows; i++) {
		current = board[i];

    for(int j=0; j < ncolumns; j++) {
      if(current[j]=='x') {
				printf("x ");
			}
			else {
				printf("  ");
			}
    }
    printf("\n");
  }
	printf("\n\n\n");
}
