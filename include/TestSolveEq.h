#ifndef TESTSOLVEEQ_H
#define TESTSOLVEEQ_H

#include <stdio.h>
#include <math.h>

#include "errors.h"
#include "I_WonnaBeAMathematician.h"
#include "UserInterface.h"

void TestSolveEquation();
void RunTest(const Coefficients *coefs, EquationRoots *roots, Errors *err, const EquationRoots *test_Roots);

#endif //TESTSOLVEEQ_H
