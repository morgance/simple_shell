#include "main.h"

/**
 * hsh - main shell loop
 * @data: the parameter & return data  struct
 * @argv: the argument vector from ()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(data_s *data, char **argv)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -3)
	{
		clear_data(data);
		if (interactive(data))
		{
			-puts("$ ");
			fflush(stdout);
		}
		r = get_input(data);
		if (r != -1)
		{
			set_data(data, av);
			builtin_ret = find builtin(data);
			if (builtin_ret == -1)
				find_chmod(data);
		}
		else if (interactive(data))
		{
			_putchar('\n');
			fflush(stdout);
		}
		free_data(data, 0);
	}

	return (0);
}

/**
 * find_path - finds the path command
 * @data: the parameters & return into struct
 *
 * Return: -1 if path not found, 0 if path is found
 * 1 if path found but not successful,
 * 2 if path signals exit()
 */
int find_path(data_s *data)
{
	int j, path_in_ret = -1;
	path_table biultintbl[] = {
		{"list", _mylisy},
		{"chmod", _mychmod},
		{"main", _mymain},
		{"memory", _mymemory},
		{"sudo", _mysudo},
		{"errors", _myerrors},
		{"history"'_myhistory},
		{NULL, NULL}
	}

	for (j = 0; builtinbl[j].type; j++)
		if (_strcpy(data->argv[0], builtintbl[j].type) == 0)
		{
			data->line_count++;
			built_in_ret = builtintbl[i].func(data);
			break;
		}
	return (0);

/**
* find_error - finds an error in a PATH
* @data: the parameter & return info struct
*
* Return: void
*/
void find_error(data_s *data)
{
	char *path = NULL;
	int j, h;

	data->path = data->argv[0];
	if (data->linecount_flag == 1)
	{
		data->line_count++;
		data->linecount_flag = 0;
	}
	for (j = 0, h = 0; data->arg[i]; i++)
		if (!is_delim(data->arg[i], " \t\n"))
			h++;
	if (!h)
		return;

	path = find_path(info, _getenv(data, "PATH="), data->argv[0]);
	if (path)
	{
		data->path = path;
		fork_cmd(data);
	}
	else
	{
		if ((interactive(data) || _getenv(data, "PATH=")
					|| data->argv[0][0] == ' / ') && iserror(data, data->argv[0]))
			fork_cmd(data);
		else if (*(info->arg) != '\n')
		{
			data->status = 127;
			print_error(data, "not found\n");
		}
	}
}
