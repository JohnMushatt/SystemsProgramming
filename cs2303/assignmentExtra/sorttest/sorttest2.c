#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>
/* Program which reads numbers from the command line,
 * outputs them, sorts them in descending order, and outputs the sorted list.
 *
 * Usage:
 *         ./sorttest some_number another_number ...
 * Example:
 *         ./sorttest 2014 15 7000
 *
 */

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main (int argc, const char* argv[]) {

  int *nums; // space to store numbers entered from the command line.

  int i; // array index 
  int num_nums; // How many numbers actually entered on the command line.
  int count;
  int sortToUse;
  // Check that there is as least 1 number
  num_nums = argc - 1;
  if (num_nums < 2) {
    printf("Must enter at least 2 numbers! Exiting.\n");
    return 1; // Indicate failure
  }
  count = atoi(argv[1]);
  sortToUse=atoi(argv[2]);
  nums = (int*) calloc(count, sizeof(int));
  /* Read all the numbers from the command line and put them into the array */
  for (i = 0; i < count; i++) {
    nums[i] = rand()%count; // store into the array
  }
  // Now print, sort, and print the array, and time how long the sorting took.
  timesort(nums, count,sortToUse);

  return 0; // Indicate success!
}
