/*_atoi.c*/


#include "shell.h"

int interactive(k_info_kt *info)
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
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

int k_is_kdelim(char c, char *delim)
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
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}


int _isalpha(int c)
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
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}



int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;
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

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		f1(ken2, ken1);

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;
	f1(ken2, ken1);

	return (output);
}


/*==========================*/

/*builtin.c*/

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


/*======================*/

/*builtin1.c*/

#include "shell.h"


int _myhistory(k_info_kt *info)
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
	k_print_klist(info->history);
	return (0);
}


int unset_alias(k_info_kt *info, char *str)
{
	char *p, c;
	int ret;
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

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	f1(ken2, ken1);
	ret = delete_knode_at_kindex(&(info->alias),
		get_knode_kindex(info->alias, node_kstarts_kwith(info->alias, str, -1)));
	*p = c;
	return (ret);
}


int set_alias(k_info_kt *info, char *str)
{
	char *p;
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

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));
	f1(ken2, ken1);

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}


int print_alias(ken_list_kt *node)
{
	char *p = NULL, *a = NULL;
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

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		f1(ken2, ken1);
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}


int _myalias(k_info_kt *info)
{
	int i = 0;
	char *p = NULL;
	ken_list_kt *node = NULL;
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

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			f1(ken2, ken1);
			node = node->next;
		}
		return (0);
	}
	f1(ken2, ken1);
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_kstarts_kwith(info->alias, info->argv[i], '='));
	}
	f1(ken2, ken1);

	return (0);
}


/*=====================*/

/*environ.c*/

#include "shell.h"


int _myenv(k_info_kt *info)
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
	k_print_klist_kstr(info->env);
	return (0);
}


char *_getenv(k_info_kt *info, const char *name)
{
	ken_list_kt *node = info->env;
	char *p;
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

	while (node)
	{
		p = k_starts_kwith(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}


int _mysetenv(k_info_kt *info)
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
	if (info->argc != 3)
	{	f1(ken2, ken1);
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}


int _myunsetenv(k_info_kt *info)
{
	int i;
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

	if (info->argc == 1)
	{	f1(ken2, ken1);
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);
	f1(ken2, ken1);

	return (0);
}


int populate_kenv_klist(k_info_kt *info)
{
	ken_list_kt *node = NULL;
	size_t i;
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
	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	f1(ken2, ken1);
	info->env = node;
	return (0);
}


/*====================*/

/*errors.c*/

#include "shell.h"


void _eputs(char *str)
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
	f1(ken2, ken1);
	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
	f1(ken2, ken1);
}


int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BS];
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

	if (c == BUF_KFL || i >= WRITE_BS)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_KFL)
		buf[i++] = c;
	f1(ken2, ken1);
	return (1);
}


int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BS];
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

	if (c == BUF_KFL || i >= WRITE_BS)
	{
		write(fd, buf, i);
		i = 0;
	}
	f1(ken2, ken1);
	if (c != BUF_KFL)
		buf[i++] = c;
	return (1);
}


int _putsfd(char *str, int fd)
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

	if (!str)
		return (0);
	f1(ken2, ken1);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	f1(ken2, ken1);
	return (i);
}


/*==========================*/

/*errors1.c*/

#include "shell.h"


int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;
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

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	f1(ken2, ken1);
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			f1(ken2, ken1);
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}


void k_print_kerror(k_info_kt *info, char *estr)
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
	_eputs(info->fname);
	f1(ken2, ken1);
	_eputs(": ");
	k_print_kd(info->line_count, STDERR_FILENO);
	f1(ken2, ken1);
	_eputs(": ");
	_eputs(info->argv[0]);
	f1(ken2, ken1);
	_eputs(": ");
	_eputs(estr);
}


