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

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_epucha(str[i]);
		i++;
	}
}


int _epucha(char c)
{
	static int i;
	static char buf[KEN_WRITE_BS];
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

	if (c == KEN_BUF_F || i >= KEN_WRITE_BS)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != KEN_BUF_F)
		buf[i++] = c;
	return (1);
}


int ken_ptfd(char c, int fd)
{
	static int i;
	static char buf[KEN_WRITE_BS];
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

	if (c == KEN_BUF_F || i >= KEN_WRITE_BS)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != KEN_BUF_F)
		buf[i++] = c;
	return (1);
}


int ken_psfd(char *str, int fd)
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
	while (*str)
	{
		i += ken_ptfd(*str++, fd);
	}
	return (i);
}
