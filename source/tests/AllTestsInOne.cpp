#include "../../include/AllTestsInOne.h"

int TestMode() {
    printf(GRID "Включен тест мод.\n");
    Errors err = TestSolveEquation();
    if (err == ERR_NONE) {
        return 0;
    }
    else {
        return 1;
    }
}