#include "main.h"

/**
 * _getenv - a function that gets an environment variable.
 *
 * @name - name of environment varible.
 * 
 * Return: value of environement variable
 */
char *_getenv(const char *name)
{
	extern char **environ;
	char *value = NULL;
	int i = 0;
	__attribute__((unused)) char* token;
	__attribute__((unused)) char* delimiter = "=";

	while(environ[i])
	{
		char *env = environ[i++];

/* 		printf("%d, env: %s\n", i, env); */

		token = strtok(env, delimiter);
		if(token != NULL)
		{
/* 			printf("token: %s\n", token);
			printf("name: %s\n", name); */

			if(_strcmp(token, name))
			{
				token = strtok(NULL, delimiter);

				if(token != NULL)
				{
					/* printf("value: %s\n", token); */
					value = token;
					break;
				}
			}
		}
	}
		
	return (value);
}
