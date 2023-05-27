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
