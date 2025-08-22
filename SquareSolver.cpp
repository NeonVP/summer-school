#include <stdio.h>
#include <math.h>

const float EPS = 1e-10f;

// void SolveEquation(void);
// void NameOfProgrammAndAuthor(void);
// void CheckInput(void);
// void OutputRoots(void);

int SolveEquation(double a, double b, double c, double* x1, double* x2) {
	if (abs(a) < EPS && abs(b) < EPS)		// func equal_zero
		return -1;

	if (abs(a) < EPS)
		return 11;

	if (abs(c) < EPS) {
		*x1 = - (b / a);

		return 2;
	}

	double diskriminant = b * b - 4 * a * c;
	if (abs(diskriminant) < EPS) {
		*x1 = - (b / (2*a));

		return 1;
	}
	else if (diskriminant > 0) {
		*x1 = (-b + sqrt(diskriminant)) / (2 * a);		// check rename disc
		*x2 = (-b - sqrt(diskriminant)) / (2 * a);

		return 2;
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

int CheckInput(int result, double *coef_a, double coef_b, double coef_c) {
	printf("@@@ %lg %lg %lg\n", coef_a, coef_b, coef_c);
	if (result == 3)
		return 1;
	return 0;
} 


int OutputRoots(int nRoots, double x1, double x2) {
	switch (nRoots){
		case -1:			// magic number		define/const/enum 
			printf("This is not a quadratic equation, but a linear one.\n");
			return 1;

		case 0: 
			printf("There are no solutions.\n");
            return 1;

		case 1: 
			printf("There is one solution: %lg\n", x1);
			return 1;


		case 11: 
			printf("This is not a quadratic equation, but a linear one.\n");
            printf("There are one solution: %lg\n", x1);
            return 1;
		

		case 2: 
			printf("There are two solutions: %lg and %lg\n", x1, x2);
			return 1;

		case 3: 
			printf("The equation has an infinite number of roots\n");
			return 1;
	}

	return 0;
}


int main(void) {
	NameOfProgrammAndAuthor();

	printf("Enter coefficients of square equation: ");

	double coef_a = 0, coef_b = 0, coef_c = 0, x1 = 0, x2 = 0;//

	if (CheckInput(scanf("%lg %lg %lg", &coef_a, &coef_b, &coef_c), &coef_a, coef_b, coef_c)) {
		int nRoots = SolveEquation(coef_a, coef_b, coef_c, &x1, &x2);

		if (OutputRoots(nRoots, x1, x2) == 1) {
				printf("\n\nCorrect Output\n");
		}
		else {
			printf("\n\n!!!Incorrect Output!!!\n");
		}
	}	
	else {
		printf("Incorrect Input. Try again, please. \n\n");
		break;
	}
	
	return 0;
}





