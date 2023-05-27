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
