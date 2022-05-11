/*  gcc -Wall -pedantic -Werror -Wextra -std=gnu89 setenv_main.c -o setenv_main && ./setenv_main */
#include <stdio.h>

/* size_t ssize_t Library */
#include <stdlib.h>

/* stat Library */
#include <sys/types.h>
#include <sys/stat.h>

/*Library for open system call man open*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* STDOUT_FILENO Library */
#include <unistd.h>

int _setenv(const char *name, const char *value, int overwrite);

char *read_textfile(const char *filename, size_t letters);

/**
 * main
 */
int main(void)
{
	if(_setenv("TESTKEY", "TESTVALUE", 0) == -1)
		perror("_setenv error: ");

	return (0);
}

/**
 * _setenv - a function that changes or adds an environment variable.
 *
 * @name: key name
 * @value: value to save
 * @overwrite: 0 to to qppend, 1 to overwrite the file.
 *
 * Return: 0 on success, -1 otherwise
 */
int _setenv(__attribute__((unused)) const char *name,
			__attribute__((unused)) const char *value,
			__attribute__((unused)) int overwrite)
{
	__attribute__((unused)) struct stat *statbuf;
	__attribute__((unused)) const char *pathname = "/etc/environment";
	__attribute__((unused)) ssize_t file_descriptor;
	__attribute__((unused)) int filesize;
	__attribute__((unused)) char *file_content;

	statbuf = malloc(sizeof(struct stat));

	if(name == NULL || value == NULL)
		return (0);

	/* Get file details */
	if(stat(pathname, statbuf) == -1)
		return -1;

	filesize = (int) statbuf->st_size;
	printf("file size: %d\n", filesize);

	file_content = read_textfile(pathname, filesize);
	printf("file content: %s\n", file_content);



	/* Check if variable exists */

	if(overwrite)
		puts("overwrite");
	else
		puts("append");

	printf("path: %s\n", pathname);

	return (1);
}


/**
 * read_textfile - Function that reads a text file and prints it
 *
 * @filename: The pathname of file to read
 * @letters: number of letters it should read and print
 *
 * Description: A function that reads a text file and prints it to
 * the POSIX standard output.
 * Return: Number of letters it could read and print, otherwise 0
 */
char *read_textfile(const char *filename, size_t letters)
{
	/* Declarations */
	ssize_t file_descriptor, read_bytes;
	char *buffer;

	if (filename == NULL)
		return (0);

	/* Dynamic memory allocation for string, reserve space */
	buffer = malloc(sizeof(char) * letters);

	/*Check to avoid avoid segmentation fault*/
	if (!buffer)
		return (0);

	/* Open file in read only using the oflag O_RDONLY */
	file_descriptor = open(filename, O_RDONLY);

	/* Read the file*/
	read_bytes = read(file_descriptor, buffer, letters);

	/* Check for fails*/
	if (read_bytes == -1  || file_descriptor == -1)
	{
		free(buffer); 
		close(file_descriptor);
		return (0);
	}

	/* Close file descriptor */
	close(file_descriptor);

	return (buffer);
}

/**
 * split_string_to_words_array - split string to words 
 * 
 * @str: string to split 
 * @delimiter: 
 */
char **split_string_to_array(char *str, char *delimiter)
{
	__attribute__((unused)) char *token;
	__attribute__((unused)) char **tokens = malloc(100 * sizeof(char *));
	__attribute__((unused)) int index = 0;

	token = strtok(str, delimiter);

	while (token != NULL)
	{
		tokens[index] = token;
		/* printf("%d. %s\n", index, token); */
		token = strtok(NULL, delimiter);
		index++;
	}
	tokens[++index] = NULL;

	return tokens;
}
