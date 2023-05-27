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