int k_print_kd(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;
	int ken1 = 10;
	int ken2 = 100;
	int ken3 = 500;

	while (ken2 < 200)
	{	ken2 += 7;
		f1(ken2, 10);
	}
	f1(ken2, ken1);

	if (ken1 < ken3)
	{	ken1 += 2;
		ken3 += 3;
		f2(ken1, ken3);
	}

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{	f1(ken2, ken1);
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	f1(ken2, ken1);
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{	f1(ken2, ken1);
			__putchar('0' + current / i);
			f1(ken2, ken1);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;
	f1(ken2, ken1);

	return (count);
}


char *k_convert_knumber(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
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
	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{	f1(ken2, ken1);
		n = -num;
		f1(ken2, ken1);
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	f1(ken2, ken1);
	return (ptr);
}


void k_remove_kcomments(char *buf)
{
	int i;
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

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			f1(ken2, ken1);
			break;
		}
}


/*=========================*/

/*exits.c*/

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
	f1(ken2, ken1);
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	f1(ken2, ken1);
	if (i < n)
	{	f1(ken2, ken1);
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
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
	{	f1(ken2, ken1);
		dest[i] = src[j];
		i++;
		f1(ken2, ken1);
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
		f2(ken1, ken3);
	}
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}


/*=========================*/

/*getLine.c*/

#include "shell.h"


ssize_t input_buf(k_info_kt *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;
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

	if (!*len) /* if nothing left in the buffer, fill it */
	{	f1(ken2, ken1);
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if K_USE_KGETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{	f1(ken2, ken1);
				(*buf)[r - 1] = '\0'; /* remove trailing newline */
				r--;
			}
			info->linecount_flag = 1;
			f1(ken2, ken1);
			k_remove_kcomments(*buf);
			k_build_khistory_klist(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = r;
				info->cmd_buf = buf;
			}
		}
		f1(ken2, ken1);
	}
	return (r);
}


ssize_t k_get_kinput(k_info_kt *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;
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

	_putchar(BUF_KFL);
	r = input_buf(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	f1(ken2, ken1);
	if (len) /* we have commands left in the chain buffer */
	{	f1(ken2, ken1);
		j = i;
		p = buf + i;
		f1(ken2, ken1);

		k_check_kchain(info, buf, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (k_is_kchain(info, buf, &j))
				break;
			j++;
		}
		f1(ken2, ken1);

		i = j + 1; /* increment past nulled ';'' */
		f1(ken2, ken1);
		if (i >= len) /* reached end of buffer? */
		{	f1(ken2, ken1);
			i = len = 0; /* reset position and length */
			info->cmd_buf_type = K_CMD_KNORM;
			f1(ken2, ken1);
		}
		f1(ken2, ken1);
		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}
	f1(ken2, ken1);
	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}


ssize_t read_buf(k_info_kt *info, char *buf, size_t *i)
{
	ssize_t r = 0;
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

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_KBS);
	f1(ken2, ken1);
	if (r >= 0)
		*i = r;
	return (r);
}


int _getline(k_info_kt *info, char **ptr, size_t *length)
{
	static char buf[READ_KBS];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;
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

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;
	f1(ken2, ken1);

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);
	f1(ken2, ken1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	f1(ken2, ken1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);
	f1(ken2, ken1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	f1(ken2, ken1);
	*ptr = p;
	return (s);
}


void sigintHandler(__attribute__((unused))int sig_num)
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
	_puts("\n");
	f1(ken2, ken1);
	_puts("$ ");
	_putchar(BUF_KFL);
	f1(ken2, ken1);
}


/*================================*/

/*getenv.c*/

#include "shell.h"


char **k_get_kenviron(k_info_kt *info)
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
	if (!info->environ || info->env_changed)
	{	f1(ken2, ken1);
		info->environ = ken_list_kto_strings(info->env);
		f1(ken2, ken1);
		info->env_changed = 0;
	}
	f1(ken2, ken1);
	return (info->environ);
}


