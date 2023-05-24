#include "main.h"
/**
 * _history - display history list
 * @data:structure arguments
 *
 * Return:0
 */
int _history(data_s *data)
{
	print_elem(data->former_n);
	return (0);
}
/**
 * unset_alias - unsets alias 
 * @data: parameter struct
 * @n:string alias
 *
 * Return:0 if succesful, 0 otherwise
 */
int unset_alias(data_s *data, char *n)
{
    char *i;
    int pk = 0;

    i = strchr(n, '=');
    if (!i)
        return (1);

    *i = '\0';  /* Replace '=' with null terminator to isolate the alias*/

    /* Find the node with the matching alias and delete it*/
    link_s *node = str_strts(data->alias, n, -1);
    if (node)
    {
        pk = del_node(&(data->alias), get_index(data->alias, node));
    }

    *i = '=';  /* Restore the original string */

    return (pk);
}
/**
 * set_alias - sets alias
 * @data:parameter struct
 * @n:the string alias
 *
 * Return:0 if successful, 1 otherwise
 */
int set_alias(data_s *data, char *n)
{
    char *j;

    j = strchr(n, '=');
    if (!j)
        return (1);

    if (!*(j + 1))
        return (unset_alias(data, n));

    *j = '\0';  /* Replace '=' with null terminator to isolate the alias*/

    /* Unset the existing alias (if any) and add the new alias*/
    unset_alias(data, n);
    int ali = node_end(&(data->alias), n, 0) == NULL;

    *j = '=';  /* Restore the original string*/

    return (ali);
}
/**
 * print_alias - prints an alias string
 * @pro:alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(link_s *pro)
{
    if (pro)
    {
        char *j = strchr(pro->srt, '=');
        if (j)
        {
            size_t alias_length = j - pro->srt;
            _putchar("%.*s '", (int)alias_length, pro->srt);
            print_inp(j + 1);
            print_inp("'\n");
            return (0);
        }
    }
    return (1);
}



