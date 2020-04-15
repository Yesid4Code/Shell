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
	char **input; /*command typing by user */

	(void)argc, (void)argv;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9); /*Display prompt */
		/* ||READING PHASE|| */
		/* Receive the command type by the user */
		input = get_input();
		if (input == NULL)
		{
			continue;
		}
		/* ||SEARCHING PATH PHASE|| */
		if (**input != '/')
		{
			input[0] = _strdup(pathtoexecute(input));
			if (!input[0])
			{
				free(input);
				continue;
			}
			execute(input); /* ||EXECUTE PHASE|| */
		}
		else
			execute(input);
	}
	free(input);
	return (0);
}
