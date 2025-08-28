#include "../include/UserInterface.h"

void NameOfProgrammAndAuthor() {
    printf(	COLOR_CYAN
            " ##############################" "      |\\__/,|   (`\\\n"
            " #   Square equation solver   #" "      |_ _  |.--.) )\n"
            " #         (c) NeonVP, 2025   #" "      ( T   )     /\n"
            " ##############################" "     (((^_(((/(((_/\n\n"
            COLOR_RESET );
}

Errors Input(Coefficients * const coefs) {
    MyAssert(coefs != NULL, ERR_NULLPTR)
    printf(GRID "Enter" COLOR_YELLOW" coefficients" COLOR_RESET " of square equation: ");
    while (scanf("%lg %lg %lg", &coefs->coef_a, &coefs->coef_b, &coefs->coef_c) != 3) {
        ClearBuffer();
        printf(GRID COLOR_RED "Incorrect Input." COLOR_RESET " Try again, please.\n"
               GRID "Enter" COLOR_YELLOW" coefficients" COLOR_RESET " of square equation: ");
    }
    return ERR_NONE;
}

Errors OutputRoots(const EquationRoots * const roots) {
    MyAssert(roots != NULL, ERR_NULLPTR)
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
    return ERR_NONE;
}

void meow_cat() {
	printf( COLOR_YELLOW
		   "       /\\_/\\      \n"
           "  /\\  / o o \\      \n"
           " //\\\\ \\~(*)~/  MEOW     \n"
           " `  \\/   ^ /        \n"
           "   | \\|| ||        \n"
           "   \\ '|| ||        \n"
		   "    \\)()-())"")    \n"
		    COLOR_RESET );
}
