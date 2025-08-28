#include "../include/AllTestsInOne.h"

const char * ListComp[] = {"BELOW", "EQUAL", "ABOVE"};

Errors TestComparison() {
    FILE * const file_with_tests = fopen("test/testComp.txt", "r");
    MyAssert(file_with_tests != NULL, ERR_NULLPTR)

    int SIZE = 0;
    fscanf(file_with_tests, "%d", &SIZE);

    List_Numbers_For_Comp * const tests_numbers = (List_Numbers_For_Comp *)calloc(SIZE, sizeof(List_Numbers_For_Comp));
    MyAssert(tests_numbers != NULL, ERR_NULLPTR);

    int * const tests_results = (int *)calloc(SIZE, sizeof(int));
    MyAssert(tests_results != NULL, ERR_NULLPTR);

    for (int i = 0; i < SIZE; i++) {
        fscanf(file_with_tests, "%lf %lf %d", &tests_numbers[i].number1, &tests_numbers[i].number2, tests_results+i);
    }

    for (int j = 0; j < SIZE; j ++) {
        RunTestComp(&tests_numbers[j], (Comparison)tests_results[j]);
    }

    return ERR_NONE;
}


Errors RunTestComp(const List_Numbers_For_Comp * const test_numbers, const Comparison test_result) {
    MyAssert(test_numbers != NULL, ERR_NULLPTR)

    Comparison result = CompareDoubleToDouble(test_numbers->number1, test_numbers->number2);

    if (!result == test_result) {
        printf(GRID COLOR_RED "FAILED: CompareDoubleToDouble(%lg, %lg) -> %s (should be %s)\n" COLOR_RESET,
                test_numbers->number1, test_numbers->number2, ListComp[result], ListComp[test_result]);
    }
    else {
        printf(GRID COLOR_GREEN "OK: CompareDoubleToDouble(%lg, %lg) -> %s (should be %s)\n" COLOR_RESET,
                 test_numbers->number1, test_numbers->number2, ListComp[result], ListComp[test_result]);
    }

    return ERR_NONE;
}