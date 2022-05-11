/* gcc -Wall -pedantic -Werror strcomp_main.c _strcomp.c -o strcomp_main && ./strcomp_main */
#include "main.h"

int main(void)
{
	printf("a == b: %d\n", _strcmp("a", "b"));
	printf("a == b: %d\n", _strcmp("b", "a"));

	return (0);
}