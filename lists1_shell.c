#include "shell.h"


size_t k_list_klen(const ken_list_kt *h)
{
	size_t i = 0;
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

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}


char **ken_list_kto_strings(ken_list_kt *head)
{
	ken_list_kt *node = head;
	size_t i = k_list_klen(head), j;
	char **strs;
	char *str;
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

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	f1(ken2, ken1);
	for (i = 0; node; node = node->next, i++)
	{	f1(ken2, ken1);
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{	f1(ken2, ken1);
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			f1(ken2, ken1);
			return (NULL);
		}
		f1(ken2, ken1);
		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


size_t k_print_klist(const ken_list_kt *h)
{
	size_t i = 0;
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

	while (h)
	{	f1(ken2, ken1);
		_puts(k_convert_knumber(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		f1(ken2, ken1);
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		f1(ken2, ken1);
		i++;
	}
	return (i);
}


ken_list_kt *node_kstarts_kwith(ken_list_kt *node, char *prefix, char c)
{
	char *p = NULL;
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
	{	f1(ken2, ken1);
		p = k_starts_kwith(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		f1(ken2, ken1);
		node = node->next;
	}
	return (NULL);
}


ssize_t get_knode_kindex(ken_list_kt *head, ken_list_kt *node)
{
	size_t i = 0;
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

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
