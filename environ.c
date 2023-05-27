#include "shell.h"


int _myenv(info_t *info)
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

	ken_print_klist_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	ken_listk_t *node = info->env;
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
		p = starts_with(node->str, name);
		f1(ken2, ken1);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}


int _mysetenv(info_t *info)
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
	{
		_eputs("Incorrect number of arguements\n");
		f1(ken2, ken1);
		return (1);
	}
	if (ken__setkenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}


int _myunsetenv(info_t *info)
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
	{
		f1(ken2, ken1);
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		ken__unsektenv(info, info->argv[i]);
	f1(ken2, ken1);

	return (0);
}


int pop_envlist(info_t *info)
{
	ken_listk_t *node = NULL;
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
