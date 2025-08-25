#include "../../include/UserInterface.h"

#include <stdio.h>

#include "../../include/common.h"

void NameOfProgrammAndAuthor() {
    printf(	COLOR_CYAN
            " ##############################\n"
            " #   Square equation solver   #\n"
            " #         (c) NeonVP, 2025   #\n"
            " ##############################\n\n"
            COLOR_RESET );
}

void ClearBuffer() {
    while (getchar() != '\n') {}
}

void Input(Coefficients *coefs) {
    printf(GRID "Enter" COLOR_YELLOW" coefficients" COLOR_RESET " of square equation: ");
    while (scanf("%lg %lg %lg", &coefs->coef_a, &coefs->coef_b, &coefs->coef_c) != 3) {
        ClearBuffer();
        printf(GRID COLOR_RED "Incorrect Input." COLOR_RESET " Try again, please.\n"
               GRID "Enter" COLOR_YELLOW" coefficients" COLOR_RESET " of square equation: ");
    }
}

void OutputRoots(const EquationRoots *roots, Errors *err) {
    if (roots == nullptr) {
        printf(COLOR_RED "Error in file:%s, function:%s and line:%d - Null pointer on roots" COLOR_RESET,
                __FILE__, __func__, __LINE__);
        *err = Err_nullptr;
    }
    if (*err == Err_NONE) {
        switch (roots->nRoots){
            case INF:
                printf(GRID "The equation has an infinity number of roots.\n");
                break;
            case ZERO:
                printf(GRID "There are no roots.\n");
                break;
            case ONE:
                printf(GRID "There is 1 roots: %lg.\n", roots->x1);
                break;
            case TWO:
                printf(GRID "There is 2 roots: %lg and %lg.\n", roots->x1, roots->x2);
                break;
            case UnknownErr:
                printf(GRID COLOR_RED "!!! Error !!!\n" COLOR_RESET " Unknown number of solutions. \n");
                break;
            default:
                break;
        }
    }
}