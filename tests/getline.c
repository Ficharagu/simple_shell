#include <stdio.h>
#include <stdlib.h>

/**
 * @brief a program that prints "$ ", wait for the user to enter a command, prints it on the next line.
 * 
 * @return int 
 */
int main()
{
    char *line;
    size_t buffer_size = 32;
    ssize_t bytes_read;

/*     buffer = (char *)malloc(bufsize * sizeof(char));

    if( buffer == NULL)
    {
		free(buffer);
        perror("Unable to allocate buffer");
        exit(1);
    } */

    printf("$ ");
    /*  while((characters = getline(&buffer, &bufsize, STDIN_FILENO)) != -1); */
    bytes_read = getline(&line, &buffer_size, stdin);

    if (bytes_read == -1)
    {
        puts ("ERROR!");
    }

    /* Replace new line character wuth Null character */
    if (bytes_read > 0 && line[bytes_read - 1] == '\n') {
        line[bytes_read-1] = '\0';
    }

    printf("%u characters were read.\n", (unsigned) bytes_read);
    puts(line);

	free(line);
    return(0);
}
