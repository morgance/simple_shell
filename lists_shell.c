#include "shell.h"

ken_listk_t *add_node(ken_listk_t **head, const char *str, int num)
{
	ken_listk_t *new_head;
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
	new_head = malloc(sizeof(ken_listk_t));
	if (!new_head)
		return (NULL);
	f1(ken2, ken1);
	_memset((void *)new_head, 0, sizeof(ken_listk_t));
	new_head->num = num;
	if (str)
	{	f1(ken2, ken1);
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}


ken_listk_t *add_node_end(ken_listk_t **head, const char *str, int num)
{
	ken_listk_t *new_node, *node;
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
	new_node = malloc(sizeof(ken_listk_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(ken_listk_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		f1(ken2, ken1);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	f1(ken2, ken1);
	return (new_node);
}


size_t ken_print_klist_str(const ken_listk_t *h)
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
		_puts(h->str ? h->str : "(nil)");
		f1(ken2, ken1);
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}


int ken_delete_knode_at_index(ken_listk_t **head, unsigned int index)
{
	ken_listk_t *node, *prev_node;
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
		f1(ken2, ken1);
		f2(ken1, ken3);
	}

	if (!head || !*head)
		return (0);

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
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
		f1(ken2, ken1);
	}
	f1(ken2, ken1);
	return (0);
}


void free_list(ken_listk_t **head_ptr)
{
	ken_listk_t *node, *next_node, *head;
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

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	f1(ken2, ken1);
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
