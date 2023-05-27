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
