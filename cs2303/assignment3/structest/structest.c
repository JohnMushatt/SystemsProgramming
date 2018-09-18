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
	return 0;
}
