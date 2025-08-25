#include "../include/errors.h"

const char* errormessage[] = {"No errors", "Null Poiter", "An infinite number"};

void printerr(const char file[], const char func[], int const line, Errors const err_code) {
    fprintf(stderr, COLOR_RED "Error in file:%s, function:%s and line:%d - %s" COLOR_RESET, file, func, line, errormessage[err_code]);
}