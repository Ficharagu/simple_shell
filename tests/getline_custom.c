/**/ 
 
 #include <stdio.h>
 
 /* Library for size_t ssize_t */
#include <stdlib.h>

/* Library for STDIN_FILENO */
#include <unistd.h>

/* Macro - object like constant */
#define BUFFER_SIZE 1

/**
 * main - program that gets user input.
 *
 * Description: a program that prints "$ ", wait for the user to enter
 * a command then prints it on the next line.
 *
 * Return: 0 always
 */
int main(void)
{
	ssize_t read_bytes;
	char buffer[BUFFER_SIZE];

	/* Get input from standard input */
	read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);

	if(read_bytes == -1)
	{
		perror("Error:");
        return (1);
	}

	printf("%s\n", buffer);

	return (0);
}
