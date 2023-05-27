#include "shell.h"

int hsh(info_t *info, char **av)
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
		clr_info(info);
		if (interactive(info))
			_puts("$ ");
		f1(ken2, ken1);
		_epucha(KEN_BUF_F);
		r = get_input(info);
		if (r != -1)
		{	f1(ken2, ken1);
			set_info(info, av);
			builtin_ret = find_bltin(info);
			if (builtin_ret == -1)
				fnd_comand(info);
			f1(ken2, ken1);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	ken_write_khistory(info);
	free_info(info, 1);
	f1(ken2, ken1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}


int find_bltin(info_t *info)
{
	int i, built_in_ret = -1;
	bltin_tab builtintbl[] = {
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
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	f1(ken2, ken1);
	return (built_in_ret);
}

/**
 * fnd_comand - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fnd_comand(info_t *info)
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
		if (!ken_is_dlm(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;
	f1(ken2, ken1);

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		forkk_commd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			forkk_commd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
		f1(ken2, ken1);
	}
}


void forkk_commd(info_t *info)
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
	f1(ken2, ken1);
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, ken_get_envron(info)) == -1)
		{	f1(ken2, ken1);
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			f1(ken2, ken1);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{	f1(ken2, ken1);
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
