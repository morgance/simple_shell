#include "shell.h"


int main(int ac, char **av)
{
	info_t info[] = { INF_INT };
	int fd = 2;
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

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{	f1(ken2, ken1);
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{	f1(ken2, ken1);
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				f1(ken2, ken1);
				_eputs(av[1]);
				_epucha('\n');
				f1(ken2, ken1);
				_epucha(KEN_BUF_F);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	f1(ken2, ken1);
	pop_envlist(info);
	ken_read_khistory(info);
	f1(ken2, ken1);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
