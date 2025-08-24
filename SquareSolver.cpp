/*
* CODESTYLE:
* - #include
* - #define
* -
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>

// TODO: add your assert
// TODO: add struct
// TODO: add test func for 1 example
// TODO: add more files

/*-------COLORS-------*/
#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"
#define GRID			"\x1b[35m # \x1b[0m"

const float EPS = 2.00000003e-10f;

enum cntRoots
{
	INF = 3,
	ZERO = 0,
	ONE = 1,
	TWO = 2,
	UnknownErr = 999
};

const char* ListCntRoots[4] = {"ZERO", "ONE", "TWO", "INF"};

enum Comparing
{
	ABOVE = 1,
	EQUAL = 0,
	BELLOW = -1
};

enum Errors
{
	Err_NONE = 0,
	Err_nullptr = 1,
	Err_infinitcoef = 2
};

struct Coefficients {
	double coef_a = NAN, coef_b = NAN, coef_c = NAN;
};

struct EquationRoots {
	double x1 = NAN, x2 = NAN;
	cntRoots nRoots = ZERO;
};




void SolveEquation(const Coefficients *coefs, EquationRoots *roots, Errors *err);
void linear_equation(const Coefficients *coefs, EquationRoots *roots, Errors *err);
void square_equation(const Coefficients *coefs, EquationRoots *roots, Errors *err);

void isinfinite(Errors *err, const double number, char func[]);
void isnullptr(Errors *err, const Coefficients *coefs, const EquationRoots *roots, char* func);
void ErrCheck(Errors *err, const Coefficients *coefs, const EquationRoots *roots, char func[]);


Comparing CompareDoubleToDouble(const double number1, const double number2);

void NameOfProgrammAndAuthor();

void Input(Coefficients *coefs);
void OutputRoots(const EquationRoots *roots);

void ClearBuffer();

void TestSolveEquation();

int main() {
	NameOfProgrammAndAuthor();
	Errors err = Err_NONE;
	Coefficients coefs = {};
	EquationRoots roots = {};
	Input(&coefs);
	SolveEquation(&coefs, &roots, &err);

	if (err == Err_NONE) {
		OutputRoots(&roots);
		return 0;
	}
	return 1;
}

// int main() {
// 	TestSolveEquation();
//
// 	return 0;
// }


void isinfinite(Errors *err, const double number, char func[]) {
	if (!isfinite(number)) {
		printf(COLOR_RED "Danger!!! There is an infunite coefficient in func %s.\n" COLOR_RESET, func);
		*err = Err_infinitcoef;
	}
}


void isnullptr(Errors *err, const Coefficients *coefs, const EquationRoots *roots, char* func) {
	if (coefs == nullptr) {
		printf(COLOR_RED "Danger!!! There is a null pointer of coefs in func %s.\n" COLOR_RESET, func);
		*err = Err_nullptr;
	}
	if (roots == nullptr) {
		printf(COLOR_RED "Danger!!! There are a null pointer of roots in func %s.\n" COLOR_RESET, func);
		*err = Err_nullptr;
	}
}


void ErrCheck(Errors *err, const Coefficients *coefs, const EquationRoots *roots, char func[]) {
	isnullptr(err, coefs, roots, func);
	isinfinite(err, coefs->coef_a, func);
	isinfinite(err, coefs->coef_b, func);
	isinfinite(err, coefs->coef_c, func);
}


void SolveEquation(const Coefficients *coefs, EquationRoots *roots, Errors *err) {
	char name_func[] = "SolveEq";

	ErrCheck(err, coefs, roots, name_func);
	if (*err == Err_NONE) {
		if (CompareDoubleToDouble(coefs->coef_a, 0) == EQUAL) {
			linear_equation(coefs, roots, err);
		}
		else {
			square_equation(coefs, roots, err);
		}
	}
}

void linear_equation(const Coefficients *coefs, EquationRoots *roots, Errors *err) {
	char name_func[] = "line_eq";

	ErrCheck(err, coefs, roots, name_func);
	if (*err == Err_NONE) {
		if (CompareDoubleToDouble(coefs->coef_b, 0) == EQUAL) {
			if (CompareDoubleToDouble(coefs->coef_c, 0) == EQUAL) {
				roots->nRoots = INF;
			}
			else {
				roots->nRoots = ZERO;
			}
		}
		else {
			roots->x1 = - (coefs->coef_c / coefs->coef_b);

			roots->nRoots = ONE;
		}
	}
}


