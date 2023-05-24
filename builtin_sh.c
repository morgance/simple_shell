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

