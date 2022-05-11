#ifndef MAIN_H
	#define MAIN_H

	#include <stdio.h>

	/* Library for strtok */
	#include <string.h>

	/* Library for malloc */
	#include <stdlib.h>

/**
 * struct list_s - singly linked list
 * @dir: String name of dir
 * @next: Next node pointer
 *
 * Description: singly linked list node structure
 *              for PATH directories
 */
typedef struct path_dir_list_s
{
	char *dir;
	struct path_dir_list_s *next;
} path_dir_list_t;

	int _strcmp(char *s1, const char *s2);
	char *_getenv(const char *name);
	char **split_string_to_array(char *str, char *delimiter);
	int path_env_directories_linked_list_push(path_dir_list_t **head, char *str);
	int _setenv(char *var, char *value);
#endif
