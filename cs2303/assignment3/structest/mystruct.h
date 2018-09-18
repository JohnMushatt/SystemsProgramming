/** mystruct.h
 * @author Mike Ciaraldi
 * Sample structs
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee *makeEmployee(int birth, int startq, const char* name);
struct Employee *makeRandomEmployee();
struct Employee **makeArrayEmployees(size_t n);
void printEmployee(struct Employee *e);
char getRandomLowerLetter();
char getRandomUpperLetter();
int getRandomInt();
int getRandomNameLength();
char* getRandomName();