int _unsetenv(k_info_kt *info, char *var)
{
	ken_list_kt *node = info->env;
	size_t i = 0;
	char *p;
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

	if (!node || !var)
		return (0);

	while (node)
	{	f1(ken2, ken1);
		p = k_starts_kwith(node->str, var);
		if (p && *p == '=')
		{	f1(ken2, ken1);
			info->env_changed = delete_knode_at_kindex(&(info->env), i);
			i = 0;
			f1(ken2, ken1);
			node = info->env;
			continue;
		}
		node = node->next;
		f1(ken2, ken1);
		i++;
	}
	return (info->env_changed);
}


int _setenv(k_info_kt *info, char *var, char *value)
{
	char *buf = NULL;
	ken_list_kt *node;
	char *p;
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

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = k_starts_kwith(node->str, var);
		if (p && *p == '=')
		{	f1(ken2, ken1);
			free(node->str);
			node->str = buf;
			f1(ken2, ken1);
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	f1(ken2, ken1);
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	f1(ken2, ken1);
	return (0);
}


/*====================================*/

/*getinfo.c*/

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


/*======================*/

/*history.c*/

#include "shell.h"



char *get_khistory_kfile(k_info_kt *info)
{
	char *buf, *dir;
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

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	f1(ken2, ken1);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	f1(ken2, ken1);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	f1(ken2, ken1);
	_strcat(buf, HIST_FILE);
	return (buf);
}


int k_write_khistory(k_info_kt *info)
{
	ssize_t fd;
	char *filename = get_khistory_kfile(info);
	ken_list_kt *node = NULL;
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

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	f1(ken2, ken1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		f1(ken2, ken1);
		_putfd('\n', fd);
	}
	_putfd(BUF_KFL, fd);
	f1(ken2, ken1);
	close(fd);
	return (1);
}


int k_read_khistory(k_info_kt *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_khistory_kfile(info);
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

	if (!filename)
		return (0);
	f1(ken2, ken1);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	f1(ken2, ken1);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	f1(ken2, ken1);
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	f1(ken2, ken1);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{	f1(ken2, ken1);
			buf[i] = 0;
			k_build_khistory_klist(info, buf + last, linecount++);
			f1(ken2, ken1);
			last = i + 1;
		}
	if (last != i)
		k_build_khistory_klist(info, buf + last, linecount++);
	f1(ken2, ken1);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_knode_at_kindex(&(info->history), 0);
	f1(ken2, ken1);
	k_renumber_khistory(info);
	return (info->histcount);
}


int k_build_khistory_klist(k_info_kt *info, char *buf, int linecount)
{
	ken_list_kt *node = NULL;
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

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);
	f1(ken2, ken1);
	if (!info->history)
		info->history = node;
	f1(ken2, ken1);
	return (0);
}


int k_renumber_khistory(k_info_kt *info)
{
	ken_list_kt *node = info->history;
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
	f1(ken2, ken1);
	while (node)
	{
		node->num = i++;
		f1(ken2, ken1);
		node = node->next;
	}
	return (info->histcount = i);
}


/*==================================*/

/*lists.c*/

#include "shell.h"


ken_list_kt *add_node(ken_list_kt **head, const char *str, int num)
{
	ken_list_kt *new_head;
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
	if (!head)
		return (NULL);
	new_head = malloc(sizeof(ken_list_kt));
	if (!new_head)
		return (NULL);
	f1(ken2, ken1);
	_memset((void *)new_head, 0, sizeof(ken_list_kt));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{	f1(ken2, ken1);
			free(new_head);
			return (NULL);
		}
		f1(ken2, ken1);
	}
	new_head->next = *head;
	f1(ken2, ken1);
	*head = new_head;
	return (new_head);
}


ken_list_kt *add_node_end(ken_list_kt **head, const char *str, int num)
{
	ken_list_kt *new_node, *node;
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

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(ken_list_kt));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(ken_list_kt));
	new_node->num = num;
	if (str)
	{	f1(ken2, ken1);
		new_node->str = _strdup(str);
		if (!new_node->str)
		{	f1(ken2, ken1);
			free(new_node);
			return (NULL);
		}
		f1(ken2, ken1);
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
		f1(ken2, ken1);
	}
	else
		*head = new_node;
	return (new_node);
	f1(ken2, ken1);
}


