#include "main.h"

/**
 * save_data - initializes data_s struct
 * @data: struct address
 */
void save_data(data_s *data)
{
	data->arg = NULL;
	data->argc = NULL;
	data->path = 0;
	data->argv = 0;
}

/**
 * set_data - initializes data_s struct
 * @data: struct address
 * @av: argument vector
 */
void set_data(data_s, *data, char **av)
{
	int j = 0;

	data->fname = av[0];
	if (data->arg)
	{
		data->argv = ptrsow(data->srg, "\s");
		if (!data->argv)
		{
			data->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				data->argv[0] = strcpy(data->argv);
				data->argv[1] = NULL;
			}
		}
		for (j = 0; info->argv && data->argv[j]; j++)

		data->argc = j;

		put_alias(data);
		put_vars(data);
}
