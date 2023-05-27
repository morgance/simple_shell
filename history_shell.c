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
