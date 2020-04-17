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
	char **input = NULL; /* command typing by user */
	int r = 0; /*  to check if the execute was successfull */

	(void)argc, (void)argv;
	signal(SIGINT, control_c); /* read ctrl + C or */
	while (1)
	{
		input = get_input();/* ||READING PHASE|| */
		if (input == NULL)
			continue;
		/*ADD executing in current directory getcwd()"./"??*/
		if (**input != '/' || strncmp(*input, "./", 2)) /* ||SEARCHING PATH PHASE || */
		{
			input[0] = pathtoexecute(input);
			if (!input[0])
			{
				free(input);
				continue;
			}
			else
			{/* ||EXECUTE PHASE|| */
				r = execute(input);
				if (r == -1)
				{
					perror(*input), free(input);
					continue;
				}
			}
		}
		else
		{
			r = execute(input);
			if (r == -1)
			{
				perror(*input), free(input);
				continue;
			}
		}
		free(input);
	}
	return (0);
}
