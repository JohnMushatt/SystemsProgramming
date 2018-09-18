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
/**
 *
 */
struct Employee **makeArrayEmployees(size_t n) {
	struct Employee **employees, **employees_temp;
	employees_temp = employees = malloc(n *(sizeof *employees));

	for(size_t i = 0;i<n;i++) {
		struct Employee *employee= makeRandomEmployee();
		*employees_temp = employee;
	}
	free(employees_temp);

	return employees;
}
/**
 *
 */
struct Employee *makeRandomEmployee() {
	struct Employee *employee = malloc(sizeof *employee);
	employee->birth_year=getRandomInt();
	employee->start_year=getRandomInt();
	char* name = getRandomName();
	strcpy(employee->name,name);

	return employee;
}
/**
 *
 */
char* getRandomName() {

	int length = getRandomNameLength();
	char *name, *temp_Name;
	temp_Name= name= malloc(length *(sizeof (char*)) +1);

	for(int i=0;i<length;i++) {
		if(i==0) {
			*temp_Name++ = getRandomUpperLetter();
		}
		else {
			*temp_Name++ = getRandomLowerLetter();
		}
	}
	*temp_Name='\0';
	free(temp_Name);
	return name;
}
/**
 *
 */
void printEmployee(struct Employee *e) {

	printf("Name: %s Start Year: %d Birth Year: %d\n",e->name,e->start_year,e->birth_year);
}

/**
 *
 */
char getRandomLowerLetter(){

	return  (rand() % 27) + 97;

}
/**
 *
 */
char getRandomUpperLetter(){

	return  (rand() % 27) + 65;

}
/**
 *
 */
int getRandomInt(){

	return  (rand() %9999)+1;

}
/**
 *
 */
int getRandomNameLength(){

	return  (rand()%11);

}
