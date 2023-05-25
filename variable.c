#include "main.h"
/**
 * test_deli - test character in a buffer is a delimeter
 * @data:struct
 * @chbf:character buffer
 * @ap:position in buffer
 *
 * Return:1 for delimeter, 0 otherwise
 */
int test_deli(data_s *data, char *chbf, size_t *ap)
{
	size_t pr = *ap;

	if (chbf[pr] == '|' && chbf[pr + 1] == '|')
	{
		chbf[pr] = 0;
		pr++;
		data->cmd_ty = CMD_O;
	}
	else if (chbf[pr] == '&' && chbf[pr + 1] == '&')
	{
		chbf[pr] = 0;
		pr++;
		data->cmd_ty = CMD_A;
	}
	else if (chbf[pr] == ';')
	{
		chbf[pr] = 0;
		data->cmd_ty = CMD_C;
	}
	else
		return (0);
	*ap = pr;
	return (1);
}
/**
 * st_check - checks chaining based on last status
 * @data:struct
 * @chbf:character buffer
 * @ap:position in buffer
 * @aj:starting position
 * @leng:length of buffer
 *
 * Return:void
 */
void st_check(data_s *data, char *chbf, size_t leng, size_t aj, size_t *ap)
{
	size_t pro = *ap;

	if (data->cmd_ty == CMD_A)
	{
		if (data->status)
		{
			chbf[aj] = 0;
			pro = leng;
		}
	}
	else if (data->cmd_ty == CMD_O)
	{
		if (!data->status)
		{
			chbf[aj] = 0;
			pro = leng;
		}
	}
	*ap = pro;
}
/**
 * alias_rep - replacea alias in string that is tokenized
 * @data:struct
 *
 * Return: 1 on success, 0 otherwise
 */
int alias_rep(data_s *data)
{
	char *pro;
	link_s pone;

	pone = str_strts(data->alias, data->argv[0], '=');
	if (!pone)
		return (0);

	pro = loc_str(pone->srt, '=');
	if (!pro)
		return (0);

	pro = duplic_str(pro + 1);
	if (!pro)
		return (0);
	free(data->argv[0]);
	data->argv[0] = pro;

	return (1);
}
/**
 * vars_str - replaces variables in a string that is tokenized
 * @data:struct
 *
 * Return: 1 on success, 0 otherwise
 */
int vars_str(data_s *data)
{
	int y = 0;
	link_s *prim;

	for (y = 0; data->argv[y]; y++)
	{
		if (data->argv[y][0] != '$' || !data->argv[y][1])
			continue;
		if (!_strcmp(data->argv[y], "$?"))
		{
			_string_rp(&(data->argv[y]), duplic_str(_numcon(data->status, 10, 0)));
		}
		else if (!strcmp(data->argv[y], "$$"))
		{
			_string_rp(&(data->argv[y]), duplic_str(_numcon(getpid(), 10, 0)))
		}
		else
		{
			char *var_name = &data->argv[y][1];

			prim = str_strts(data->_env, var_name, '=');
			if (prim)
			{
				char *value = loc_str(prim->srt, '=') + 1;

				_string_rp(&(data->argv[y]), duplic_str(value));
			}
			else
			{
				_string_rp(&data->argv[y], duplic_str(""));
			}
		}
	}
	return (1);
}
/**
 * _string_rp - replaces a string
 * @old_str:the old string
 * @new_str:the new string
 *
 * Return:1 on success, 0 otherwise
 */
int _string_rp(char **old_str, char *new_str)
{
	if (*old_str != NULL)
		free(old_str);
	*old_str = new_str;
	return (*old_str != NULL);
}
