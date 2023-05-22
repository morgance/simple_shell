#include "main.h"
/**
 * test_deli - test character in a buffer is a delimeter
 * @data:struct
 * @chbf:character buffer
 * @ap:position in buffer
 *
 * Return:1 for delimeter, 0 otherwise
 */
int est_deli(data_s *data, char *chbf, size_t *ap)
{
	size_t pr = *ap;

	if (chbf[pr] == '|' && chbf[pr + 1] == '|')
	{
		chbf[pr] = 0;
		pr++;
		data->cmd_ty = CMD_O;
	}
	else if (chbf[pr] == '&' && chbf[ap + 1] == '&')
	{
		chbf[pr] = 0;
		pr++;
		data->cmd_ty = CMD_A;
	}
	else if (chbf[pr] = ';')
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
 * @@leng:length of buffer
 *
 * Return:void
 */
void st_check(data_s *data, char *chbf, size_t len, size_t aj, size_t *ap)
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
 * vars_str 
