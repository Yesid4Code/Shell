#include "headershell.h"
#include <stdio.h>
/**
 * get_input - get input typing for the user
 *
 * Return: Always 0 success
 */
char **get_input(char *line)
{
	char **argv;
	char *tokens = NULL;/* containt each string typing */
        char *limstr[1] = {" \t\n\r"};/* string delimited */
        int i = 0;

	tokens = strtok(line, *limstr);
	i = 0;
	while (tokens != NULL && i < 50)/*token each string*/
	{
		argv[i] = tokens;
		if (!strcmp("exit", argv[0]))
			exit(1);
		tokens = strtok(NULL, *limstr);
		i++;
		printf("%s\n", argv[0]);
	}
	argv[i] = NULL;
	return (argv);
}
