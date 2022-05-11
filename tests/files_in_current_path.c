/* gcc -Wall -pedantic -Werror -Wextra -std=gnu89 files_in_current_path.c -o files_in_current_path && ./files_in_current_path */
#include <stdio.h>

/* Library for  opendir */
#include <sys/types.h>
#include <dirent.h>

/**
 * main - Program that looks for files in the current PATH
 * 
 * Return: 0 Always
 */
int main(void)
{
	DIR *dir;
	struct dirent *struct_dir;

	dir = opendir(".");
	if(dir){
		while ((struct_dir = readdir(dir)) != NULL) {
			printf("%s\n", struct_dir->d_name);
		}
		closedir(dir);
	}

	return (0);
}
