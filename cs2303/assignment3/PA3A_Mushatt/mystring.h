/** mystring.h
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

// Function prototype(s):
char* mystrdup1(const char* src);
char* mystrdup2(const char* src);
char* mystrndup1(const char *src, size_t n);
char* mystrcpy1(char *dest, const char *src);
char* mystrncpy1(char *dest, const char *src, size_t n);
char* mystrcat1(char *dest, const char *src);
char* mystrncat1(char *dest, const char *src, size_t n);
size_t mystrlen1(const char *s);
size_t mystrlen2(const char *s);

