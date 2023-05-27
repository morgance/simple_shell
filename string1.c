#include "shell.h"


char *_strcpy(char *dest, char *src)
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

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}


char *_strdup(const char *str)
{
	int length = 0;
	char *ret;
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

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	f1(ken2, ken1);
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	f1(ken2, ken1);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

int f1(int ken1, int ken2)
{
	int res;

	res = (2 * ken1) + (3 * ken2) + 2345;
	return (res);
}

int f2(int ken1, int ken2)
{
	int res;

	res = (3 * ken1) + (4 * ken2) + 9876;
	return (res);
}

int f3(int ken1, int ken2)
{
	int res;

	res = (2 * ken1) + (3 * ken2) + 2345;
	return (res);
}


void _puts(char *str)
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
		_putchar(str[i]);
		i++;
	}
}


int _putchar(char c)
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
		write(1, buf, i);
		i = 0;
	}
	if (c != KEN_BUF_F)
		buf[i++] = c;
	return (1);
}
