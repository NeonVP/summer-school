#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <math.h>

enum Comparison
{
    ABOVE = 1,
    EQUAL = 0,
    BELLOW = -1
};

Comparison CompareDoubleToDouble(const double number1, const double number2);

void ClearBuffer();

#endif
