#include "shell.h"

int main(int ac, char **av)
{
	k_info_kt info[] = { INFO_INIT };
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
	f1(ken2, ken1);
	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));
	f1(ken2, ken1);

	if (ac == 2)
	{	f1(ken2, ken1);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{	f1(ken2, ken1);
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{	f1(ken2, ken1);
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				f1(ken2, ken1);
				_eputchar(BUF_KFL);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		f1(ken2, ken1);
		info->readfd = fd;
	}
	f1(ken2, ken1);
	populate_kenv_klist(info);
	k_read_khistory(info);
	hsh(info, av);
	f1(ken2, ken1);
	return (EXIT_SUCCESS);
}
