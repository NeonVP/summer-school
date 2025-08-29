#include <stdio.h>
#include <math.h>
#include <string.h>

#include "../include/I_WonnaBeAMathematician.h"
#include "../include/UserInterface.h"
#include "../include/AllTestsInOne.h"

enum Modes {
	HELP     = 104,
	STANDART = 115,
	TEST     = 116
};

int StdMode();
int TestMode();
int HelpMode();

int main(int argc, char* argv[]) {
	if (argc == 1) {
		meow_cat();
		return StdMode();
	}
	else {
		switch (argv[1][1]) {
			case HELP:
				return HelpMode();
			case STANDART:
				meow_cat();
				return StdMode();
			case TEST:
				meow_cat();
				return TestMode();
			default:
				printf("Type\n");
				return 1;
		}
	}
}


int StdMode() {
	NameOfProgrammAndAuthor();

	Errors err = ERR_NONE;
	Coefficients  coefs = {.coef_a = NAN, .coef_b = NAN, .coef_c = NAN};
	EquationRoots roots = {.x1 = NAN, .x2 = NAN};

	err = Input(&coefs);
	IsERR_NONE(err)

	err = SolveEquation (&coefs, &roots);~
	IsERR_NONE(err)

	err = OutputRoots (&roots);
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
	printf( COLOR_GREEN
		   "     /\\     /\\                 \n"
           "    {  `---'  }                  \n"
           "    {  O   O  }                  \n"
           "    ~~>  V  <~~                  \n"
           "     \\  \\|/  /                 \n"
           "      `-----'__                  \n"
           "      /     \\  `^\\_            \n"
           "     {       }\\ |\\_\\_   W     \n"
           "     |  \\_/  |/ /  \\_\\_( )    \n"
           "      \\__/  /(_E     \\__/      \n"
           "    	(  /                     \n"
           "         MM                      \n"
             COLOR_RESET );

	printf(GRID COLOR_CYAN "My Last Brain Cell During a Math Test\n" COLOR_RESET);


	const char *list_of_commands[][2] = {
		{"-s", "Standart Mode"},
		{"-t", "Test Mode"},
		{"-h", "Help Mode"}
	};
	for (int i = 0; i < 3; i++) {
		printf(GRID COLOR_YELLOW"%s :" COLOR_BLUE "%s\n" COLOR_RESET, list_of_commands[i][0], list_of_commands[i][1]);
	}
	return 0;
}
