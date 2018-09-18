#include <stdio.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {
	struct Employee *e;

	e = makeEmployee(1952, 1999, "Mike Ciaraldi");

	struct Employee *randomEmployee;
	randomEmployee = makeRandomEmployee();

	printEmployee(e);
	printf("\n");
	printEmployee(randomEmployee);

	struct Employee *employees = makeArrayEmployees(10);
	printEmployees(employees,10);

	struct Employee *new_employees = duplicateEmployees(employees,10);
	printf("\n");
	//printEmployees(new_employees,10);
	return 0;
}
