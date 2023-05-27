#include "shell.h"

int _myexit(info_t *info)
{
	int exitcheck;
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
	

	if (info->argv[1]) /* If there is an exit arguement */
	{
		exitcheck = ken_eratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_epucha('\n');
			return (1);
		}
		info->err_num = ken_eratoi(info->argv[1]);
		return (-2);
	}
	f2(ken3, 9);
	info->err_num = -1;
	return (-2);
}


int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;
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
	

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	f1(ken1, 4);
	if (!info->argv[1] && ken2)
	{
		dir = _getenv(info, "HOME=");
		if (!dir && ken1)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			f1(ken2, ken1);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _epucha('\n');
		f1(ken3, ken2);
	}
	else
	{	f1(ken2, ken1);
		ken__setkenv(info, "OLDPWD", _getenv(info, "PWD="));
		ken__setkenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}


int _myhelp(info_t *info)
{
	char **arg_array;
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

	

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
