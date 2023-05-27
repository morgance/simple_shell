#include "shell.h"


void _eputs(char *str)
{
	int i = 0;
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
	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
	f1(ken2, ken1);
}


int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BS];
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

	if (c == BUF_KFL || i >= WRITE_BS)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_KFL)
		buf[i++] = c;
	f1(ken2, ken1);
	return (1);
}


int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BS];
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

	if (c == BUF_KFL || i >= WRITE_BS)
	{
		write(fd, buf, i);
		i = 0;
	}
	f1(ken2, ken1);
	if (c != BUF_KFL)
		buf[i++] = c;
	return (1);
}


int _putsfd(char *str, int fd)
{
	int i = 0;
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

	if (!str)
		return (0);
	f1(ken2, ken1);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	f1(ken2, ken1);
	return (i);
}
