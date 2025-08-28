#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <stdio.h>

#include "I_WonnaBeAMathematician.h"
#include "errors.h"
#include "colors.h"

void NameOfProgrammAndAuthor();

Errors Input(Coefficients * const coefs);
Errors OutputRoots(const EquationRoots * const roots);

bool IsBufClean();

void meow_cat();

#endif
