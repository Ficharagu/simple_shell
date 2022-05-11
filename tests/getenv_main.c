/* gcc -Wall -pedantic -Werror getenv.c _strcomp.c -o getenv && ./getenv */

#include "main.h"

int main(void)
{
	char *env = _getenv("PATH");

	if(env)
		printf("%s\n", env);

	return (0);
}