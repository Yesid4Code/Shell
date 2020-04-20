#include "headershell.h"

/**
 * main - Read, Search and execute the input
 * @argc: count arguments
 * @argv: array of arguments
 * @environ: array of environment variables
 *
 * Return: Always 0 success
 */
int main(int argc, char *argv[], char **env)
{
	char **input = NULL, *fullpath = NULL; /* command & pathcommand */
	int countexec = 1; /* check if the execute was successfull */

	(void)argc, (void)argv, signal(SIGINT, control_c); /* read ctrl + C */
	while (1)
	{
		input = get_input(printpromt()); /* ||READING PHASE|| */
		if (input == NULL)
		{
			countexec++;
			continue; /*ADD executing in getcwd() ?*/
		}
		if (**input != '/'/* || !strncmp(*input, "./", 2)*/)
		{       /*||SEARCHING PATH PHASE || */
			fullpath = get_path(*input);
			if (fullpath) /* ||EXECUTE PHASE|| */
			{
				execute(argv[0], fullpath,
					input, env, countexec);
			}
		}
		else
		{/**inpút = argv[0] = commandpath to execute*/
			execute(argv[0], *input, input, env, countexec);
/*			if (r == -1)*/
/*			{*/
/*				freepptr(input);*/
/*				continue;*/
/*			}*/
		}
		freepptr(input);
		countexec++;
	}
	return (0);
}
