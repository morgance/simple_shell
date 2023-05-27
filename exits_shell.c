#include "shell.h"


char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;
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

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		f1(ken2, ken1);
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
		f1(ken2, ken1);
	}
	f1(ken2, ken1);
	return (s);
}


char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;
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

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		f1(ken2, ken1);
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	f1(ken2, ken1);
	return (s);
}


char *_strchr(char *s, char c)
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
		f1(ken2, ken1);
		f2(ken1, ken3);
	}

	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	f1(ken2, ken1);

	return (NULL);
}
