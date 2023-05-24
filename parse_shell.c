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

