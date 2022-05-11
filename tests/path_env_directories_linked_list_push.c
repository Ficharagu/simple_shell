#include "main.h"

/**
 * path_env_directories_linked_list_add - 
 * 
 */
int path_env_directories_linked_list_push(path_dir_list_t **head_node, char *str)
{
	/* Create new node */
	path_dir_list_t *new_node;
	path_dir_list_t *last_node;

	new_node = malloc(sizeof(path_dir_list_t));

	if(new_node == NULL)
		return (1);

	/* New node */
	new_node->dir = str;
	new_node->next = NULL;

	if(*head_node == NULL)
		/* Add first node */
		*head_node = new_node;
	else
	{
		last_node = *head_node;

		/* Go to last node */
		while(last_node->next != NULL)
			last_node = last_node->next;

		/* Add node */
		last_node->next = new_node;
	}

	return (0);
}