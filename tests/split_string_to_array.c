#include "main.h"

/**
 * @brief
 *
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