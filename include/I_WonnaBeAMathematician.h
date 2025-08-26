#ifndef I_WONNABEAMATHEMATICIAN_H
#define I_WONNABEAMATHEMATICIAN_H

#include <stdio.h>
#include <math.h>

#include "errors.h"
#include "utilities.h"


enum cntRoots
{
    INF = 3,
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    UnknownErr = 999
};

inline const char* ListCntRoots[] = {"ZERO", "ONE", "TWO", "INF"};

struct Coefficients {
    double coef_a = NAN, coef_b = NAN, coef_c = NAN;
};

struct EquationRoots {
    double x1 = 0, x2 = 0;
    cntRoots nRoots = ZERO;
};

Errors SolveEquation(const Coefficients * const coefs, EquationRoots * const roots);
Errors linear_equation(const double * const b, const double * const c, double * const root, cntRoots * const nRoots);
Errors square_equation(const Coefficients * const coefs, EquationRoots * const roots);


#endif
