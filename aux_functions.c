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

/**
 * countstrings - function that count the strings in the input line.
 * @str: line to tokenize and duplicate
 *
 * Return: size of the input line
 */
int countstrings(char *str)
{
	int state = 0;
	unsigned int wc = 0; /* word count */

	/* Scan all characters one by one */
	while (*str)
	{
		/* If next character is a separator, set the state as zero */
		if (*str == ' ' || *str == '\n' ||
		    *str == '\t' || *str == '\0' || *str == ':')
			state = 0;
		else if (state == 0) /* increment word count */
		{
			state = 1;
			wc++;
		}
		str++; /*Move to next character*/
	}
	return (wc);
}