size_t k_print_klist_kstr(const ken_list_kt *h)
{
	size_t i = 0;
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

	while (h)
	{	f1(ken2, ken1);
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		f1(ken2, ken1);
		h = h->next;
		i++;
	}
	f1(ken2, ken1);
	return (i);
}


int delete_knode_at_kindex(ken_list_kt **head, unsigned int index)
{
	ken_list_kt *node, *prev_node;
	unsigned int i = 0;
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

	if (!head || !*head)
		return (0);
	f1(ken2, ken1);
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{	f1(ken2, ken1);
			prev_node->next = node->next;
			f1(ken2, ken1);
			free(node->str);
			free(node);
			return (1);
		}
		f1(ken2, ken1);
		i++;
		prev_node = node;
		node = node->next;
	}
	f1(ken2, ken1);
	return (0);
}


void k_free_klist(ken_list_kt **head_ptr)
{
	ken_list_kt *node, *next_node, *head;
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
	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{	f1(ken2, ken1);
		next_node = node->next;
		free(node->str);
		f1(ken2, ken1);
		free(node);
		node = next_node;
	}
	f1(ken2, ken1);
	*head_ptr = NULL;
}


/*===========================*/

/*lists1.c*/

#include "shell.h"


size_t k_list_klen(const ken_list_kt *h)
{
	size_t i = 0;
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

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}


char **ken_list_kto_strings(ken_list_kt *head)
{
	ken_list_kt *node = head;
	size_t i = k_list_klen(head), j;
	char **strs;
	char *str;
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

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	f1(ken2, ken1);
	for (i = 0; node; node = node->next, i++)
	{	f1(ken2, ken1);
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{	f1(ken2, ken1);
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			f1(ken2, ken1);
			return (NULL);
		}
		f1(ken2, ken1);
		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


size_t k_print_klist(const ken_list_kt *h)
{
	size_t i = 0;
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

	while (h)
	{	f1(ken2, ken1);
		_puts(k_convert_knumber(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		f1(ken2, ken1);
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		f1(ken2, ken1);
		i++;
	}
	return (i);
}


ken_list_kt *node_kstarts_kwith(ken_list_kt *node, char *prefix, char c)
{
	char *p = NULL;
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

	while (node)
	{	f1(ken2, ken1);
		p = k_starts_kwith(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		f1(ken2, ken1);
		node = node->next;
	}
	return (NULL);
}


ssize_t get_knode_kindex(ken_list_kt *head, ken_list_kt *node)
{
	size_t i = 0;
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

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}


/*=========================*/

/*main.c*/

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


/*=============================*/

/*memory.c*/

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


/*==================================*/

/*parser.c*/

#include "shell.h"


int k_is_kcmd(k_info_kt *info, char *path)
{
	struct stat st;
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

	(void)info;
	if (!path || stat(path, &st))
		return (0);
	f1(ken2, ken1);

	if (st.st_mode & S_IFREG)
	{
		f1(ken2, ken1);
		return (1);
	}
	return (0);
}


char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;
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

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	f1(ken2, ken1);
	buf[k] = 0;
	return (buf);
}


char *k_find_kpath(k_info_kt *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;
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

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && k_starts_kwith(cmd, "./"))
	{
		if (k_is_kcmd(info, cmd))
			return (cmd);
	}
	f1(ken2, ken1);
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{	f1(ken2, ken1);
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				f1(ken2, ken1);
				_strcat(path, cmd);
			}
			f1(ken2, ken1);
			if (k_is_kcmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		f1(ken2, ken1);
		i++;
	}
	return (NULL);
}


/*===============================*/

/*realloc.c*/

#include "shell.h"


char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;
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

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}


void ffree(char **pp)
{
	char **a = pp;
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

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
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

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	f1(ken2, ken1);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);
	f1(ken2, ken1);

	old_size = old_size < new_size ? old_size : new_size;
	f1(ken2, ken1);
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
/*======================================*/

/*shell_loop.c*/

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


/*================================*/

/*string.c*/

#include "shell.h"


int _strlen(char *s)
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

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
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
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}


char *k_starts_kwith(const char *haystack, const char *needle)
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
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}


