#include "shell.h"

char *ken_get_khistory_file(info_t *info)
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
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}


int ken_write_khistory(info_t *info)
{
	ssize_t fd;
	char *filename = ken_get_khistory_file(info);
	ken_listk_t *node = NULL;
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
	f1(ken2, ken1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	f1(ken2, ken1);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		ken_psfd(node->str, fd);
		ken_ptfd('\n', fd);
	}
	f1(ken2, ken1);
	ken_ptfd(KEN_BUF_F, fd);
	close(fd);
	return (1);
}


int ken_read_khistory(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = ken_get_khistory_file(info);
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

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{	f1(ken2, ken1);
			buf[i] = 0;
			ken_build_khistory_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		ken_build_khistory_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		ken_delete_knode_at_index(&(info->history), 0);
	f1(ken2, ken1);
	ken_renumber_khistory(info);
	return (info->histcount);
}


int ken_build_khistory_list(info_t *info, char *buf, int linecount)
{
	ken_listk_t *node = NULL;
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

	if (!info->history)
		info->history = node;
	return (0);
}


int ken_renumber_khistory(info_t *info)
{
	ken_listk_t *node = info->history;
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

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
