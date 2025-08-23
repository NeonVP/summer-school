#include <assert.h>
#include <stdio.h>
#include <math.h>

// read about dynamic memory and calloc, realloc, malloc
// add massivi and unit tests on masivi
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

void NameOfProgrammAndAuthor(void) {
	printf("# Square equation solver\n"
        "# (c) NeonVP, 2025\n\n");
}


// stdin 
// stdout
// stderr

//read about eof

bool ClearBuffer() {
	while (getchar() != '\n') {}
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


// int TestSolveEquation() {
// 	double x1 = 0, x2 = 0;
// 	cntRoots nRoots = SolveEquation(1, -5, 6, &x1, &x2);		// 2, 3
// 	if (!(nRoots == TWO && x1 == 2 && x2 == 3)) {
// 		printf("FAILED: SolveEquation(-1, 5, 6, ...) -> 2, x1 = %lf, x2 = %lf (should be x1 = 3, x2 = 2)\n", x1, x2);
// 	}
// }