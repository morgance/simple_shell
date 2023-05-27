#include "shell.h"


char **ken_get_envron(info_t *info)
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
	{
		f1(ken2, ken1);
		info->environ = ken_listk_to_strings(info->env);
		info->env_changed = 0;
	}
	f1(ken2, ken1);

	return (info->environ);
}


int ken__unsektenv(info_t *info, char *var)
{
	ken_listk_t *node = info->env;
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
	f1(ken2, ken1);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = ken_delete_knode_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	f1(ken2, ken1);
	return (info->env_changed);
}


int ken__setkenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	ken_listk_t *node;
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
	f1(ken2, ken1);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	f1(ken2, ken1);
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			f1(ken2, ken1);
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	f1(ken2, ken1);
	info->env_changed = 1;
	return (0);
}
