/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"


/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup1(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = strlen(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}


/** Calculates the length of a string, not including null character '\0'
 * This version iterates through the char array via array subscripting
 * @param  s Pointer to string to calculate length of
 * @return size_t Size of the string
 */
 size_t mystrlen1(const char *s) {


	 size_t str_length =0;

	 for(int i =0; s[i]!='\0';i++) {
		 str_length++;
	 }

	 return str_length;
 }
/** Calculates the length of a string, not including null character '\0'
 * via poiner arithmatic
 * @param  s Pointer to string to calculate length of
 * @return size_t Size of the string
 */
 size_t mystrlen2(const char *s) {

	 const char *string_pointer = s;
	 size_t str_length = 0;

	 while(*string_pointer != '\0') {
		 str_length++;
		 string_pointer++;
	 }

	 return str_length;
 }


