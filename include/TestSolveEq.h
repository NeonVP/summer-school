#ifndef TESTSOLVEEQ_H
#define TESTSOLVEEQ_H

#include "../include/common.h"

void TestSolveEquation();
void OneTest(const Coefficients *coefs, EquationRoots *roots, Errors *err, const EquationRoots *test_Roots);

#endif //TESTSOLVEEQ_H
