/* gcc -Wall -pedantic -Werror environ.c -o environ && ./environ */

#include <stdio.h>

int main(void)
{
	/* points to an array of pointers to strings called the "environment" */
	extern char **environ;

	int i = 0;
	while(environ[i])
		printf("%s\n", environ[i++]);

	return (0);
}
