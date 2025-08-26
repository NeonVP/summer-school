#ifndef TESTSOLVEEQ_H
#define TESTSOLVEEQ_H

#include <stdio.h>
#include <math.h>

#include "errors.h"
#include "I_WonnaBeAMathematician.h"
#include "UserInterface.h"

Errors TestSolveEquation();
Errors RunTest(const Coefficients *coefs, EquationRoots *roots, const EquationRoots *test_Roots);

#endif //TESTSOLVEEQ_H
