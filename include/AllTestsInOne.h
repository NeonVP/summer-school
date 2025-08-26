#ifndef ALLTESTSINONE_H
#define ALLTESTSINONE_H

#include <stdio.h>
#include <math.h>

#include "errors.h"
#include "I_WonnaBeAMathematician.h"

int TestMode();
Errors TestSolveEquation();
Errors RunTestSolvEq(const Coefficients *coefs, EquationRoots *roots, const EquationRoots *test_Roots);


#endif //ALLTESTSINONE_H
