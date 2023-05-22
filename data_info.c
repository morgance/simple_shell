#include "main.h"
/**
 * data_info - initialize struct
 * @data:struct adress
 *
 * Return:void
 */
void data_info(data_s *data)
{
	data->str = NULL;
	data->argc = 0;
	data->path = NULL;
	data->argv = NULL;
}
/**
 * set_data - initialize the struct
 * @data:struct address
 * @ph:argument
 *
 * Return:void
 */
void set_data(data_s *data, char **ph)
{
	int x = 0;

	data->filename = ph[0];

	if (data->str)
	{
		data->argv = spl_str(data->str, "\t");

		if (!data->argv)
		{
			data->argv = malloc(sizeof(char *) * 2);
			if (data->argv)
			{
				data->argv[0] = duplic_str(data->str);
				data->argv[1] = NULL;
			}
		}
		for (x = 0; data->argv && data->argv[x]; x++)
			;

		data->argc = x;

		alias_rep(data);
		vars_str(data);
	}
}
/**
 * free_strct - frees struct fields
 * @data:struct address
 * @pst:free all fields
 *
 * Return:void
 */
void free_strct(data_s *data, int pst)
{
	free_sh(data->argv);
	data->path = NULL;
	data->argv = NULL;

	if (pst)
	{
		if (data->cmd_add)
			free(data->str);
		if (data->alias)
			free_nodes(&(data->alias));
		if (data->_env)
			free_nodes(&(data->_env));
		if (data->former_n)
			free_nodes(&(data->former_n));
		free_sh(data->_envi_)
			data->_envi_ = NULL;
		bfree((void **)data->cmd_add);
		if (data->read_in > 2)
			close(data->read_in);
		_putchar(FLUSH_BUFF);
	}
}
