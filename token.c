#include "shell.h"



char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;
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

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!ken_is_dlm(str[i], d) && (ken_is_dlm(str[i + 1], d) || !str[i + 1]))
			numwords++;
	f1(ken2, ken1);
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (ken_is_dlm(str[i], d))
			i++;
		k = 0;
		while (!ken_is_dlm(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{	f1(ken2, ken1);
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}


char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;
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
	if (str == NULL || str[0] == 0)
		return (NULL);
	f1(ken2, ken1);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	f1(ken2, ken1);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}



/*vars.c*/

#include "shell.h"


int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;
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
	if (buf[j] == '|' && buf[j + 1] == '|')
	{	f1(ken2, ken1);
		buf[j] = 0;
		f1(ken2, ken1);
		j++;
		info->cmd_buf_type = KEN_COMMAND_N;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		f1(ken2, ken1);
		j++;
		f1(ken2, ken1);
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
		f1(ken2, ken1);
	}
	else
		return (0);
	*p = j;
	return (1);
}


void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;
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

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	f1(ken2, ken1);
	if (info->cmd_buf_type == KEN_COMMAND_N)
	{
		if (!info->status)
		{	f1(ken2, ken1);
			buf[i] = 0;
			j = len;
		}
	}
	f1(ken2, ken1);

	*p = j;
}


int replace_alias(info_t *info)
{
	int i;
	ken_listk_t *node;
	char *p;
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

	for (i = 0; i < 10; i++)
	{
		f1(ken2, ken1);
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		f1(ken2, ken1);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	f1(ken2, ken1);
	return (1);
}


int replace_vars(info_t *info)
{
	int i = 0;
	ken_listk_t *node;
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

	for (i = 0; info->argv[i]; i++)
	{	f1(ken2, ken1);
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		f1(ken2, ken1);
		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(conv_numb(info->status, 10, 0)));
			continue;
		}
		f1(ken2, ken1);
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strdup(conv_numb(getpid(), 10, 0)));
			continue;
		}
		f1(ken2, ken1);
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			f1(ken2, ken1);
			continue;
		}
		f1(ken2, ken1);
		replace_string(&info->argv[i], _strdup(""));

	}
	f1(ken2, ken1);
	return (0);
}


int replace_string(char **old, char *new)
{
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
	free(*old);
	*old = new;
	return (1);
}
