#include <stdio.h>
#include <string.h>

/*
 * gcc -Wall -pedantic -Werror -Wextra -std=gnu89 strtok.c -o strtok && ./strtok
 */

char ** split_string(char str_p[])
{
	/* char str[] = "Geeks-for-Geeks"; */
	char* token;
	static char *str_arr[2];
	int index = 0;
/* 	int space_count = 0; */

	/* count number of spaces*/
/* 	while(*str_p)
	{
		if(*str_p == ' ')
			space_count++;

		str_p++;
	}

	printf("space_count:%u \n", space_count); */

/* 	static char *str_arr[] = {
		"abc", "def"
	}; */

/* 	str_arr[0] = "abc";
	str_arr[1] = "def"; */

	/* puts(str_p); */

	token = strtok(str_p, " ");

    while (token != NULL) {
		str_arr[index] = token;
        printf("%s\n", token);
        token = strtok(NULL, " ");
		index++;
    }

	return(str_arr);
}

int main(void)
{
	char str[] = "hello world";

	char **ptr = split_string(str);

/* 	char *str[] = {
		"abc", "def"
	}; */

	printf("%s\n", *ptr);

	return(0);
}