/*  gcc -Wall -pedantic -Werror -Wextra -std=gnu89  path_env_directories.c _getenv.c _strcomp.c split_string_to_array.c -o path_env_directories && ./path_env_directories */

#include "main.h"

/**
 * main - a function that prints each directory contained in the the 
 * environment variable PATH.
 *
 * Return: O always.
 */
int main(void)
{
	char *directories_str;
	__attribute__((unused)) char **directories_path_array;
	int index = 0;

	/* Get PATH directories */
	directories_str = _getenv("PATH");
	/* printf("%s\n", directories_str); */

	/* Split  */
	directories_path_array = split_string_to_array(directories_str, ":");

	/* Ouput directories */
	while(directories_path_array[index]) {
		printf("%s\n", directories_path_array[index]);
		index++;
	}
		
	
	return(0);
}