void square_equation(const Coefficients *coefs, EquationRoots *roots, Errors *err) {
	char name_func[] = "sq_eq";

	ErrCheck(err, coefs, roots, name_func);
	if (*err == Err_NONE) {
		if (CompareDoubleToDouble(coefs->coef_c, 0) == EQUAL) {
			roots->x1 = 0;
			linear_equation(coefs, roots, err);

			roots->nRoots = TWO;
		}
		else {
			double disc = coefs->coef_b * coefs->coef_b - 4 * coefs->coef_a * coefs->coef_c;

			switch (CompareDoubleToDouble(disc, 0)) {
				case EQUAL:
					roots->x1 = - (coefs->coef_b / (2 * coefs->coef_a));
					roots->nRoots = ONE;
					break;
				case ABOVE:
					roots->x1 = (- coefs->coef_b - sqrt(disc)) / (2 * coefs->coef_a);
					roots->x2 = (- coefs->coef_b + sqrt(disc)) / (2 * coefs->coef_a);
					roots->nRoots = TWO;
					break;
				case BELLOW:
					roots->nRoots = ZERO;
					break;
				default:
					roots->nRoots = UnknownErr;
					break;
			}
		}
	}
}

Comparing CompareDoubleToDouble(const double number1, const double number2) {
	assert(isfinite(number1));
	assert(isfinite(number2));

	if (number1 - number2 > EPS) {
		return ABOVE;
	}
	else if (abs(number1 - number2) < EPS) {
		return EQUAL;
	}
	else {
		return BELLOW;
	}

}

void NameOfProgrammAndAuthor() {
	printf(	COLOR_CYAN
			" ##############################\n"
			" #   Square equation solver   #\n"
			" #         (c) NeonVP, 2025   #\n"
			" ##############################\n\n"
			COLOR_RESET );
}

void ClearBuffer() {
	while (getchar() != '\n') {}
}

void Input(Coefficients *coefs) {
	printf(GRID "Enter" COLOR_YELLOW" coefficients" COLOR_RESET " of square equation: ");
	while (scanf("%lg %lg %lg", &coefs->coef_a, &coefs->coef_b, &coefs->coef_c) != 3) {
		ClearBuffer();
		printf(GRID COLOR_RED "Incorrect Input." COLOR_RESET " Try again, please.\n"
			   GRID "Enter" COLOR_YELLOW" coefficients" COLOR_RESET " of square equation: ");
	}
} 


void OutputRoots(const EquationRoots *roots) {  // add asserts
	switch (roots->nRoots){
		case INF:
			printf(GRID "The equation has an infinity number of roots.\n");
			break;
		case ZERO:
			printf(GRID "There are no roots.\n");
			break;
		case ONE:
			printf(GRID "There is 1 roots: %lg.\n", roots->x1);
			break;
		case TWO:
			printf(GRID "There is 2 roots: %lg and %lg.\n", roots->x1, roots->x2);
			break;
		case UnknownErr:
			printf(GRID COLOR_RED "!!! Error !!!\n" COLOR_RESET " Unknown number of solutions. \n");
			break;
		default:
			break;
	}
}


// void TestSolveEquation() {
// 	double tests_Coefs[8][3] =
// 		{
// 		{1, -5, 6},
// 		{1, -4, 4},
// 		{1, 2, 5},
// 		{0, 2, -4},
// 		{4, 0, -16},
// 		{2, -6, 0},
// 		{0, 0, 0},
// 		{0, 0, 5}
// 		};
//
// 	EquationRoots tests_Roots[8] =
// 		{
// 		{2, 3, TWO},
// 		{2, 0, ONE},
// 		{0, 0, ZERO},
// 		{2, 0, ONE},
// 		{-2, 2, TWO},
// 		{0, 3, TWO},
// 		{0, 0, INF},
// 		{0, 0, ZERO}
// 		};
//
// 	for (int i = 0; i < 8; i++) {
// 		Coefficients coefs = tests_Coefs[i];
// 		EquationRoots roots = {};
// 		SolveEquation(tests[i][0], roots);
//
// 		if (!(nRoots == tests_nRoots[i] && roots[0] == tests[i][1][0] && roots[1] == tests[i][1][1])) {
// 			printf(COLOR_RED "FAILED: SolveEquation(%lf, %lf, %lf, ...) -> %s, x1 = %lf, x2 = %lf (should be x1 = %lf, x2 = %lf, %s)\n" COLOR_RESET,
// 				   tests[i][0][0], tests[i][0][1], tests[i][0][2],
// 				   ListCntRoots[nRoots],
// 				   roots[0], roots[1],
// 				   tests[i][1][0], tests[i][1][1], ListCntRoots[tests_nRoots[i]]);
// 		}
// 		else {
// 			printf(COLOR_GREEN "OK: SolveEquation(%lf, %lf, %lf, ...) -> %s, x1 = %lf, x2 = %lf (should be x1 = %lf, x2 = %lf, %s)\n" COLOR_RESET,
// 				   tests[i][0][0], tests[i][0][1], tests[i][0][2],
// 				   ListCntRoots[nRoots],
// 				   roots[0], roots[1],
// 				   tests[i][1][0], tests[i][1][1], ListCntRoots[tests_nRoots[i]]);
// 		}
// 	}
// }
//
// int OneTest() {
// 	double roots[2] = {};
// 	cntRoots nRoots = SolveEquation(coefs, roots);
// 	if (!(roots[0] == roots_ref[0] && roots[1] == roots_ref[1] && nRoots == nRoots_ref)) {
// 		printf("");
// 		return 0;
// 	}
// 	else {
// 		return 1;
// 	}
// }