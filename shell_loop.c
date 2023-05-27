#include "shell.h"

int hsh(k_info_kt *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;
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

	while (r != -1 && builtin_ret != -2)
	{
		k_clear_kinfo(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_KFL);
		r = k_get_kinput(info);
		if (r != -1)
		{
			k_set_kinfo(info, av);
			builtin_ret = k_find_kbuiltin(info);
			if (builtin_ret == -1)
				k_find_kcmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		k_free_kinfo(info, 0);
	}
	k_write_khistory(info);
	k_free_kinfo(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	f1(ken2, ken1);
	return (builtin_ret);
}


int k_find_kbuiltin(k_info_kt *info)
{
	int i, built_in_ret = -1;
	k_builtin_ktable builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};
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

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			f1(ken2, ken1);
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	f1(ken2, ken1);
	return (built_in_ret);
}


void k_find_kcmd(k_info_kt *info)
{
	char *path = NULL;
	int i, k;
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

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!k_is_kdelim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = k_find_kpath(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		f1(ken2, ken1);
		k_fork_kcmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && k_is_kcmd(info, info->argv[0]))
			k_fork_kcmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			f1(ken2, ken1);
			k_print_kerror(info, "not found\n");
		}
		f1(ken2, ken1);
	}
}


void k_fork_kcmd(k_info_kt *info)
{
	pid_t child_pid;
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

	child_pid = fork();
	if (child_pid == -1)
	{	f1(ken2, ken1);
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, k_get_kenviron(info)) == -1)
		{	f1(ken2, ken1);
			k_free_kinfo(info, 1);
			f1(ken2, ken1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			f1(ken2, ken1);
			if (info->status == 126)
				k_print_kerror(info, "Permission denied\n");
		}
		f1(ken2, ken1);
	}
}
