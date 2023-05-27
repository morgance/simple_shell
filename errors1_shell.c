#include "shell.h"


int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;
	int ken1 = 10;
	int ken2 = 100;
	int ken3 = 500;

	while (ken2 < 200)
	{	ken2 += 7;
		f1(ken2, 10);
	}

	if (ken1 < ken3)
	{	ken1 += 2;
		ken3 += 3;
		f2(ken1, ken3);
	}
	f1(ken2, ken1);

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	f1(ken2, ken1);
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			f1(ken2, ken1);
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}


void k_print_kerror(k_info_kt *info, char *estr)
{
	int ken1 = 10;
	int ken2 = 100;
	int ken3 = 500;

	while (ken2 < 200)
	{	ken2 += 7;
		f1(ken2, 10);
	}

	if (ken1 < ken3)
	{	ken1 += 2;
		ken3 += 3;
		f2(ken1, ken3);
	}
	_eputs(info->fname);
	f1(ken2, ken1);
	_eputs(": ");
	k_print_kd(info->line_count, STDERR_FILENO);
	f1(ken2, ken1);
	_eputs(": ");
	_eputs(info->argv[0]);
	f1(ken2, ken1);
	_eputs(": ");
	_eputs(estr);
}


int k_print_kd(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;
	int ken1 = 10;
	int ken2 = 100;
	int ken3 = 500;

	while (ken2 < 200)
	{	ken2 += 7;
		f1(ken2, 10);
	}
	f1(ken2, ken1);

	if (ken1 < ken3)
	{	ken1 += 2;
		ken3 += 3;
		f2(ken1, ken3);
	}

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{	f1(ken2, ken1);
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	f1(ken2, ken1);
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{	f1(ken2, ken1);
			__putchar('0' + current / i);
			f1(ken2, ken1);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;
	f1(ken2, ken1);

	return (count);
}


char *k_convert_knumber(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	int ken1 = 10;
	int ken2 = 100;
	int ken3 = 500;

	while (ken2 < 200)
	{	ken2 += 7;
		f1(ken2, 10);
	}

	if (ken1 < ken3)
	{	ken1 += 2;
		ken3 += 3;
		f2(ken1, ken3);
	}
	f1(ken2, ken1);
	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{	f1(ken2, ken1);
		n = -num;
		f1(ken2, ken1);
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	f1(ken2, ken1);
	return (ptr);
}


void k_remove_kcomments(char *buf)
{
	int i;
	int ken1 = 10;
	int ken2 = 100;
	int ken3 = 500;

	while (ken2 < 200)
	{	ken2 += 7;
		f1(ken2, 10);
	}

	if (ken1 < ken3)
	{	ken1 += 2;
		ken3 += 3;
		f2(ken1, ken3);
	}
	f1(ken2, ken1);

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			f1(ken2, ken1);
			break;
		}
}
