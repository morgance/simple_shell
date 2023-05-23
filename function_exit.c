#include "main.h"

/**
 * *_strprint - prints a string
 * @dest: the destination string to be printed
 * @src: the source string
 * @n: the maximum number of character to be printed
 * Return: pointer to the destination
 */
char *_strprint(char *dest, const char *src, int n)
{
	int j;

	for (j = 0; j < n - 1 && src[j] != '\0'; i++)
		dest[j] = src[j];

	for (; j < n; i++)
		dest[j] = '\0';

	return (dest);
}

/**
 * *_strcpy - copies a string
 * @dest: the destination of the first string
 * @src: the destination of the second string
 * @n: the amounut of maximum bytes to be used
 * Return: the concatenated string
 */
char *_strcpy(char *dest, char *src, int n)
{
	int j, i;
	char *s = dest;

	j = 0;
	i = 0;
	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0' && i < n)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	if (i < n)
		dest[j] = '\0';
	return (dest);
}
