#include "../include/AllTestsInOne.h"

const char * ListCntRoots[] = {"ZERO", "ONE", "TWO", "INF"};

Errors TestSolveEquation() {
	FILE * file_with_tests = fopen("test/testSolvEq.txt", "r");

	MyAssert(file_with_tests != NULL, ERR_NULLPTR);

	int SIZE = 0;
	fscanf(file_with_tests, "%d", &SIZE);

    Coefficients  * const tests_coefs = (Coefficients *)calloc(SIZE, sizeof(Coefficients));
	MyAssert(tests_coefs != NULL, ERR_NULLPTR);

    EquationRoots * const tests_roots = (EquationRoots *)calloc(SIZE, sizeof(EquationRoots));
	MyAssert(tests_roots != NULL, ERR_NULLPTR);

	for (int j = 0; j < SIZE; j++) {
		fscanf(file_with_tests, "%lf %lf %lf %lf %lf %d", &tests_coefs[j].coef_a, &tests_coefs[j].coef_b, &tests_coefs[j].coef_c,
		                                       &tests_roots[j].x1, &tests_roots[j].x2, &tests_roots[j].nRoots);
	}

    for (int i = 0; i < SIZE; i++) {
    	Errors err = ERR_NONE;
    	Coefficients coefs = tests_coefs[i];
    	EquationRoots roots = {};
    	RunTestSolvEq(&coefs, &roots, &tests_roots[i]);
    }

	return ERR_NONE;
}

Errors RunTestSolvEq(const Coefficients  * const coefs, EquationRoots * const roots, const EquationRoots * const test_Roots) {
	MyAssert(coefs      != NULL, ERR_NULLPTR);
	MyAssert(roots      != NULL, ERR_NULLPTR);
	MyAssert(test_Roots != NULL, ERR_NULLPTR);

	SolveEquation(coefs, roots);
	if (!(roots->nRoots == test_Roots->nRoots && CompareDoubleToDouble(roots->x1, test_Roots->x1) == EQUAL &&
												 CompareDoubleToDouble(roots->x2, test_Roots->x2) == EQUAL)) {
		printf(GRID COLOR_RED "FAILED: SolveEquation(%lf, %lf, %lf, ...) -> %s, x1 = %lf, x2 = %lf (should be x1 = %lf, x2 = %lf, %s)\n" COLOR_RESET,
				coefs->coef_a, coefs->coef_b, coefs->coef_c,
				ListCntRoots[roots->nRoots],
				roots->x1, roots->x2,
				test_Roots->x1, test_Roots->x2, ListCntRoots[test_Roots->nRoots]);
	}
	else {
		printf(GRID COLOR_GREEN "OK: SolveEquation(%lf, %lf, %lf, ...) -> %s, x1 = %lf, x2 = %lf (should be x1 = %lf, x2 = %lf, %s)\n" COLOR_RESET,
				coefs->coef_a, coefs->coef_b, coefs->coef_c,
				ListCntRoots[roots->nRoots],
				roots->x1, roots->x2,
				test_Roots->x1, test_Roots->x2, ListCntRoots[test_Roots->nRoots]);
	}

	return ERR_NONE;
}
