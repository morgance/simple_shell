#include "main.h"
/**
 * is_exec - checks if a file is an executable command
 * @data:data struct
 * @path:path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_exec(data_s *data, char *path)
{
	struct stat st;

	if (path == NULL || stat(path, &st) != 0)
		return (0);

	return (S_ISREG(st.st_mode));
}
/**
 * dupli_char - duplicates characters
 * @pstrn: the PATH string
 * @sindx: starting index
 * @spinx: stopping index
 *
 * Return: pointer to new buffer
 */
char *dupli_char(char *pstrn, int sindx, int spinx)
{
	int i, j;
	char *pro;

	pro = malloc((spinx - sindx + 1) * sizeof(char));
	if (pro == NULL)
		return (NULL);

	j = 0;
	for (i = sindx; i < spinx; i++)
	{
		if (pstrn[i] != ':')
		{
			pro[j] = pstrn[i];
			j++;
		}
	}

	pro[j] = '\0';
	return (pro);
}
/**
 * chk_path - checks cmd in the PATH string
 * @data:data struct
 * @pstrn:PATH string
 * @cmd:cmd to find
 *
 * Return:path of cmd 
 */
char *chk_path(data_s *data, char *pstrn, char *cmd)
{
	int i = 0, dest = 0;
	char *path;

	if (!pstrn)
		return (NULL);

	if (_strlen(cmd) > 2 && starts_with(cmd, "./"))
	{
		if (is_exec(data, cmd))
			return (cmd);
	}

	while (pstrn[i])
	{
		if (pstrn[i] == ':')
		{
			path = dupli_char(pstrn, dest, i);
			if (*path)
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			else
			{
				path = duplic_str(cmd);
			}

			if (is_exec(data, path))
				return (path);

			dest = i + 1;
		}

		i++;
	}

	return (NULL);
}