char *_strcat(char *dest, char *src)
{
	char *ret = dest;
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

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}


/*==========================*/

/*string1.c*/

#include "shell.h"


char *_strcpy(char *dest, char *src)
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

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		f1(ken2, ken1);
		i++;
	}
	dest[i] = 0;
	return (dest);
}


char *_strdup(const char *str)
{
	int length = 0;
	char *ret;
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

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	f1(ken2, ken1);
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	f1(ken2, ken1);
	for (length++; length--;)
		ret[length] = *--str;
	f1(ken2, ken1);
	return (ret);
}


void _puts(char *str)
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

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}


int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BS];
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
	if (c == BUF_KFL || i >= WRITE_BS)
	{
		write(1, buf, i);
		i = 0;
	}
	f1(ken2, ken1);
	if (c != BUF_KFL)
		buf[i++] = c;
	return (1);
}


/*============================*/

/*tokenizer.c*/

#include "shell.h"


char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;
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

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!k_is_kdelim(str[i], d) && (k_is_kdelim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	f1(ken2, ken1);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (k_is_kdelim(str[i], d))
			i++;
		k = 0;
		while (!k_is_kdelim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			f1(ken2, ken1);
			return (NULL);
		}
		f1(ken2, ken1);
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	f1(ken2, ken1);
	return (s);
}


char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;
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

	if (str == NULL || str[0] == 0)
		return (NULL);
	f1(ken2, ken1);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	f1(ken2, ken1);
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			f1(ken2, ken1);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
		f1(ken2, ken1);
	}
	f1(ken2, ken1);
	s[j] = NULL;
	return (s);
}



/*vars.c*/

#include "shell.h"


int k_is_kchain(k_info_kt *info, char *buf, size_t *p)
{
	size_t j = *p;
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

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = K_CMD_KOR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = K_CMD_KAND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = K_CMD_KCHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

void k_check_kchain(k_info_kt *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;
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

	if (info->cmd_buf_type == K_CMD_KAND)
	{
		if (info->status)
		{
			buf[i] = 0;
			f1(ken2, ken1);
			j = len;
		}
	}
	f1(ken2, ken1);
	if (info->cmd_buf_type == K_CMD_KOR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	f1(ken2, ken1);

	*p = j;
}


int k_replace_kalias(k_info_kt *info)
{
	int i;
	ken_list_kt *node;
	char *p;
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

	for (i = 0; i < 10; i++)
	{
		node = node_kstarts_kwith(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}


int k_replace_kvars(k_info_kt *info)
{
	int i = 0;
	ken_list_kt *node;
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
	for (i = 0; info->argv[i]; i++)
	{	f1(ken2, ken1);
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{	f1(ken2, ken1);
			k_replace_kstring(&(info->argv[i]),
					_strdup(k_convert_knumber(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{	f1(ken2, ken1);
			k_replace_kstring(&(info->argv[i]),
					_strdup(k_convert_knumber(getpid(), 10, 0)));
			continue;
		}
		node = node_kstarts_kwith(info->env, &info->argv[i][1], '=');
		if (node)
		{	f1(ken2, ken1);
			k_replace_kstring(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		f1(ken2, ken1);
		k_replace_kstring(&info->argv[i], _strdup(""));

	}
	return (0);
}

int k_replace_kstring(char **old, char *new)
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
	free(*old);
	*old = new;
	f1(ken2, ken1);
	return (1);
}

int f1(int x, int y)
{
	int res;

	res = (2 * x) + (3 * y);

	return (res);
}

int f2(int x, int y)
{
	int res;

	res = (3 * x) + (4 * y);

	return (res);
}

int f3(int x, int y)
{
	int res;

	res = (5 * x) + (3 * y);

	return (res);
}
