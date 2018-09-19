/** mystruct.c
 * @author Mike Ciaraldi
*/


#include <string.h>
#include <stdlib.h>
#include "mystruct.h"
#include <stdio.h>
#include <time.h>
/** Allocates an Employee struct and fills in its fields
 * @param birth Year the emploee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee *makeEmployee(int birth, int start, const char *name) {

	//Allocate memory for employee
	struct Employee *employee = malloc(sizeof (struct Employee));
	//Assign birth year
	employee->birth_year=birth;

	//Assign start year
	employee->start_year=start;

	//Assign name
	strcpy(employee->name,name);

	//Return pointer to employee
	return employee;
}
/**Creates array of employees
 *@param n Size to make
 *@return Pointer to new struct
 */
struct Employee **makeArrayEmployees(size_t n) {

	//Allocate memory for array of employees
	struct Employee **employees = malloc(n * sizeof(struct Employee *));

	//Build array of employees
	for(size_t i = 0; i < n; i++) {
			*(employees + i) = makeRandomEmployee();
	}
	//return pointer to employees
	return employees;

}
/**Create a random employ with random info
 *@return Pointer to struct
 */
struct Employee *makeRandomEmployee() {

	//Allcoate memory
	struct Employee *employee = malloc(sizeof (struct Employee ));

	//Birth Year
	employee->birth_year=getRandomInt();

	//Start year
	employee->start_year=getRandomInt();

	//Name
	char* name = getRandomName();

	//Assign name
	strcpy(employee->name,name);

	//Return pointer to employee
	return employee;
}
/**Changes the birth year of an employee
 * @param e Pointer to an employee
 */
void changeBirthYear(struct Employee *e) {

	//increment the birth year by 1
	e->birth_year++;
}
/**Shallow copy of new array of employees
 *@param e Pointer to array of employees
 *@param  n size of employees to duplicate
 *@return Pointer to array of new employees
 */
struct Employee **duplicateEmployees(struct Employee **e, size_t n) {

	//Allocate memory
	struct Employee **employee_final = malloc(sizeof(struct Employee *)*n);

	//Loop through and shallow copy via copying the pointers
	for(size_t i = 0; i < n; i++) {

		employee_final[i] = e[i];
	}

	//Return pointer to newly duplicated array
	return employee_final;
}
/**Deep Copy of employees
 *@param e Pointer to array of employees
 *@param n # of employees to copy
 *@return Pointer to newly deep copied array
 */
struct Employee **deepCopyEmployees(struct Employee **e, size_t n) {

	//Allocate memory
	struct Employee **new_employees = malloc(n * sizeof(struct Employee *));

	//Loop through and deep copy
	for(size_t i = 0; i < n; i++) {

		//Allocate memory
		new_employees[i] = malloc(sizeof(struct Employee ));

		//Assign birth year
		new_employees[i]->birth_year = e[i]->birth_year;

		//Assign start year
		new_employees[i]->start_year = e[i]->start_year;

		//Assign name
		strcpy(new_employees[i]->name,e[i]->name);

	}
	//Return pointer to newly deep copied array
	return new_employees;
}
/**Frees memory from each employee and then the array holding the employees
 * @param e Pointer pointing to an array holding pointers of employees
 * @param n # of employees to free
 */
void freeEmployees(struct Employee **e, size_t n) {

	//Loop through employees
	for(int i=0; i<n; i++) {

		//Free memory of employee
		free(e[i]);
	}
	//free array
	free(e);
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

	//Return randomly generated name
	return name;
}

/**Print employees
 *@param e Pointer to array of employees
 *@param n Number of employees to print
 */
void printEmployees(struct Employee **e,size_t n) {
	//Allcoate memory
	for(size_t i =0; i < n;i++) {

		printf("Name: %s Start Year: %d Birth Year: %d\n",e[i]->name,e[i]->start_year,e[i]->birth_year);

	}
}
/**Print single employee
 * @param e Pointer to employee
 *
 */
void printEmployee(struct Employee *e) {

	printf("Name: %s Start Year: %d Birth Year: %d\n\n",e->name,e->start_year,e->birth_year);
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
/**Seeds the random function
 *
 */
void seedRand() {
	time_t t;
	unsigned int seed = time(&t);
	srand(seed);
}
