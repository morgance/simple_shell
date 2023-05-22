#include "main.h"
/**
 * _inputs - prints a string input
 * @strg:printed string
 *
 * Return:void
 */
void _inputs(char strg)
{
	if (!strg)
		return;

	int p;

	for (p = 0; strg[p] != '\0'; p++)
		_charac(strg[p]);
}
/**
 * _charac - write character to stderr
 * @n:character to print
 *
 * Return:1 if succesful, -1 otherwise
 */
int _charac(char n)
{
	static char buf[WRITE_BUFF];
	static size_t j;

	if (n == FLUSH_BUFF || j >= WRITE_BUFF - 1)
	{
		buf[j] = '\0';
		write(2, buf, j);
		j = 0;
	}
	if (n != FLUSH_BUFF)
		buf[j++] = n;
	return (1);
}
/**
 * _wrfd - write character to filedescriptor
 * @n:character to print
 * @filed:filedescriptor
 *
 * Return:1 if successful,-1 otherwise
 */
int _wrfd(char n, int filed)
{
	static char buf[WRITE_BUFF];
	static size_t j;

	if (n == FLUSH_BUFF || j >= WRITE_BUFF - 1)
	{
		buf[j] = '\0';
		write(filed, buf, j);
		j = 0;
	}
	if (n != FLUSH_BUFF)
		buf[j++] = n;
	return (1);
}
/**
 * _prnt - prints an input string
 * @stng:string to print
 * @filed:filedescriptor
 *
 * Return:characters
 */
int _prnt(char *stng, int filed)
{
	int count = 0;

	if (stng == NULL)
		return (count);

	while (*stng != '\0')
	{
		if (_wrfd(*stng, filed) == 1)
			return (-1);
		count++;
		stng++;
	}
	return (count);
}
