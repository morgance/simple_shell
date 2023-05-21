#include "main.h"
/**
 * node_new - adds a node to the start on list
 * @hd:pointer to head node
 * @srt:string of the node
 * @ber:node index
 *
 * Return: the new head node
 */
link_s *node_new(link_s **hd, const char *srt, int ber)
{
	if (!hd)
		return (NULL);
	link_s *head = malloc(sizeof(link_s));

	if (!head)
		return (NULL);
	memory_set((char *)head, 0, sizeof(link_s));
	head->ber = ber;

	if (srt)
	{
		head->srt = duplic_str(srt);
		if (!head->srt)
		{
			free(head);
			return (NULL);
		}
	}
	head->next = *hd;
	hd = head;
	return (head);
}
/**
 *node_end - adds node at the end of linked list
 *@hd:pointer to the head node
 *@srt:string of node
 *@ber:node index
 *
 * Return: pointer to the new node
 */
link_s *node_end(link_s **hd, const char *srt, int ber)
{
	if (!hd)
		return (NULL);
	link_s *end_node = malloc(sizeof(link_s));

	if (!end_node)
		return (NULL);

	memory_set((char *)end_node, 0, sizeof(link_s));
	end_node->ber ber;

	if (!srt)
	{
		end_node->srt = duplic_str(srt);
		if (!end_node->srt)
		{
			free(end_node);
			return (NULL);
		}
	}
	end_node->next = NULL;

	if (!hd)
	{
		link_s *node = *hd;

		while (node->next)
			node = node->next;
		node->next = end_node;
	}
	else
	{
		*hd = end_node;
	}
	return (end_node);
}
/**
 * print_str - prints the string of a linked list
 * @head:first node pointer
 *
 * Return:list size
 */
size_t print_str(const link_s *head)
{
	size_t count = 0;

	while (head)
	{
		print_inp(head->srt ? head->srt : "(nil)");
		print_inp("\n");
		head = head->next;
		count++;
	}
	return (count);
}
/**
 * del_node - deletes node at an index
 * @dest:pointer to the first node
 * @deleto:index of node to delete
 *
 * Return:1 when succesful, 0 otherwise
 */
int del_node(link_s **dest, unsigned int deleto)
{
	if (!dest || !*dest)
		return (0);

	if (deleto == 0)
	{
		link_s *pro = *dest;
		*dest = (*dest)->next;
		free(pro->srt);
		free(pro);
		return (1);
	}
	link_s *pro = *dest;
	link_s *pre_node = NULL;
	unsigned int  x = 0;

	while (pro)
	{
		if (x == deleto)
		{
			pre_node->next = pro->next;
			free(pro->srt);
			free(pro);
			return (1);
		}
		pre_node = pro;
		pro = pro->next;
		x++;
	}
	return (0);
}
/**
 * free_nodes - frees nodes of a linked list
 * @head:pointer to tne head node
 *
 * Return:nothing
 */
void free_nodes(link_s **head)
{
	if (!head || !*head)
		return;
	link_s *current_node = *head;
	link_s *next_node;

	while (current_node)
	{
		next_node = current_node->next;
		free(current_node->srt);
		free(current_node);
		current_node = next_node;
	}
	*head = NULL;
}
