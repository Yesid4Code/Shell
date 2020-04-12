#include "headershell.h"
#include <stdio.h>


/**
 * main - Read, Search and execute the input
 * @argc: count arguments
 * @argv: array of arguments
 *
 * Return: Always 0 success
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	char **input; /* command typing by user */
	char **binpath; /* pointer to PATH*/
	size_t len = 0;
	ssize_t read;/*chars read by getline() */
	int exe_child; /*value return by execve*/
	/*int i, j;*/
	(void)argc;
	(void)argv;

	while (1)
	{
		printf("#cisfun$> ");/*prompt */

		/*// READING PHASE \\ */
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		input = get_input(line); /*receive the command type by the user*/

		/*// SEARCHING PATH PHASE \\ */
		/*-----------------*/
		binpath = get_path();

		/*// EXECUTE PHASE \\ */
		exe_child = fork();
		if (exe_child == 0)
		{
			if (execve(input[0], input, NULL) == -1)
			{
				perror("Command not executed. Try again");
				exit(1);
			}
		}
		else
			wait(&status);
	}
	free(line);
	return (0);
}
