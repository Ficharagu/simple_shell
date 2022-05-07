#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t parent_pid, child_pid;

    /* fork(); */

    parent_pid = getppid();
    child_pid = getpid();

    printf("parent_pid: %u\n", parent_pid);
    printf("child_pid: %u\n", child_pid);

    return (0);
}
