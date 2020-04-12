#include "headershell.h"

/**
 * _strdup - Function that return a pointer to duplicate string.
 * @str: pointer to a string.
 *
 * Return: Pointer to an string.
 */

char *_strdup(char *str)
{
	int i = 0, j;
	char *la;

	if (str == '\0')
		return (0);
	while (str[i] != '\0')
		i++;
	i++;
	la = malloc(i * sizeof(char)); /*reserve the space of memory*/
	if (!la)
		return (NULL);
	for (j = 0; j < i; j++)
		la[j] = str[j];
	la[j] = '\0';
	return (la);
}
