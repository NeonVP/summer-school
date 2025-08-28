#ifndef ALLTESTSINONE_H
#define ALLTESTSINONE_H

#include <stdio.h>
#include <math.h>

#include "errors.h"
#include "I_WonnaBeAMathematician.h"

struct List_Numbers_For_Comp {
    double number1 = 0;
    double number2 = 0;
};

Errors TestSolveEquation();
Errors RunTestSolvEq(const Coefficients * const coefs, EquationRoots * const roots, const EquationRoots * const test_Roots);

Errors TestComparison();
Errors RunTestComp(const List_Numbers_For_Comp * const test_numbers, const Comparison test_result);


#endif //ALLTESTSINONE_H
