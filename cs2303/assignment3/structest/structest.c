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

	struct Employee **employees = makeArrayEmployees(10);
	printEmployees(employees,10);

	struct Employee **new_employees = duplicateEmployees(employees,10);
	printf("\n");
	printEmployees(new_employees,10);

	struct Employee **shallow_employees = duplicateEmployees(employees,10);
	printf("\nEmployee #1 original birth year: %d\n",employees[0]->birth_year);
	changeBirthYear(shallow_employees[0]);

	printf("\nEmployee #1 shallow copy after birth year change: %d\n",shallow_employees[0]->birth_year);
	printf("\nEmployee #1 original after  birth year change: %d\n",employees[0]->birth_year);

	struct Employee **deep_employees = deepCopyEmployees(employees,10);

	printf("\nEmployee #1 deep copy birth year: %d\n",deep_employees[0]->birth_year);
	changeBirthYear(deep_employees[0]);
	printf("\nEmployee #1 deep copy after birth year change: %d\n",deep_employees[0]->birth_year);
	printf("\nEmployee #1 original after birth year change: %d\n",employees[0]->birth_year);


	freeEmployees(new_employees,10);

	return 0;
}
