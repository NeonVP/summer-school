#ifndef INPUT_H
#define INPUT_H

#include "../include/common.h"

void ClearBuffer();

void Input(Coefficients *coefs);
void OutputRoots(const EquationRoots *roots, Errors *err);

#endif
