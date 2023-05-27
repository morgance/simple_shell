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
