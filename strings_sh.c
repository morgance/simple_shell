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
/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle && *haystack)
	{
		if (*needle != *haystack)
			return (NULL);
		needle++;
		haystack++;
	}

	if (*needle == '\0')
		return (char *)haystack;
	else
		return (NULL);
}
/**
 * _strcat - concatenates two strings
 * @dest:destination buffer
 * @src:source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, const char *src)
{
	char *prim = dest;

	while (*dest)
		dest++;
	
	while (*src)
		*dest++ = *src++;
	
	*dest = '\0';
	
	return (prim);
}




