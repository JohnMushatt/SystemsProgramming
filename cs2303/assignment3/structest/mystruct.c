/** mystruct.c
 * @author Mike Ciaraldi
*/


#include <string.h>
#include <stdlib.h>
#include "mystruct.h"
#include <stdio.h>
/** Allocates an Employee struct and fills in its fields
 * @param birth Year the emploee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee *makeEmployee(int birth, int start, const char *name) {

	struct Employee *employee = malloc(sizeof *employee);
	employee->birth_year=birth;
	employee->start_year=start;
	strcpy(employee->name,name);

	return employee;
}
/**Creates array of employees
 *@param n Size to make
 *@param @return Pointer to new struct
 */
struct Employee *makeArrayEmployees(size_t n) {
	//Allcoate memory
	struct Employee *e = malloc(n * sizeof(struct Employee *));
	//Allcoate memory
	struct Employee *e_temp = malloc(n * sizeof(struct Employee *));
	//Assignt to keep accuray
	e_temp = e;
	for(size_t i = 0; i < n; i++) {
		*e_temp = *makeRandomEmployee();
		e_temp++;
	}
	return e;
}
/**Create a random employ with random info
 *@return Pointer to struct
 */
struct Employee *makeRandomEmployee() {
	//Allcoate memory
	struct Employee *employee = malloc(sizeof *employee);
	//Birth Year
	employee->birth_year=getRandomInt();
	//Start year
	employee->start_year=getRandomInt();
	//Name
	char* name = getRandomName();
	strcpy(employee->name,name);

	return employee;
}

/**Shallow copy of new array of employees
 *@param e Pointer to array of employees
 *@param  n size of employees to duplicate
 *@return Pointer to array of new employees
 */
struct Employee *duplicateEmployees(struct Employee *e,size_t n) {


	//Allcoate memory
	//struct Employee *new_e = (struct Employee *)malloc(n * sizeof(struct Employee *));

	//struct Employee *new_e_temp = malloc(size * sizeof(struct Employee *));

	//struct Employee *employees = malloc(size * sizeof(struct Employee *));

	//employees=e;
	//new_e_temp = new_e;

	//for(int i = 0; i < n;i++) {

		//new_e = e[i];
	//}
	return 0;
}
/**Generate a random name
 *@return Return a random name
 */
char* getRandomName() {

	//Name length
	int length = getRandomNameLength();
	//Acurray holders
	char *name, *temp_Name;
	//Assign accuracy holds memory
	temp_Name= name= malloc(length *(sizeof (char*)) +1);

	for(int i=0;i<length;i++) {
		if(i==0) {
			*temp_Name++ = getRandomUpperLetter();
		}
		else {
			*temp_Name++ = getRandomLowerLetter();
		}
	}
	//Add null terminator
	*temp_Name='\0';
	return name;
}

/**Print employees
 *@param e Pointer to array of employees
 *@param n Number of employees to print
 */
void printEmployees(struct Employee *e,size_t n) {
	//Allcoate memory
	struct Employee *employee = malloc(sizeof(struct Employee*));
	for(size_t i =0; i < n;i++) {
		*employee=*e++;
		printf("Name: %s Start Year: %d Birth Year: %d\n",employee->name,employee->start_year,employee->birth_year);
	}
}
/**Print single employee
 * @param e Pointer to employee
 *
 */
void printEmployee(struct Employee *e) {

	printf("Name: %s Start Year: %d Birth Year: %d\n",e->name,e->start_year,e->birth_year);
}

/**Generate random lower case letter
 *@return A lower case letter
 */
char getRandomLowerLetter(){

	return  (rand() % 27) + 97;

}
/**Generate an upper case letter
 *@return An upper case letter
 */
char getRandomUpperLetter(){

	return  (rand() % 27) + 65;

}
/**Generate a random year from 1-9999
 *@return a year from 1 - 9999
 */
int getRandomInt(){

	return  (rand() %9999)+1;

}
/**Generate a random name length
 *@return random name length 1-11
 */
int getRandomNameLength(){

	return  (rand()%11+1);

}
