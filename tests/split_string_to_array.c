#include "main.h"

/**
 * split_string_to_array
 *
 * @str: string to split
 * @delimiter: String to use to split string
 *
 * Return: string array
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