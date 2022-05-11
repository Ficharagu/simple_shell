/**
 * _strcomp.c - A function to compare two strings if they are same
 *
 * @s1 - first string to compare
 * @s2 - second string to comapre with s1
 *
 * Return: 1 if s1 and s2 match, otherwise 0
 */
int _strcmp(char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if((*s1 - *s2) == 0)
		return (1);

	return (0);
}
