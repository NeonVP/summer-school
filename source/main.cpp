#include <stdio.h>
#include <math.h>
#include <string.h>

#include "../include/I_WonnaBeAMathematician.h"
#include "../include/UserInterface.h"
#include "../include/AllTestsInOne.h"

int StdMode();

// TODO: read about argc argv

int main(int argc, char* argv[]) {
	if ((argc == 1) || (argc > 1 && !strcmp(argv[1], "-std"))) {
		return StdMode();
	}
	else {
		if (!strcmp(argv[1], "-t")) {
			return TestMode();
		}
	}
}

int StdMode() {
	printf("MOEW\n");
	NameOfProgrammAndAuthor();

	Errors err = ERR_NONE;
	Coefficients coefs = {NAN, NAN, NAN};
	EquationRoots roots = {NAN, NAN};

	err = Input(&coefs);

	if (err == ERR_NONE) {
		err = SolveEquation(&coefs, &roots);
	}
	else {
		return 1;
	}

	if (err == ERR_NONE) {
		err = OutputRoots(&roots);
	}
	else {
		return 1;
	}

	if (err == ERR_NONE) {
		printf("uwu\nCOMMIT GITHUB");
		return 0;
	}
	else {
		return 1;
	}
}