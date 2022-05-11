/* gcc -Wall -pedantic -Werror -Wextra -std=gnu89 exec.c -o exec && ./exec */
#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    /* char *argv[] = {"/bin/ls", "TEST_ENV=test/hello/world", NULL}; */
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}
