#include <stdio.h>
#include <math.h>

#include "../include/I_WonnaBeAMathematician.h"
#include "../include/UserInterface.h"
#include "../include/errors.h"

// TODO: read about argc argv

void TestSolveEquation();

int main() {
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
		return 0;
	}
	else {
		return 1;
	}
}




