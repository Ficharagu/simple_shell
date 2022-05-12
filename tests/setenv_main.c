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

/* Library for strtok */
#include <string.h>

/**
 * struct env_vars_s - struct for environment variables
 * @key: Variable key
 * @value: Variable value
 */
typedef struct env_vars_s
{
	char *key;
	char *value;
	struct env_vars_s *next; /* Pointer */
} env_vars_t;

int _setenv(char *name, char *value, int overwrite);
char *read_file(char *filename, size_t letters);
int write_file(char *filename, char *text, int truncate);
char **split_string_to_words_array(char *str, char *delimiter);
int env_vars_t_push(env_vars_t **head, char *key, char *value);
int env_vars_t_set(env_vars_t **head, char *key, char *value);
int _strcomp(char *str1, char *str2);
char *_strconcat(char *str1, char *str2);
int _strlen(char *s);

/**
 * main
 */
int main(void)
{
	if (_setenv("TEST", "TESTVALUE", 0) == -1)
		perror("_setenv error: ");

	/* printf("%s\n", _strconcat("abc", "def")); */

	return (0);
}

/**
 * _setenv - a function that changes or adds an environment variable.
 *
 * @key: variable name
 * @value: varable value
 * @overwrite: 0 to to qppend, 1 to overwrite the file.
 *
 * Return: 0 on success, -1 otherwise
 */
int _setenv(__attribute__((unused)) char *key,
			__attribute__((unused)) char *value,
			__attribute__((unused)) int overwrite)
{
	__attribute__((unused)) struct stat *statbuf;
	__attribute__((unused)) char *pathname = "/etc/environment";
	__attribute__((unused)) ssize_t file_descriptor;
	__attribute__((unused)) int filesize;
	__attribute__((unused)) char *file_content;

	__attribute__((unused)) env_vars_t *head = NULL;
	__attribute__((unused)) env_vars_t *new = NULL;

	__attribute__((unused)) char **env_variables_dptr;
	__attribute__((unused)) char **env_variable_dptr;
	__attribute__((unused)) int index = 0;

	statbuf = malloc(sizeof(struct stat));

	if (key == NULL || value == NULL)
		return (0);

	/* Get file details */
	if (stat(pathname, statbuf) == -1)
		return -1;

	filesize = (int)statbuf->st_size;
	printf("file size: %d\n", filesize);

	file_content = read_file(pathname, filesize);
	printf("file content: %s\n", file_content);

	/* Create a linked list of environemt varaibles */
	/* variable_linked_list_push(&head, file_content); */
	/* Get environment variables as an array */
	env_variables_dptr = split_string_to_words_array(file_content, "\n");

	/* Add environment variables to linked list*/
	while (env_variables_dptr[index])
	{
		/* Split environment variable into key and value*/
		env_variable_dptr =
			split_string_to_words_array(env_variables_dptr[index], "=");

		/* printf("env_variable key: %s \n", env_variable_dptr[0]); */

		/* Push environment variable into linked list*/
		env_vars_t_push(&head, env_variable_dptr[0], env_variable_dptr[1]);

		/* printf("env_variables %s \n", env_variables_dptr[index]); */
		index++;
	}

	/* if variable exist in linked list update its value */
	/* If variable does not exist, add variable to linked list */
	if(env_vars_t_set(&head, key, value) == 0)
	{
		env_vars_t_push(&head, key, value);
	}

	/*  Save environment variables to file*/
	printf("write_file: %d", write_file(pathname, "TESTKEY0:testvalue0", 0));

	/* Loop linked list nodes*/
	while(head != NULL)
	{
		printf("%s:%s\n", head->key, head->value);
		head = head->next;
	}
	if (overwrite)
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
char *read_file(char *filename, size_t letters)
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
	if (read_bytes == -1 || file_descriptor == -1)
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
 * write_file - Function that writes text to a file
 *
 * @filename: The pathname of file
 * @text: Text to write to file
 * @truncate: 1 truncate file
 *
 * Return: 1 on success, otherwise 0
 */
int write_file(char *filename, char *text, __attribute__((unused)) int truncate)
{
	int file_descriptor, written_bytes = 0;

	file_descriptor = open("/etc/environment", O_WRONLY | O_APPEND);
	if (filename == NULL || file_descriptor == -1)
	{
		puts("-");
		close(file_descriptor);
		return (0);
	}

	written_bytes = write(file_descriptor, text, _strlen(text));

	if (written_bytes == -1)
	{		puts("-");
		close(file_descriptor);
		return (0);
	}

	return (0);
}

/**
 * split_string_to_words_array
 *
 * @str: string to split
 * @delimiter: String to use to split string
 *
 * Return: string array
 */
char **split_string_to_words_array(char *str, char *delimiter)
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

/**
 * env_vars_t_push - Add a new node at end of env_vars_t.
 *
 * @key: Name of environment.
 * @value: Value of environment.
 * 
 * Return: 0 on success, 1 otherwise
 */
int env_vars_t_push(env_vars_t **head_node, char *key, char *value)
{
	env_vars_t *new_node, *end_node;

	/* Create new node */
	new_node = malloc(sizeof(env_vars_t));
	if(new_node == NULL) /* Malloc check */
	{
		free(new_node);
		exit (1);
	}

	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;

	/* Attach new node to end of linked list */
	if(*head_node == NULL)
	{
		*head_node = new_node;
	}
	else
	{
		end_node = *head_node;

		while(end_node->next != NULL) /* Go to last node */
			end_node = end_node->next;

		end_node->next = new_node;
	}

	/* !!Freeing memory here cause segmemntation fault */
	/* 	free(new_node); */

	return (0);
}

/**
 * env_vars_t_push - Set the value of env_vars_t node
 *
 * @key: Name of environment.
 * @value: Value of environment.
 * 
 * Return: 1 on success, 0 otherwise
 */
int env_vars_t_set(__attribute__((unused)) env_vars_t **head_node, __attribute__((unused)) char *key, __attribute__((unused)) char *value)
{
	env_vars_t *track = *head_node;

	/* Find node with key and set value */
	while(track != NULL)
	{
		if(_strcomp(track->key, key))
		{
			track->value = value;
			return (1);
		}
			
		track = track->next;
	}

	return (0);
}

/**
 * _strcomp - check if two strings are the same.
 *
 * @str1: First string
 * @str2: Second string
 *
 * Return: 1 if strings match, 0 otherwise 
 */
int _strcomp(char *str1, char *str2)
{
	if(str1 == NULL || str2 == NULL)
		return (0);

	while(*str1 && *str2)
	{
		if(*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}

	return (1);
}

/**
 * _strconcat - Join two strings.
 *
 * @str1: First string
 * @str2: Second string
 *
 * Return: Joined string
 */
char *_strconcat(char *str1, char *str2)
{
	char *joined_str = NULL;
	int index = 0;

	joined_str = malloc(sizeof(char) * (_strlen(str1) + _strlen(str2)));

	if(str1 == NULL || str2 == NULL || joined_str == NULL)
		return (joined_str);

	/* Add str1 to joined string */
	while(*str1)
	{
		joined_str[index] = *str1;
		str1++;
		index++;
	}
	/* Add str2 to joined string */
	while(*str2)
	{
		joined_str[index] = *str2;
		str2++;
		index++;
	}

	return (joined_str);
}

/**
 * _strlen - Gets length of passed string
 *
 * @s: Pointer to a String
 *
 * Return: The length of @s
 */
int _strlen(char *s)
{
	int i = 0;
	char c = s[0];

	while (c != '\0')
	{
		i++;
		c = s[i];
	}

	return (i);
}
