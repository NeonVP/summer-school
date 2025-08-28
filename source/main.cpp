#include <stdio.h>
#include <math.h>
#include <string.h>

#include "../include/I_WonnaBeAMathematician.h"
#include "../include/UserInterface.h"
#include "../include/AllTestsInOne.h"

// TODO: add Help Mode

enum Modes {
	HELP = 104,
	STANDART = 115,
	TEST = 116
};

int StdMode();
int TestMode();
int HelpMode();

int main(int argc, char* argv[]) {
	meow_cat();
	if (argc == 1) {
		return StdMode();
	}
	else {
		switch (argv[1][1]) {
			case HELP:
				return HelpMode();
			case STANDART:
				return StdMode();
			case TEST:
				return TestMode();
			default:
				printf("");
				return 0;
		}
	}
}


int StdMode() {
	NameOfProgrammAndAuthor();

	Errors err = ERR_NONE;
	Coefficients coefs = {.coef_a = NAN, .coef_b = NAN, .coef_c = NAN};
	EquationRoots roots = {.x1 = NAN, .x2 = NAN};

	err = Input(&coefs);
	IsERR_NONE(err)

	err = SolveEquation(&coefs, &roots);
	IsERR_NONE(err)

	err = OutputRoots(&roots);
	IsERR_NONE(err)

	printf(
		   "    /\\___/\\                                           \n"
           "   /       \\                                           \n"
           "  l  u   u  l                                           \n"
           "--l----*----l--                                         \n"
           "   \\   w   /      - Meow! Thanks for using my produnct. \n"
           "     ======       - for Developer: GIT COMMIT and PUSH  \n"
           "   /       \\ __                                        \n"
           "   l        l\\ \\                                      \n"
           "   l        l/ /   -Vladimir Pyshkin-                   \n"
           "   l  l l   l /                                         \n"
           "    \\ ml lm /_/                                        \n"
           );
	return 0;
}


int TestMode() {
	printf(GRID "Включен тест мод.\n");
	Errors err = ERR_NONE;

	err = TestSolveEquation();
	IsERR_NONE(err)

	printf("\n");

	err = TestComparison();
	IsERR_NONE(err)

	return 0;
}

int HelpMode() {


	return 0;
}
