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
	char **input = NULL, *cmd; /* command & pathcommand */
	int r = 0; /* check if the execute was successfull */

	(void)argc, (void)argv;
	signal(SIGINT, control_c); /* read ctrl + C */
	while (1)
	{
		input = get_input();/* ||READING PHASE|| */
		if (input == NULL)
			continue; /*ADD executing in current directory getcwd()"./"??*/
		/*https://pubs.opengroup.org/onlinepubs/009695399/functions/getcwd.html*/
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
				r = execute(cmd, input);
				if (r == -1)
				{
					freepptr(input), free(cmd);
					continue;
				}
			}
		}
		else
		{
			r = execute(*input, input);
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
