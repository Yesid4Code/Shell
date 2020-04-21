#include "headershell.h"
#include <signal.h>

/**
 * control_c - catch signal of Ctrl + C
 * @c: value signal typed
 *
 * Return: void
 */
void control_c(int c)
{
	if (c == SIGINT)
		write(STDOUT_FILENO, "\n#cisfun$ ", 10);
	/*else if (c == EOF)*/
	/*write(STDOUT_FILENO, "\n", 1);*/
}

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
		return (NULL);

	i = _strlen(str) + 1;
	la = malloc(i * sizeof(char)); /*reserve the space of memory*/
	if (!la)
		return (NULL);

	for (j = 0; j < i; j++)
		la[j] = str[j];

	return (la);
}

/**
 * _strlen -  returns the length of a string.
 * @s: char
 * Return: i
 */
int _strlen(char *s)
{
	int i = 0;
	if (s == NULL)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
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

/**
 * str_concat - Function that concatenates two string.
 * @s1: String to concatenate.
 * @s2: String to concatenate.
 * Return: Pointer to the final string.
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0;

	i = _strlen(s1);

	for (; s2[j] != '\0'; i++, j++)
		s1[i] = s2[j];
	s1[i] = '\0';
	return (s1);
}
