#include "shell.h"


int bfree(void **ptr)
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
	if (ptr && *ptr)
	{	f1(ken2, ken1);
		free(*ptr);
		*ptr = NULL;
		f1(ken2, ken1);
		return (1);
	}
	f1(ken2, ken1);
	return (0);
}
