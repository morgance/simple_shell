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

