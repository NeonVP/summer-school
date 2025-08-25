#include "TestSolveEq.h"

#include <stdio.h>
#include "../include/common.h"
#include "../math/comparison.h"
#include "../math/I_WonnaBeAMathematician.h"

void TestSolveEquation() {
    Coefficients tests_Coefs[] =
    	{
    	{1, -5, 6},
    	{1, -4, 4},
    	{1, 2, 5},
    	{0, 2, -4},
    	{4, 0, -16},
    	{2, -6, 0},
    	{0, 0, 0},
    	{0, 0, 5}
    	};

    EquationRoots tests_Roots[] =
    	{
    	{2, 3, TWO},
    	{2, 0, ONE},
    	{0, 0, ZERO},
    	{2, 0, ONE},
    	{-2, 2, TWO},
    	{0, 3, TWO},
    	{0, 0, INF},
    	{0, 0, ZERO}
    	};



    for (int i = 0; i < 8; i++) {
    	Errors err = Err_NONE;
    	Coefficients coefs = tests_Coefs[i];
    	EquationRoots roots = {};
    	OneTest(&coefs, &roots, &err, &tests_Roots[i]);
    }
}

void OneTest(const Coefficients *coefs, EquationRoots *roots, Errors *err, const EquationRoots *test_Roots) {
	SolveEquation(coefs, roots, err);
	if (!(roots->nRoots == test_Roots->nRoots && CompareDoubleToDouble(roots->x1, test_Roots->x1) == EQUAL &&
												 CompareDoubleToDouble(roots->x2, test_Roots->x2) == EQUAL)) {
		printf(COLOR_RED "FAILED: SolveEquation(%lf, %lf, %lf, ...) -> %s, x1 = %lf, x2 = %lf (should be x1 = %lf, x2 = %lf, %s)\n" COLOR_RESET,
				coefs->coef_a, coefs->coef_b, coefs->coef_c,
				ListCntRoots[roots->nRoots],
				roots->x1, roots->x2,
				test_Roots->x1, test_Roots->x2, ListCntRoots[test_Roots->nRoots]);
	}
	else {
		printf(COLOR_GREEN "OK: SolveEquation(%lf, %lf, %lf, ...) -> %s, x1 = %lf, x2 = %lf (should be x1 = %lf, x2 = %lf, %s)\n" COLOR_RESET,
				coefs->coef_a, coefs->coef_b, coefs->coef_c,
				ListCntRoots[roots->nRoots],
				roots->x1, roots->x2,
				test_Roots->x1, test_Roots->x2, ListCntRoots[test_Roots->nRoots]);
	}
	}
