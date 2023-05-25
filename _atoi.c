#include "main.h"
#include <unistd.h>

/**
 * collective - checks if the shell is running in collective mode
 * @data: pointer to info_t struct
 *
 * Return: 1 if running in collective mode, 0 otherwise
 */
int collective(data_s *data)
{
	return (isatty(STDIN_FILENO) && data->read_in <= 2);
}

/**
 * is_lim - checks if a character is a limiter
 * @c: the character to check
 * @lim: the limiter string
 * Return: 1 if it is a limiter, 0 otherwise
 */
int is_lim(char c, char *lim)
{
	while (*lim != '\0')
	{
		if (*lim == c)
			return (1);
		lim++;
	}
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: the character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no number in string, converted number otherwise
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result = result * 10 + (s[i] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
	}

	return (sign * result);
}
