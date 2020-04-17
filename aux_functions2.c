#include "headershell.h"

/**
 * _strncmp -  function that compares two strings.
 * @s1: string one
 * @s2: string two
 * @n: number of characters
 * Return: diference
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	int i = 0, j = 0;

	while (n && s1[i] && (s1[i] == s2[j]))
	{
		i++;
		j++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[j]);
	}
}
