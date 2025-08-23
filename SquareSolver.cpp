#include <assert.h>
#include <stdio.h>
#include <math.h>

// read about dynamic memory and calloc, realloc, malloc
enum cntRoots
{
	INF = -1,
	ZERO = 0, 
	ONE = 1, 
	TWO = 2
};

enum CompWithNull
{
	ABOVE = 1,
	EQUAL = 0,
	BELLOW = -1
};

const float EPS = 1e-10f;

cntRoots SolveEquation(double *coefs, double *roots);
cntRoots linear_equation(double *x1, double b, double c);
cntRoots square_equation(double *roots, double *coefs);

CompWithNull CompareDoubleNull(double n);

void NameOfProgrammAndAuthor();

int Input(double *coefs);
int OutputRoots(cntRoots nRoots, double *roots);

bool ClearBuffer();

void TestSolveEquation();
const char* cntRoots_to_str(cntRoots string);

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


cntRoots SolveEquation(double *coefs, double *roots) {
	assert(isfinite (coefs[0]));
	assert(isfinite (coefs[1]));
	assert(isfinite (coefs[2]));
	assert(roots != NULL);

	if (CompWithNull(coefs[0]) == EQUAL) {
		if (CompWithNull(coefs[1]) == EQUAL) {
			if (CompWithNull(coefs[2]) == EQUAL) {
				return INF;
			}
			else {
				return ZERO;
			}
		}
		else {
			return linear_equation(&(roots[0]), coefs[1], coefs[2]);
		}
	}
	else {
		return square_equation(roots, coefs);
	}
}


cntRoots linear_equation(double *x1, double b, double c) {
	assert(isfinite (b));
	assert(isfinite (c));
	assert(x1 != NULL);

	printf("This is not a square equation, but a linear one.\n");
	*x1 = - (c / b);

	return ONE;
}


cntRoots square_equation(double *roots, double *coefs) {
	assert(isfinite (coefs[0]));
	assert(isfinite (coefs[1]));
	assert(isfinite (coefs[2]));
	assert(roots != NULL);

	if (CompWithNull(coefs[2]) == EQUAL) {
		roots[0] = 0;
		linear_equation(&(roots[1]), coefs[0], coefs[1]);	// call linear_equation		ax+b=0

		return TWO;
	}
	else {
		double disc = coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];

		if (CompWithNull(disc) == EQUAL) {
			roots[0] = - (coefs[1] / (2 * coefs[0]));

			return ONE;
		}
		else if (disc > 0) {			// add func for compare double and null
			roots[0] = (-coefs[1] - sqrt(disc)) / (2 * coefs[0]);
			roots[1] = (-coefs[1] + sqrt(disc)) / (2 * coefs[0]);

			return TWO;
		}
		else {
			return ZERO;
		}
	}
}

CompWithNull CompareDoubleNull(double n) {
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
	printf("# Square equation solver\n"
        "# (c) NeonVP, 2025\n\n");
}


// stdin 
// stdout
// stderr

//read about eof

bool ClearBuffer() {
	while (getchar() != EOF) {}
	return false;
}

int Input(double *coefs) {
	while (scanf("%lg %lg %lg", &coefs[0], &coefs[1], &coefs[2]) != 3) {
		ClearBuffer();
		printf("Incorrect Input. Try again, please.\n"
		  "Enter coefficients of square equation: ");
	}
	return 0;
} 


int OutputRoots(cntRoots nRoots, double *roots) {
	switch (nRoots){
		case INF:
			printf("The equation has an infinity number of roots.\n");
			return 1;
		case ZERO:
			printf("There are no roots.\n");
			return 1;
		case ONE:
			printf("There is 1 roots: %lg.\n", roots[0]);
			return 1;
		case TWO:
			printf("There is 2 roots: %lg and %lg.\n", roots[0], roots[1]);
			return 1;
		default:
			printf("Unknown number of solutions");
	}
	return 0;
}


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

	int i = 0;
	for (i = 0; i < 7; i++) {
		double roots[2] = {};
		cntRoots nRoots = SolveEquation(tests[i][0], roots);		// 2, 3
		if (!(nRoots == tests_nRoots[i] && roots[0] == tests[i][1][0] && roots[1] == tests[i][1][1])) {
			printf("FAILED: SolveEquation(%lf, %lf, %lf, ...) -> %s, x1 = %lf, x2 = %lf (should be x1 = %lf, x2 = %lf, %s)\n",
				tests[i][0][0], tests[i][0][1], tests[i][0][2],
				cntRoots_to_str(nRoots),
				roots[0], roots[1],
				tests[i][1][0], tests[i][1][1], tests_nRoots[i]);
		}
	}
}

const char* cntRoots_to_str(cntRoots string) {
	switch (string) {
		case INF: return "INF";
		case ZERO: return "0";
		case ONE: return "1";
		case TWO: return "2";
		default: return "Error";
	}
}