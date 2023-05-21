#include "main.h"

/**
 * print_environment - prints the current environment
 * @env: Array of strings containing the environment variables
 */
void print_environment(char **env)
{
	if (env == NULL)
		return;

	for (int i = 0; env[i] != NULL; i++)
		printf("%s\n", env[i]);
}

/**
 * _printenv - wrapper function to print the current environment
 * @data: Structure containing potential arguments
 * Return: Always 0
 */
int _printenv(data_s *data)
{
	print_environment(data->env);
	return (0);
}

/**
 * getenv_value - retrieves the value of the environment variable
 * @env: Array of strings containing the environment variables
 * @name: Name of the environment variable to retrieve
 *
 * Return: Pointer to the value of the environment variable
 */
char *getenv_value(char **env, const char *name)
{
	if (env == NULL || name == NULL)
		return (NULL);

	size_t name_len = strlen(name);

	for (int i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i]. name, name_len) == 0 && env[i][name_len]
				return (&env[i][name_len + 1]);
	}

	return (NULL);
}

/**
 * set_environment_variable - sets a new environment variable
 * @env: Array of strings containing the environment variables
 * @name: Name of the environment variable
 * @value: Value to be assigned to the environment variable
 *
 * Return: 1 on success, 0 on failure
 */
int set_environment_variable(char **env, const char *name, const char *value)
{
	if (env == NULL || name == NULL || value == NULL)
	return (0);

	size_t name_len = strlen(name);
	size_t value_len = strlen(value);

	char *new_env_var = malloc(name_len + value_len + 2;

	if (new_env_var == NULL)
	return (0);

	snprintf(new_env_var, name_len + value_len + 2, "%s=%s", name, value);

	for (int i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], name, name_len) == 0 && env[i][name_len] == '=')
		{
			free(env[i]);
			env[i] = new_env_var;
			return (1);
		}
	}
}
