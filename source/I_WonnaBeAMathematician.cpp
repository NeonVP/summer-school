#include "../include/I_WonnaBeAMathematician.h"

Errors SolveEquation(const Coefficients * const coefs, EquationRoots * const roots) {
	MyAssert(roots != NULL, ERR_NULLPTR)
	MyAssert(coefs != NULL, ERR_NULLPTR)
	MyAssert(isfinite(coefs->coef_a), ERR_ISINFINITE)
	MyAssert(isfinite(coefs->coef_a), ERR_ISINFINITE)
	MyAssert(isfinite(coefs->coef_a), ERR_ISINFINITE)

	if (CompareDoubleToDouble(coefs->coef_a, 0) == EQUAL) {
		return linear_equation(&coefs->coef_b, &coefs->coef_c, &roots->x1, &roots->nRoots);
	}
	else {
		return square_equation(coefs, roots);
	}
}


Errors linear_equation(const double * const b, const double * const c, double * const root, cntRoots * const nRoots) {
	MyAssert(b != NULL, ERR_NULLPTR)
	MyAssert(c != NULL, ERR_NULLPTR)
	MyAssert(isfinite(*b), ERR_ISINFINITE)
	MyAssert(isfinite(*c), ERR_ISINFINITE)

	if (CompareDoubleToDouble(*b, 0) == EQUAL) {
		if (CompareDoubleToDouble(*c, 0) == EQUAL) {
			*nRoots = INF;
		}
		else {
			*nRoots = ZERO;
		}
	}
	else {
		*root = - (*c / *b);

		*nRoots = ONE;
	}

	return ERR_NONE;
}

Errors square_equation(const Coefficients * const coefs, EquationRoots * const roots) {
	MyAssert(coefs != NULL, ERR_NULLPTR)
	MyAssert(roots != NULL, ERR_NULLPTR)
	MyAssert(isfinite(coefs->coef_a), ERR_ISINFINITE)
	MyAssert(isfinite(coefs->coef_b), ERR_ISINFINITE)
	MyAssert(isfinite(coefs->coef_c), ERR_ISINFINITE)

	if (CompareDoubleToDouble(coefs->coef_c, 0) == EQUAL) {
		if (CompareDoubleToDouble(coefs->coef_b, 0) == EQUAL) {
			roots->x1 = 0;

			roots->nRoots = ONE;
		}
		else {
			roots->x1 = 0;
			linear_equation(&coefs->coef_a, &coefs->coef_b, &roots->x2, &roots->nRoots);

			roots->nRoots = TWO;
		}
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

	return ERR_NONE;
}
