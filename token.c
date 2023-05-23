#include "main.h"
/**
 * **strtow - splits a string into words
 * @str:input string
 * @delimiters: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str, char *delimiters)
{
	int i, j, k, word_count = 0;
	char **words;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	if (delimiters == NULL)
		delimiters = " ";

	int len = strlen(str);

	/* Count the number of words */
	for (i = 0; i < len; i++)
	{
		if (!is_delimiter(str[i], delimiters) && (is_delimiter(str[i + 1], delimiters) || str[i + 1] == '\0'))
			word_count++;
	}

	if (word_count == 0)
		return (NULL);

	words = malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);

	i = 0;
	j = 0;

	/* Extract words and store them in the array */
	while (j < word_count)
	{
		while (is_delimiter(str[i], delimiters))
			i++;

		k = 0;
		while (!is_delimiter(str[i + k], delimiters) && str[i + k] != '\0')
			k++;

		words[j] = malloc((k + 1) * sizeof(char));
		if (!words[j])
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}

		strncpy(words[j], &str[i], k);
		words[j][k] = '\0';

		i += k;
		j++;
	}

	words[j] = NULL;
	return (words);
}

