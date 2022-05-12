/* gcc -Wall -pedantic -Werror strcomp_main.c _strcomp.c -o strcomp_main && ./strcomp_main */
/* #include "main.h" */
#include <stdio.h>

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

int main(void)
{
	printf("a == b: %d\n", _strcomp(" ", " "));
	printf("a == b: %d\n", _strcomp("b", "a"));
	printf("b == b: %d\n", _strcomp("b", "b"));
	printf("b == b: %d\n", _strcomp(NULL, NULL));
	printf("b == b: %d\n", _strcomp("moses_soft_eng@DESKTOP-2A7R4TU:~/simple_shell/tests$ gcc -Wall -pedantic -Werror strcomp_main.c _strcomp.c -o strcomp_main && ./strcomp_main", "moses_soft_eng@DESKTOP-2A7R4TU:~/simple_shell/tests$ gcc -Wall -pedantic -Werror strcomp_main.c _strcomp.c -o strcomp_main && ./strcomp_main"));

	if(_strcomp("one", "one"))
	{
		puts("Match");
	}

	return (0);
}