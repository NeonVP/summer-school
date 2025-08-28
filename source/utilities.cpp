#include "../include/utilities.h"

const double EPS = 2.22045e-16;

const char* ListComparison[] = {"BELLOW", "EQUAL", "ABOVE"};

Comparison CompareDoubleToDouble(const double number1, const double number2) {
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

void ClearBuffer() {
    while (getchar() != '\n') {}
}