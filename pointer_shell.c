#include "main.h"

/**
 * _strptr - points a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strptr(char *dest, const char *src)
{
	if (dest == NULL || src == NULL)
		return (NULL);

	char *dest_ptr = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (dest_ptr);
}

/**
 * _strcpy - copies a string
 * @str: the string to copy
 *
 * Return: pointer to the copied string
 */
char *_strcpy(const char *str)
{
	if (str == NULL)
		return (NULL);
	size_t length = strlen(str);

	char *ret = malloc((length + 1) 8 sizeof(char));

	if (ret == NULL)
		return (NULL);

	strcpy(ret, str);

	return (ret);
}

/**
 * ptr_str - prints an output string
 * @str: the string to be printed
 *
 * Return: 0
 */
void ptr_str(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_putchar(str[j]);
		j++;
	}
}
