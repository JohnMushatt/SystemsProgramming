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

  length = mystrlen1(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}
/**Copy src string into target string and return a pointer to target
 * @param target Pointer to target string to copy to
 * @param src Pointer to src string to copy from
 * @return Pointer to newly copied-to target
 */

char* mystrcpy1(char *dest, const char *src) {

	char *dest_char = dest;
	const char *src_char = src;

	for(; *src_char != '\0';src_char++) {

		*dest_char = *src_char;
		dest_char++;

	}
	*dest_char = '\0';

	return dest;



}

/**Copies n # of bytes from src to dest, adding null terminators if mystrlen2(src) < n
 * @param dest Destination of string to copy to from src
 * @param src Source to copy from
 * @param n # of bytes to copy
 * @return Pointer to destination after copy
 */
char* mystrncpy1(char *dest, const char *src, size_t n) {

	char *dest_char = dest;
	const char *src_char = src;
	size_t counter = 0;
	for(; *src_char != '\0' && (counter <=n);src_char++) {

		*dest_char = *src_char;
		dest_char++;
		counter++;
	}
	if(counter<=n) {
		for(;counter<=n;counter++) {
			*dest_char = '\0';
		}
	}
	return dest;
}
/** Concatenates two strings together
 * @param dest Pointer to destination string
 * @param src Pointer to src string
 * @return Pointer to destination string after src is concatenated into dest
 */
char* mystrcat1(char *dest,const char *src) {
	char* c = dest + mystrlen2(dest);

	while(*src!='\0') {
		*c++=*src++;

	}
	*c='\0';
	return dest;
}

/** Concatenates n bytes of src string to dest string, adding null terminator at the end
 * @param dest Destination string to concatenate to from src
 * @param src Source to concatenate from
 * @return pointer to destination after concatenation
 */
char* mystrncat1(char *dest, const char *src, size_t n) {

	char* c = dest + mystrlen2(dest);
	size_t counter =0;
		while(*src!='\0' && counter < n) {
			*c++=*src++;
			counter++;

		}
		*c='\0';
		return dest;
}
/** Copies input string and returns the copied version
 * @param src Pointer to input string
 * @return Pointer to new string containing char elements of the src string as a copy,
 *         or null if not enough memory
 */

char* mystrdup2(const char* src) {

	int length;

	char* copied_string;

	length = mystrlen2(src) +1;

	copied_string = (char*) malloc (length);

	if(copied_string == 0) {
		return (char *) 0;
	}
	else {
		strcpy(copied_string,src);
		return copied_string;
	}

}
/**Duplicate n bytes of from src into a new string holding the right amount of memory
 *@param src Pointer to source string to duplicate from
 *@param n Number of bytes to duplicate
 *@return Pointer to new string containing duplicated string and n number of bytes
 */
char* mystrndup1(const char* src, size_t n) {
	int length; // Length of the source string
	char* newstr; // Pointer to memory which will hold new string

	length = mystrlen1(src) + 1;  // Leave space for the terminator
	newstr = (char*) malloc(length); // Must cast!

	// If no memory was available, return null pointer immediately
	if (newstr == 0) return (char *) 0;

	// Otherwise, copy the string and return pointer to new string
	mystrncpy1(newstr, src,n);
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


