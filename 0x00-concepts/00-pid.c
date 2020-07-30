#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid, my_ppid;
	/* int my_ttid;  declare the variable with the data type 'pid_t' */

	my_pid = getpid(); /* capture the Process ID in my_pid variable */
	my_ppid = getppid(); /* capture the Parent PID in my_ppid variable */
	/*my_ttid = gettid(my_ppid); * capture the Thread ID - its no working*/
	printf("Process ID: %u\n", my_pid);
	printf("Parent PID: %u\n", my_ppid);
	/*printf("Thread ID : %u\n", my_ttid);*/
	return (0);
}
