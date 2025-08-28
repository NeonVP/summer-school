#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <math.h>

enum Comparison
{
    ABOVE = 2,
    EQUAL = 1,
    BELLOW = 0
};

Comparison CompareDoubleToDouble(const double number1, const double number2);

void ClearBuffer();

#endif
