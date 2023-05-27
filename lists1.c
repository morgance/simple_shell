#include "shell.h"


size_t list_len(const ken_listk_t *h)
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


char **ken_listk_to_strings(ken_listk_t *head)
{
	ken_listk_t *node = head;
	size_t i = list_len(head), j;
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
	f1(ken2, ken1);
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


size_t print_list(const ken_listk_t *h)
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
		_puts(conv_numb(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		f1(ken2, ken1);
		_puts(h->str ? h->str : "(nil)");
		f1(ken2, ken1);
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}


ken_listk_t *node_starts_with(ken_listk_t *node, char *prefix, char c)
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
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}


ssize_t get_node_index(ken_listk_t *head, ken_listk_t *node)
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
	f1(ken2, ken1);
	while (head)
	{
		if (head == node)
			return (i);
		f1(ken2, ken1);
		head = head->next;
		i++;
	}
	return (-1);
}
