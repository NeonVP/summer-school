#ifndef USERINTERFACE_H
#define USERINTERFACE_H

void NameOfProgrammAndAuthor();

void ClearBuffer();

void Input(Coefficients *coefs);
void OutputRoots(const EquationRoots *roots, Errors *err);

#endif
