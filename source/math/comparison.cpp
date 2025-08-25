#include "comparison.h"

#include <math.h>

Comparing CompareDoubleToDouble(const double number1, const double number2) {
    if (!isfinite(number1)) {

    }

    if (number1 - number2 > EPS) {
        return ABOVE;
    }
    else if (abs(number1 - number2) < EPS) {
        return EQUAL;
    }
    else {
        return BELLOW;
    }
}