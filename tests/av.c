#include <stdio.h>

int main (__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	int i = 0;
	  
	while(argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}

	return (0);
}
