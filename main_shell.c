#include "headershell.h"
#include <stdio.h>


/**
 * main - Read, Search and execute the input
 *
 * Return: Always 0 success
 */
int main(int argc, char *argv[], char **env)
{
	(void)argc;
	(void)argv;
	char *line = NULL;
	char **input; /* command typing by user */
	char **binpath; /* pointer to PATH*/
	int i, j;
	size_t len = 0;
	ssize_t read;/*chars read by getline() */
	int exe_child; /*value return by execve*/
	int status; /*status return*/

	while (1)
	{
		printf("#cisfun$> ");/*prompt */

		/*// READING PHASE \\ */
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		input = get_input(line); /*receive the command type by the user */
		printf("VERIFICANDO");

		/*// SEARCHING PATH PHASE \\ */
		/*-----------------*/
		binpath = get_path(env);

		i = 0, j = 0;
		for (; input[i] != '\0'; i++)
			printf("%s", input[i]);

		for (; binpath[j] != '\0'; j++)
                        printf("%s", binpath[j]);

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
