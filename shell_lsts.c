#include "main.h"
/**
 * leng_ls - checks the length of a linked list
 * @head:first node
 *
 * Return:lists size
 */
size_t leng_ls(const link_s *head)
{
	size_t count = 0;

	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}
/**
 * arry_strng - returns array of strings
 * @head:first node
 *
 * Return: array of string
 */
char **arry_strng(link_s *head)
{
	size_t count = leng_ls(head);
	char **pst;
	size_t h = 0, y;

	if (!head || count == 0)
		return (NULL);
	pst = malloc(sizeof(char *) * (count + 1));

	if (!pst)
		return (NULL);

	for (; head != NULL; head = head->next, h++)
	{
		pst[h] = duplic_str(head->srt);

		if (!pst[h])
		{
			for (y = 0; y < h; y++)
				free(pst[y]);
			free(pst);
			return (NULL);
		}
	}
	pst[h] = NULL;
	return (pst);
}
/**
 * print_elem - prints elements of a liked list
 * @head:first node
 *
 * Return:size of liked list
 */
size_t print_elem(const *head)
{
	size_t count = 0;

	while (head != NULL)
	{
		print_inp(_numcon(head->ber, 10, 0));
		_putchar(':');
		_putchar(' ');
		print_inp(head->srt ? head->srt : "(nil)");
		print_inp("\n");
		head = head->next;
		count++;
	}
	return (count);
}
/**
 * str_strts - returns node string with perix as start
 * @head:head list
 * @pfix:string to match
 * @n:the next char
 *
 * Return:matching node
 */
link_s *str_strts(link_s *head, const char pfix, char n)
{
	while (head != NULL)
	{
		if (starts_with(head->srt, pfix))
		{
			if (n == -1 || head->srt[_strlen(pfix)] == c)
				return (head);
		}
		head = head->next;
	}
	return (NULL);
}
/**
 * get_index - gets the index of the node
 * @head:head list
 * @pnodes:node pointer
 *
 * Return:the node index
 */
ssize_t get_index(link_s *head, link_s *pnodes)
{
	ssize_t index = 0;

	while (head)
	{
		if (head == pnodes)
			return (index);
		index++;

		head = head->next;
	}
	return (-1);
}
