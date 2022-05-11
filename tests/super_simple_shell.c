/* gcc -Wall -pedantic -Werror -Wextra -std=gnu89 super_simple_shell.c -o super_simple_shell && ./super_simple_shell */
/* Library for getline */
#include <stdio.h>

/* Library for malloc */
#include <stdlib.h>

/* Library for STDIN_FILENO */
#include <unistd.h>

/* Library for strtok */
#include <string.h>

/* Library for wait */
#include <sys/wait.h>

/**
 * print_string
 * 
 */
void print_string(char *str)
{
	while (*str)
	{
		write(STDOUT_FILENO, &*str, 1);
		str++;
	}
}

/**
 * get_user_command - a function to get user command
 *
 * Description: Get user command from standard input.
 *
 * Return: command in string format, otherwise null
 */
char *get_user_command(void)
{
	/* NULL pointer */
	__attribute__((unused)) char *command = NULL;
    __attribute__((unused)) size_t buffer_size = 32;
    __attribute__((unused)) ssize_t bytes_read;

    print_string("$");

	/* Get user input */
    bytes_read = getline(&command, &buffer_size, stdin);

    if (bytes_read == -1)
    {
        perror("Error:");
		exit(1);
    }

    /* Replace new line character with Null character */
    if (bytes_read > 0 && command[bytes_read - 1] == '\n') {
        command[bytes_read-1] = '\0';
    }

	return (command);
}

char **split_string_to_words_array(char *str_p)
{
	__attribute__((unused)) char* token;
	__attribute__((unused)) char **str = malloc(10 * sizeof(char*));
	__attribute__((unused)) int index = 0;

	token = strtok(str_p, " ");

	while (token != NULL)
	{
		str[index] = token;
		printf("%d. %s\n", index, token);
        token = strtok(NULL, " ");
		index++;
    }
	str[++index] = NULL;

	return str;
}

/**
 * execute_command - Function that executes a command using execve system call.
 * @argv: A double pointer string (array) of commands
 *
 * Description: argv should be of the format format
 * {"command", "options", .. NULL};
 *
 * Return: Nothing.
 */
void execute_command(char **argv)
{
	int pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Error:");
	}

	/* Child process */
	if (pid == 0) {
		/* Execute the command */
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	} else {
		/* wait for child process to finish */
		wait(&status);
	}
}

int main(void)
{
	/* NULL pointer */
	__attribute__((unused)) char *command = NULL;

	/* NULL double pointer */
	__attribute__((unused)) char **argv = NULL;

	while(1) {
		/* Get command from user */
		command = get_user_command();
		printf("%s\n", command);

		/* Split string command to array */
		argv = split_string_to_words_array(command);

		/* perform execve in child process */
		execute_command(argv);

		/* deallocte memory */
		free(command);
		free(argv);
	}

	return (0);	
}
