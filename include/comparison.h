#ifndef COMPARISSON_H
#define COMPARISSON_H

const float EPS = 2.00000003e-10f;

enum Comparing
{
    ABOVE = 1,
    EQUAL = 0,
    BELLOW = -1
};

Comparing CompareDoubleToDouble(const double number1, const double number2);

#endif


