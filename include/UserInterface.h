#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "common.h"

void NameOfProgrammAndAuthor();

void ClearBuffer();

void Input(Coefficients *coefs);
void OutputRoots(const EquationRoots *roots, Errors *err);

#endif
