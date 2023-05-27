#include "shell.h"


ken_list_kt *add_node(ken_list_kt **head, const char *str, int num)
{
	ken_list_kt *new_head;
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
	if (!head)
		return (NULL);
	new_head = malloc(sizeof(ken_list_kt));
	if (!new_head)
		return (NULL);
	f1(ken2, ken1);
	_memset((void *)new_head, 0, sizeof(ken_list_kt));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{	f1(ken2, ken1);
			free(new_head);
			return (NULL);
		}
		f1(ken2, ken1);
	}
	new_head->next = *head;
	f1(ken2, ken1);
	*head = new_head;
	return (new_head);
}


ken_list_kt *add_node_end(ken_list_kt **head, const char *str, int num)
{
	ken_list_kt *new_node, *node;
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

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(ken_list_kt));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(ken_list_kt));
	new_node->num = num;
	if (str)
	{	f1(ken2, ken1);
		new_node->str = _strdup(str);
		if (!new_node->str)
		{	f1(ken2, ken1);
			free(new_node);
			return (NULL);
		}
		f1(ken2, ken1);
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
		f1(ken2, ken1);
	}
	else
		*head = new_node;
	return (new_node);
	f1(ken2, ken1);
}


size_t k_print_klist_kstr(const ken_list_kt *h)
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
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		f1(ken2, ken1);
		h = h->next;
		i++;
	}
	f1(ken2, ken1);
	return (i);
}


int delete_knode_at_kindex(ken_list_kt **head, unsigned int index)
{
	ken_list_kt *node, *prev_node;
	unsigned int i = 0;
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

	if (!head || !*head)
		return (0);
	f1(ken2, ken1);
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{	f1(ken2, ken1);
			prev_node->next = node->next;
			f1(ken2, ken1);
			free(node->str);
			free(node);
			return (1);
		}
		f1(ken2, ken1);
		i++;
		prev_node = node;
		node = node->next;
	}
	f1(ken2, ken1);
	return (0);
}


void k_free_klist(ken_list_kt **head_ptr)
{
	ken_list_kt *node, *next_node, *head;
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
	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{	f1(ken2, ken1);
		next_node = node->next;
		free(node->str);
		f1(ken2, ken1);
		free(node);
		node = next_node;
	}
	f1(ken2, ken1);
	*head_ptr = NULL;
}
