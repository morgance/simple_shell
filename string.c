#include "main.h"

/**
 * get_string_file - gets the string of a file
 * @data: parameter struct
 *
 * Return: allocated strings containing file
 */
char *get_string_file(data_s *data)
{
	char *buf, *dir;

	dir = _getenv(data, "SCHOOL=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(STR_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, STR_FILE);
	return (buf);
}

/**
 * write_history - creates a file, or appends to an existing file
 * @data: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_string(data_ *data)
{
	int fd;
	char *filename = get_string_file(data);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, 0_CREAT | 0_WRONLY | 0_APPEND, 0644);
	free(filename);

	if (fd == -1)
		return (-1);

	for (node = data->string; node; node = node->next)
	{
		if (_putsfd(node->str, fd) == -1)
		{
			close(fd);
			return (-1);
		}
		if (_putfd('\n', fd) == -1)
		{
			close(fd);
			return (-1);
		}
	}

	if (_putfd(FLUSH_BUFF, fd) == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}

/**
 * read_string - reads history from file
 * @data: the parameter struct
 *
 * Return: strngcount on success, 0 otherwise
 */
int read_string(data_s *data)
{
	int i, last = 0, linecount = 0;
	int fd;
	ssize_t rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_string_file(data);

	if (!filename)
		return (0);
	fd = open(filename, 0_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);

	if (fstat(fd, &st) != 0)
	{
		close(fd);
		return (0);
	}

	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
	{
		close(fd);
		return (0);
	}

	rdlen = read(fd, buf, fsize);
	buf[fsize] = '\0';
	if (rdlen <= 0)
	{
		free(buf);
		close(fd);
		return (0);
	}

	close(fd);

	for (i = 0; i < fsize; i++)
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			build_string_list(data, buf + last, linecount++);
			last = i + 1;
		}
	}

	if (last != i)
		 build_string_list(data, buf + last, linecount++);

	free(buf);
	info->strcount = linecount;

	while (data->strng-- >= STR_MAX)
		delete_node_at_index(&(data->former_n), 0);

	renumber_string(data);

	return (data->strcount);
}
