// #ifndef COMMON_H_INCLUDED
// #define COMMON_H_INCLUDED
#pragma once

#include <math.h>

/*-------COLORS-------*/
#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"
#define GRID			"\x1b[35m # \x1b[0m"

enum cntRoots
{
    INF = 3,
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    UnknownErr = 999
};

inline const char* ListCntRoots[4] = {"ZERO", "ONE", "TWO", "INF"};

enum Errors
{
    Err_NONE = 0,
    Err_nullptr = 1,
    Err_infinitcoef = 2
};


struct Coefficients {
    double coef_a = NAN, coef_b = NAN, coef_c = NAN;
};

struct EquationRoots {
    double x1 = 0, x2 = 0;
    cntRoots nRoots = ZERO;
};

// #endif
