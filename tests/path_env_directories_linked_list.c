/*  gcc -Wall -pedantic -Werror -Wextra -std=gnu89  path_env_directories_linked_list.c _getenv.c _strcomp.c split_string_to_array.c path_env_directories_linked_list_push.c -o path_env_directories_linked_list && ./path_env_directories_linked_list */

#include "main.h"

/**
 * main - a function that builds a linked list of the PATH directories
 *
 * Return: 0 Always
 */
int main(void)
{
	char *directories_str;
	__attribute__((unused)) char **directories_path_array;
	__attribute__((unused)) int index = 0;

	__attribute__((unused)) path_dir_list_t *head = NULL;
	__attribute__((unused)) path_dir_list_t *tmp = NULL;
	
	head = (path_dir_list_t *) malloc(sizeof(path_dir_list_t));

	/* Get PATH directories */
	directories_str = _getenv("PATH");

	/* printf("%s\n", directories_str); */

	/* Split  */
	directories_path_array = split_string_to_array(directories_str, ":");

	/* Malloc check */
	if (head == NULL) {
		perror("Error: ");
		return 1;
	}

	/* Add directories to linked list */
	while(directories_path_array[index])
	{
		path_env_directories_linked_list_push(&head, directories_path_array[index]);
		index++;
	}

	/* Loop linked list */
	while(head)
	{
		if(head->dir != NULL)
			printf("%s\n", head->dir);
		head = head->next;
	}

	/*TODO Free memory */
	return (0);
}
