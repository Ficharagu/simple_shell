/* gcc -Wall -pedantic -Werror env_vs_environ.c -o env_vs_environ && ./env_vs_environ */

#include <stdio.h>

/**
 * main - prints the environment variables
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    unsigned int i;

    i = 0;
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }

	puts("\n\n");

	extern char **environ;

	i = 0;
	while(environ[i])
		printf("%s\n", environ[i++]);

    return (0);
}