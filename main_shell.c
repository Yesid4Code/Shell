#include "headershell.h"

/**
 * main - Read, Search and execute the input
 * @argc: count arguments
 * @argv: array of arguments
 *
 * Return: Always 0 success
 */
int main(int argc, char *argv[])
{
	char **input = NULL; /*command typing by user */
	/*int exefun = 0; return execute function */
	(void)argc, (void)argv;

	/*signal(SIGINT, ctrl_c);*/

	while (1)
	{
		if (isatty(STDIN_FILENO)) /*Display prompt */
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		input = get_input();/* ||READING PHASE|| */
		if (input == NULL)
		{
			continue;
		}
		/* ||SEARCHING PATH PHASE|| */
		if (**input != '/')
		{
			input[0] = pathtoexecute(input);
			if (!input[0])
			{
				free(input);
				continue;
			}
			else
			{/* ||EXECUTE PHASE|| */
				/*exefun = receive return of bad executing*/
				execute(input);
				continue;
				/*if (exefun < 0)	continue;*/
			}
		}
		else
			execute(input);
	}
	free(input);
	return (0);
}
