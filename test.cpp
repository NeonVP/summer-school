#include <stdio.h>

int main(void) {
	double a = 0, b  = 0, c = 0;

	printf("%d\n", scanf("%lg %lg %lg", &a, &b, &c));
	printf("%lg %lg %lg", a, b, c);
}