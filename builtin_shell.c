#include "shell.h"

int _myexit(k_info_kt *info)
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
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			f1(ken2, ken1);
			k_print_kerror(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			f1(ken2, ken1);
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		f1(ken2, ken1);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}


int _mycd(k_info_kt *info)
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
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{	f1(ken2, ken1);
			_puts(s);
			_putchar('\n');
			return (1);
		}
		f1(ken2, ken1);
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		f1(ken2, ken1);
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		k_print_kerror(info, "can't cd to ");
		f1(ken2, ken1);
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		f1(ken2, ken1);
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}


int _myhelp(k_info_kt *info)
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
