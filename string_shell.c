#include "main.h"
/**
 * copy_str - copies a string
 * @prim:where its being copied to
 * @frm:were its coppying from
 *
 * Return: pointer to the destination
 */
char *copy_str(char *prim, const char frm)
{
	if (prim == frm || frm == 0)
		return (prim);

	char *dest_start = prim;

	while (*frm)
	{
		*prim = *frm;
		prim++;
		frm++;
	}
	*prim = '\0';
	return (dest_start);
}
/**
 * duplic_str - duplicates a string
 * @strng:string to duplicate
 *
 * Return:duplicated  string
 */
char *duplic_str(const char *strng)
{
	if (strng == NULL)
		return (NULL);
	int dup = 0;
	const char *str_ptr = strng;

	while (*str_ptr)
	{
		dup++;
		str_ptr++;
	}

	char *duplicate = malloc(sizeof(char) * (dup + 1));

	if (duplicate == NULL)
		return (NULL);

	char *duplicate_ptr = duplicate;

	str_ptr = strng;

	while (*str_ptr)
	{
		*duplicate_ptr = *str_ptr;
		duplicate_ptr++;
		str_ptr++;
	}
	*duplicate_ptr = '\0';
	return (duplicate);
}
/**
 * print_inp - prints input string
 * @strng:string to be printed
 *
 * Return:void
 */
void print_inp(const char *strng)
{
	if (strng == NULL)
		return;
	const char *str_ptr = strng;

	while (*str_ptr != '\0')
	{
		_putchar(*str_ptr);
		str_ptr++;
	}
}
/**
 * _putchar - write character c
 * @c:the character to print
 *
 *  Return:1 if succesful,-1 otherwise
 */
int _putchar(char c)
{
	static int j;
	static char fub[WRITE_BUFF];

	if (c == FLUSH_BUFF || j >= WRITE_BUFF)
	{
		write(STDOUT_FILENO, fub, j);
		j = 0;
	}
	if (c != FLUSH_BUFF)
		fub[j++] = c;

	return (1);
}
