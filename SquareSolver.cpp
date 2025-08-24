#include <assert.h>
#include <stdio.h>
#include <math.h>

// read about dynamic memory and calloc, realloc, malloc
enum cntRoots
{
	INF = 3,
	ZERO = 0, 
	ONE = 1, 
	TWO = 2,
	UnknownErr = 999
};

const char* ListCntRoots[4] = {"ZERO", "ONE", "TWO", "INF"};

enum CompWithNull
{
	ABOVE = 1,
	EQUAL = 0,
	BELLOW = -1
};

/*-------COLORS-------*/
#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

const float EPS = 1e-10f;

cntRoots SolveEquation(double *coefs, double *roots);
cntRoots linear_equation(double *x1, double b, double c);
cntRoots square_equation(double *coefs, double *roots);

CompWithNull CompareDoubleNull(double n);

void NameOfProgrammAndAuthor();

void Input(double *coefs);
int OutputRoots(cntRoots nRoots, double *roots);

void ClearBuffer();

void TestSolveEquation();

int main() {
	NameOfProgrammAndAuthor();

	printf("Enter coefficients of square equation: ");
	double coefs[3] = {};
	double roots[2] = {};
	Input(coefs);
	cntRoots nRoots = SolveEquation(coefs, roots);
	OutputRoots(nRoots, roots);
	return 0;
}

// int main() {
// 	TestSolveEquation();
//
// 	return 0;
// }


cntRoots SolveEquation(double *coefs, double *roots) {
	assert(coefs != NULL);
	assert(roots != NULL);
	assert(isfinite (coefs[0]));
	assert(isfinite (coefs[1]));
	assert(isfinite (coefs[2]));

	if (CompareDoubleNull(coefs[0]) == EQUAL) {
		return linear_equation(&(roots[0]), coefs[1], coefs[2]);
	}
	else {
		return square_equation(coefs, roots);
	}
}


cntRoots linear_equation(double *x1, double b, double c) {
	assert(isfinite (b));
	assert(isfinite (c));
	assert(x1 != NULL);

	if (CompareDoubleNull(b) == EQUAL) {
		if (CompareDoubleNull(c) == EQUAL) {
			return INF;
		}
		else {
			return ZERO;
		}
	}
	else {
		printf("This is not a square equation, but a linear one.\n");
		*x1 = - (c / b);

		return ONE;
	}
}


cntRoots square_equation(double *coefs, double *roots) {
	assert(coefs != NULL);
	assert(roots != NULL);
	assert(isfinite (coefs[0]));
	assert(isfinite (coefs[1]));
	assert(isfinite (coefs[2]));

	if (CompareDoubleNull(coefs[2]) == EQUAL) {
		roots[0] = 0;
		linear_equation(&(roots[1]), coefs[0], coefs[1]);	// call linear_equation		ax+b=0

		return TWO;
	}
	else {
		double disc = coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];

		switch (CompareDoubleNull(disc)) {
			case EQUAL:
				roots[0] = - (coefs[1] / (2 * coefs[0]));
				return ONE;
			case ABOVE:
				roots[0] = (-coefs[1] - sqrt(disc)) / (2 * coefs[0]);
				roots[1] = (-coefs[1] + sqrt(disc)) / (2 * coefs[0]);
				return TWO;
			case BELLOW:
				return ZERO;
			default:
				return UnknownErr;
		}
	}
}


CompWithNull CompareDoubleNull(double n) {  //
	if (n > EPS) {
		return ABOVE;
	}
	else if (abs(n) < EPS) {
		return EQUAL;
	}
	else {
		return BELLOW;
	}

}

void NameOfProgrammAndAuthor() {
	printf(	COLOR_CYAN
			"##############################\n"
			"#   Square equation solver   #\n"
			"#         (c) NeonVP, 2025   #\n"
			"##############################\n\n"
			COLOR_RESET );
}

void ClearBuffer() {
	while (getchar() != EOF) {}
}

void Input(double *coefs) {
	while (scanf("%lg %lg %lg", &coefs[0], &coefs[1], &coefs[2]) != 3) {
		ClearBuffer();
		printf("Incorrect Input. Try again, please.\n"
		  "Enter coefficients of square equation: ");
	}
} 


void OutputRoots(cntRoots nRoots, double *roots) {  //
	switch (nRoots){
		case INF:
			printf("The equation has an infinity number of roots.\n");
		case ZERO:
			printf("There are no roots.\n");
		case ONE:
			printf("There is 1 roots: %lg.\n", roots[0]);
		case TWO:
			printf("There is 2 roots: %lg and %lg.\n", roots[0], roots[1]);
		default:
			printf("!!! Error !!!\n Unknown number of solutions. \n");
	}
}


/* TODO: colors for tests, debug unitests, read about structures */
void TestSolveEquation() {
	double tests[8][2][3] =
		{
		{{1, -5, 6}, {2, 3}},
		{{1, -4, 4}, {2, 0}},
		{{1, 2, 5}, {0, 0}},
		{{0, 2, -4}, {2, 0}},
		{{4, 0, -16}, {-2, 2}},
		{{2, -6, 0}, {0, 3}},
		{{0, 0, 0}, {0, 0}},
		{{0, 0, 5}, {0, 0}}
		};

	cntRoots tests_nRoots[8] = {TWO, ONE, ZERO, ONE, TWO, TWO, INF, ZERO};

	for (int i = 0; i < 8; i++) {
		double roots[2] = {};
		cntRoots nRoots = SolveEquation(tests[i][0], roots);

		if (!(nRoots == tests_nRoots[i] && roots[0] == tests[i][1][0] && roots[1] == tests[i][1][1])) {
			printf(COLOR_RED "FAILED: SolveEquation(%lf, %lf, %lf, ...) -> %s, x1 = %lf, x2 = %lf (should be x1 = %lf, x2 = %lf, %s)\n" COLOR_RESET,
				   tests[i][0][0], tests[i][0][1], tests[i][0][2],
				   ListCntRoots[nRoots],
				   roots[0], roots[1],
				   tests[i][1][0], tests[i][1][1], ListCntRoots[tests_nRoots[i]]);
		}
		else {
			printf(COLOR_GREEN "OK: SolveEquation(%lf, %lf, %lf, ...) -> %s, x1 = %lf, x2 = %lf (should be x1 = %lf, x2 = %lf, %s)\n" COLOR_RESET,
				   tests[i][0][0], tests[i][0][1], tests[i][0][2],
				   ListCntRoots[nRoots],
				   roots[0], roots[1],
				   tests[i][1][0], tests[i][1][1], ListCntRoots[tests_nRoots[i]]);
		}
	}
}
