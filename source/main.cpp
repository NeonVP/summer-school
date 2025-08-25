#include <stdio.h>
#include <math.h>

#include "../include/common.h"
#include "../include/I_WonnaBeAMathematician.h"
#include "../include/UserInterface.h"
#include "../include/In_Output.h"

// TODO: add test func for 1 example
// TODO: add more files DONE
// TODO: read about argc argv

void TestSolveEquation();

int main() {
	NameOfProgrammAndAuthor();
	Errors err = Err_NONE;
	Coefficients coefs = {NAN, NAN, NAN};
	EquationRoots roots = {NAN, NAN};
	Input(&coefs);
	SolveEquation(&coefs, &roots, &err);

	if (err == Err_NONE) {
		OutputRoots(&roots, &err);
		if (err == Err_NONE) {
			return 0;
		}
		else {
			return 1;
		}
	}
	return 1;
}

// int main() {
// 	TestSolveEquation();
//
// 	return 0;
// }



