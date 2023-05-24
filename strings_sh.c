#include "main.h"
/**
 * _strlen - returns length of a string
 * @str: the string whose length to check
 *
 * Return: int length of string
 */
int _strlen(char *str)
{
	int length = 0;

	if (str == NULL)
		return (0);

	for (; *str != '\0'; str++)
		length++;

	return (length);
}
/**
 * _strcmp - performs lexicographic comparison of two strings.
 * @s1:first string
 * @s2:second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}


