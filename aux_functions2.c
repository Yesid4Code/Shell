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

/**
 * _copy - function that copy a string in other one.
 * @dest: where src is going to be copied.
 * @src: string to be copy.
 *
 * Return: pointer to dest.
 */
char *_copy(char *dest, char *src)
{
	int i = 0, j = 0;

	i = _strlen(src);
	for (; j < i; j++)
		dest[j] = src[j];
	dest[j] = '\0';
	return (dest);
}

/**
 * freepptr -  free each position and later the double pointer
 * @pptr: double pointer to free
 *
 *
 * Return: diference
 */
void freepptr(char **pptr)
{
	int i = 0;

	while (pptr && pptr[i])
		free(pptr[i++]);
	free(pptr);
}

/**
 * _memseet
 *
 */
char *_memset(char *str, char a, unsigned int size)
{
	unsigned int i;

	for (i = 0; i < size; i++)
		str[i] = a;
	return (str);
}

/**
 * _calloc - function that reserved memory and fill it with zeros.
 * @sizeppter: number of strings inside the array line.
 *
 * Return: array filled with zeros.
 */
void *_calloc(unsigned int sizepptr, unsigned int sizetype)
{
	void *argline = NULL;

	if (sizepptr == 0 || sizetype == 0)
		return (NULL);
	argline = malloc(sizepptr * sizetype + 1);
	if (!argline)
		return (NULL);
	_memset(argline, 0, (sizepptr * sizetype));
	return(argline);
}
