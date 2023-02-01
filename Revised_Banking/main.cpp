#include "control.h"

/*
things to do:
-deposit and withraw
-DOB
-PIN
-Checking and Savings
-Admin and user interface(require PIN)

CREATE INDIVIDUAL SETTERS
*/

Control controller;

int main()

{
	controller.login();

	while (controller.checkRunning())
	{
		controller.mainMenu();

	}

	printf("Program has closed!\n");
	system("PAUSE");
	return 0;
}