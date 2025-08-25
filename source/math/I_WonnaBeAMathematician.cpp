#include "../../include/I_WonnaBeAMathematician.h"

#include <stdio.h>
#include "../../include/common.h"

#include "../../include/comparison.h"

void SolveEquation(const Coefficients *coefs, EquationRoots *roots, Errors *err) {
	if (coefs == nullptr) {
		printf("Error in file:%s, function:%s and line:%d - Null pointer on coefs", __FILE__, __func__, __LINE__);
		*err = Err_nullptr;
	}
	if (roots == nullptr) {
		printf("Error in file:%s, function:%s and line:%d - Null pointer on roots", __FILE__, __func__, __LINE__);
		*err = Err_nullptr;
	}
	if (!isfinite(coefs->coef_a)) {
		printf("Error in file:%s, function:%s and line:%d - An infinite A coefficient", __FILE__, __func__, __LINE__);
		*err = Err_infinitcoef;
	}
	if (!isfinite(coefs->coef_b)) {
		printf("Error in file:%s, function:%s and line:%d - An infinite B coefficient", __FILE__, __func__, __LINE__);
		*err = Err_infinitcoef;
	}
	if (!isfinite(coefs->coef_c)) {
		printf("Error in file:%s, function:%s and line:%d - An infinite C coefficient", __FILE__, __func__, __LINE__);
		*err = Err_infinitcoef;
	}
	if (*err == Err_NONE) {
		if (CompareDoubleToDouble(coefs->coef_a, 0) == EQUAL) {
			linear_equation(&coefs->coef_b, &coefs->coef_c, &roots->x1, &roots->nRoots, err);
		}
		else {
			square_equation(coefs, roots, err);
		}
	}
}


// TODO: more nullptr
// void linear_equation(const Coefficients *coefs, EquationRoots *roots, Errors *err) {
void linear_equation(const double *b, const double *c, double *root, cntRoots *nRoots, Errors *err) {
	// if (coefs == nullptr) {
	// 	printf("Error in file:%s, function:%s and line:%d - Null pointer on coefs", __FILE__, __func__, __LINE__);
	// 	*err = Err_nullptr;
	// }
	// if (roots == nullptr) {
	// 	printf("Error in file:%s, function:%s and line:%d - Null pointer on roots", __FILE__, __func__, __LINE__);
	// 	*err = Err_nullptr;
	// }
	// if (!isfinite(coefs->coef_a)) {
	// 	printf("Error in file:%s, function:%s and line:%d - An infinite A coefficient", __FILE__, __func__, __LINE__);
	// 	*err = Err_infinitcoef;
	// }
	// if (!isfinite(coefs->coef_b)) {
	// 	printf("Error in file:%s, function:%s and line:%d - An infinite B coefficient", __FILE__, __func__, __LINE__);
	// 	*err = Err_infinitcoef;
	// }
	// if (!isfinite(coefs->coef_c)) {
	// 	printf("Error in file:%s, function:%s and line:%d - An infinite C coefficient", __FILE__, __func__, __LINE__);
	// 	*err = Err_infinitcoef;
	// }
	if (*err == Err_NONE) {
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
	}
}

void square_equation(const Coefficients *coefs, EquationRoots *roots, Errors *err) {
	if (coefs == nullptr) {
		printf("Error in file:%s, function:%s and line:%d - Null pointer on coefs", __FILE__, __func__, __LINE__);
		*err = Err_nullptr;
	}
	if (roots == nullptr) {
		printf("Error in file:%s, function:%s and line:%d - Null pointer on roots", __FILE__, __func__, __LINE__);
		*err = Err_nullptr;
	}
	if (!isfinite(coefs->coef_a)) {
		printf("Error in file:%s, function:%s and line:%d - An infinite A coefficient", __FILE__, __func__, __LINE__);
		*err = Err_infinitcoef;
	}
	if (!isfinite(coefs->coef_b)) {
		printf("Error in file:%s, function:%s and line:%d - An infinite B coefficient", __FILE__, __func__, __LINE__);
		*err = Err_infinitcoef;
	}
	if (!isfinite(coefs->coef_c)) {
		printf("Error in file:%s, function:%s and line:%d - An infinite C coefficient", __FILE__, __func__, __LINE__);
		*err = Err_infinitcoef;
	}
	if (*err == Err_NONE) {
		if (CompareDoubleToDouble(coefs->coef_c, 0) == EQUAL) {
			roots->x1 = 0;
			linear_equation(&coefs->coef_a, &coefs->coef_b, &roots->x2, &roots->nRoots, err);

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
