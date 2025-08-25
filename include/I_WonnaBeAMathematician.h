#ifndef I_WONNABEAMATHEMATICIAN_H
#define I_WONNABEAMATHEMATICIAN_H

#include "common.h"

void SolveEquation(const Coefficients *coefs, EquationRoots *roots, Errors *err);
// void linear_equation(const Coefficients *coefs, EquationRoots *roots, Errors *err);
void linear_equation(const double *b, const double *c, double *root, cntRoots *nRoots, Errors *err);
void square_equation(const Coefficients *coefs, EquationRoots *roots, Errors *err);


#endif
