#include <stdio.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {
	struct Employee *e;

	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	//Initialize random with a new seed
	seedRand();
	struct Employee *randomEmployee;
	randomEmployee = makeRandomEmployee();
	//Test premade employee
	printEmployee(e);
	printf("\n");
	//Test printing random employee
	printEmployee(randomEmployee);

	//Create an array of random employees
	struct Employee **employees = makeArrayEmployees(10);

	//Print out random employees
	printEmployees(employees,10);
	//Create  shallow employees
	struct Employee **new_employees = duplicateEmployees(employees,10);
	printf("\n");
	//Print out shallow employees
	printEmployees(new_employees,10);


	//Create another set of shallow employees
	struct Employee **shallow_employees = duplicateEmployees(employees,10);
	//Print out pre-copy 1st employee's birth year
	printf("\nEmployee #1 original birth year: %d\n",employees[0]->birth_year);
	//Change the employees birth year by 1
	changeBirthYear(shallow_employees[0]);

	//Show any changes, shallow copy should edit both itself and the array it points to
	printf("\nEmployee #1 shallow copy after birth year change: %d\n",shallow_employees[0]->birth_year);
	printf("\nEmployee #1 original after  birth year change: %d\n",employees[0]->birth_year);


	//Create deep copy
	struct Employee **deep_employees = deepCopyEmployees(employees,10);

	//Show original vallue
	printf("\nEmployee #1 deep copy birth year: %d\n",deep_employees[0]->birth_year);
	//Change employee values
	changeBirthYear(deep_employees[0]);
	//Deep copy should only edit itself as it copies the elements and not the pointers
	printf("\nEmployee #1 deep copy after birth year change: %d\n",deep_employees[0]->birth_year);
	printf("\nEmployee #1 original after birth year change: %d\n",employees[0]->birth_year);

	//Free employees
	freeEmployees(new_employees,10);

	return 0;
}
