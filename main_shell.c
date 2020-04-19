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
{	/*https://pubs.opengroup.org/onlinepubs/009695399/functions/getcwd.html*/
	char **input = NULL, *cmd = NULL; /* command & pathcommand */
	int r = 0; /* check if the execute was successfull */

	(void)argc, (void)argv;
	signal(SIGINT, control_c); /* read ctrl + C */
	while (1)
	{
		input = get_input(printpromt());/* ||READING PHASE|| */
		if (input == NULL)
			continue; /*ADD executing in current directory getcwd()"./"??*/
		if (**input != '/' || !strncmp(*input, "./", 2))
		{/*||SEARCHING PATH PHASE || */
			cmd = pathtoexecute(input);/*duplicate??*/
			if (!cmd)
			{
				freepptr(input), free(cmd);/*free double pptr*/
				continue;
			}
			else /* ||EXECUTE PHASE|| */
			{
				r = execute(cmd, input, env);
				if (r == -1)
				{
					freepptr(input), free(cmd);
					continue;
				}
			}
		}
		else
		{/**inpút = argv[0] = commandpath to execute*/
			r = execute(*input, input, env);
			if (r == -1)
			{
				freepptr(input);
				continue;
			}
		}
		freepptr(input);
	}
	return (0);
}
