 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <sys/wait.h>

/**
 * main - a program that executes the command ls -l /tmp
 * in 5 different child processes.
 *
 * Return: 0 always
 */
int main(void)
{
	int child_pid;
/* 	int status; */
/* 	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL}; */

	/* execu
	child_pid = fork();
	if(child_pid != 0) child_pid = fork();
	if(child_pid != 0) child_pid = fork();
	if(child_pid != 0) child_pid = fork();
	if(child_pid != 0) child_pid = fork();

	if(child_pid == 0)
	{
		printf("p\n");
	}

	return (0);*/

	int child_pid;
	int status;
/* 	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL}; */

	int i;
	for (i = 0; i < 5; i++) {
		/* Child process PID is always 0 */
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (child_pid == 0) {
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				return (1);
			}

			printf("%u\n", i);
			i++;

			/* Exit child */
			exit(0);
		}
	}

	/* wait for child process to finish */
	for (i = 0; i < 5; i++)
		wait(&status);

	return (0);
}
