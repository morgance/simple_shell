#include "shell.h"


void k_clear_kinfo(k_info_kt *info)
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
	f1(ken2, ken1);
	info->arg = NULL;
	info->argv = NULL;
	f1(ken2, ken1);
	info->path = NULL;
	info->argc = 0;
}


void k_set_kinfo(k_info_kt *info, char **av)
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

	info->fname = av[0];
	if (info->arg)
	{	f1(ken2, ken1);
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{	f1(ken2, ken1);
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{	f1(ken2, ken1);
				info->argv[0] = _strdup(info->arg);
				f1(ken2, ken1);
				info->argv[1] = NULL;
			}
		}
		f1(ken2, ken1);
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		k_replace_kalias(info);
		f1(ken2, ken1);
		k_replace_kvars(info);
	}
}


void k_free_kinfo(k_info_kt *info, int all)
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
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{	f1(ken2, ken1);
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			k_free_klist(&(info->env));
		f1(ken2, ken1);
		if (info->history)
			k_free_klist(&(info->history));
		f1(ken2, ken1);
		if (info->alias)
			k_free_klist(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		f1(ken2, ken1);
		if (info->readfd > 2)
			close(info->readfd);
		f1(ken2, ken1);
		_putchar(BUF_KFL);
	}
}
