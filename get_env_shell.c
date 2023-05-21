#include "main.h"

/**
 * my_environ - prints the current environment
 * @data: Structures containing potential arguments.
 * Return: Always 0
 */
int my_environ(data_s *data)
{
	char **environ = data->environ;

	if (environ == NULL)
	{
		printf("Environment variable is empty.\n");
		return (0);
	}

	for (int j = 0; environ[j] != NULL; j++)
	{
		printf("%s\n", environ[j]);
	}

	return (0);
}

/**
 * exits_env - exits the value of the environment variable
 * @data: Structures containing potential arguments.
 * @name: Name of the environment variable
 *
 * Return: Pointer to the value of the environment variable, pr NULL
 */
char *exits_env(data_s *data, const char *name)
{
	char **env = data->env;

	if (env == NULL || name == NULL)
		return (NULL);

	while (*env != NULL)
	{
		if (started_with(*env, name))
			return (*env);
		env++;
	}

	return (NULL);
}

/**
 * print_lists_env - Prints a new environment variable.
 * @data: Structure containing potential arguments.
 * Return: 0 on success, 1 on failure
 */
int print_lists_env(data_s *data)
{
	if (data->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}

	if (_lists_env(data->argv[1], data->argv[2]) ==)
		return (0);

	return (1);
}

/**
 * _erase_env - Remove an environment variable
 * @data: Structure containing potential arguments
 * Return: 0 on success, 1 on failure
 */
int _erase_env(data_s *data)
{
	int j;

	if (data->argc < 2)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}

	for (j = 1, j < data->argc; i++)
	{
		if (_erase_env(data->argv[j]) != 0)
			return (1);
	}

	return (0);
}
