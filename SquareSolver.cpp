#include <assert.h>
#include <stdio.h>
#include <math.h>

// read about dynamic memory and calloc, realloc, malloc
// add assert

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

cntRoots SolveEquation(double a, double b, double c, double *x1, double *x2);
cntRoots linear_equation(double *x1, double b, double c);
cntRoots square_equation(double *x1, double *x2, double a, double b, double c);

CompWithNull CompareDoubleNull(double n);

void NameOfProgrammAndAuthor(void);

int Input(double *coef_a, double *coef_b, double *coef_c);
int OutputRoots(cntRoots nRoots, double x1, double x2);

bool ClearBuffer();



int main(void) {
	NameOfProgrammAndAuthor();

	printf("Enter coefficients of square equation: ");

	double coef_a = NAN, coef_b = NAN, coef_c = NAN;
	double x1 = NAN, x2 = NAN;
	Input(&coef_a, &coef_b, &coef_c);
	cntRoots nRoots = SolveEquation(coef_a, coef_b, coef_c, NULL, &x2);
	assert(x1 != NULL);
	assert(x2 != NULL);
	OutputRoots(nRoots, x1, x2);

	
	return 0;
}


cntRoots SolveEquation(double a, double b, double c, double *x1, double *x2) {
	assert(std::isfinite (a));
	assert(std::isfinite (b));
	assert(std::isfinite (c));
	if (CompWithNull(a) == EQUAL) {
		if (CompWithNull(b) == EQUAL) {
			if (CompWithNull(c) == EQUAL) {
				return INF;
			}
			else {
				return ZERO;
			}
		}
		else {
			return linear_equation(x1, b, c);
		}
	}
	else {
		return square_equation(x1, x2, a, b, c);
	}
}



cntRoots linear_equation(double *x1, double b, double c) {
	assert(std::isfinite (b));
	assert(std::isfinite (c));
	printf("This is not a square equation, but a linear one.\n");
	*x1 = - (c / b);

	return ONE;
}


cntRoots square_equation(double *x1, double *x2, double a, double b, double c) {
	assert(std::isfinite (a));
	assert(std::isfinite (b));
	assert(std::isfinite (c));
	if (CompWithNull(c) == EQUAL) {
		*x1 = 0;
		linear_equation(x2, a, b);	// call linear_equation		ax+b=0

		return TWO;
	}
	else {
		double disc = b * b - 4 * a * c;

		if (CompWithNull(disc) == EQUAL) {
			*x1 = - (b / (2 * a));

			return ONE;
		}
		else if (disc > 0) {			// add func for compare double and null
			*x1 = (-b + sqrt(disc)) / (2 * a);
			*x2 = (-b - sqrt(disc)) / (2 * a);

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

int Input(double *coef_a, double *coef_b, double *coef_c) {
	while (scanf("%lg %lg %lg", coef_a, coef_b, coef_c) != 3) {
		ClearBuffer();
		printf("Incorrect Input. Try again, please.\n"
		  "Enter coefficients of square equation: ");
	}
	return 0;
} 


int OutputRoots(cntRoots nRoots, double x1, double x2) {
	assert(x1 != NULL);
	assert(x2 != NULL);
	switch (nRoots){
		case INF:
			printf("The equation has an infinity number of roots.\n");
			return 1;
		case ZERO:
			printf("There are no roots.\n");
			return 1;
		case ONE:
			printf("There is 1 roots: %lg.\n", x1);
			return 1;
		case TWO:
			printf("There is 2 roots: %lg and %lg.\n", x1, x2);
			return 1;
		default:
			printf("Unknown number of solutions");
	}
	return 0;
}