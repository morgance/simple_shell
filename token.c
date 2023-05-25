#include "main.h"
/**
 * **strtow - splits a string into words
 * @str:input string
 * @delimiters:delimeter string
 * Return:pointer to an array of strings
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
		if (!is_lim(str[i], delimiters) && (is_lim(str[i + 1],
						delimiters) || str[i + 1] == '\0'))
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
		while (is_lim(str[i], delimiters))
			i++;

		k = 0;
		while (!is_lim(str[i + k], delimiters) && str[i + k] != '\0')
			k++;

		words[j] = malloc((k + 1) * sizeof(char));
		if (!words[j])
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}

		words[j] = duplic_str(&str[i], k);
		words[j][k] = '\0';

		i += k;
		j++;
	}

	words[j] = NULL;
	return (words);
}
/**
 * **token - splits a string into words
 * @str:input string
 * @delimiter:delimiter
 * Return:pointer to array of strings
 */
char **token(char *str, char delimiter)
{
	int i, j, k, m, word_count = 0;
	char **words;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] != delimiter && str[i + 1] == delimiter) ||
				(str[i] != delimiter && !str[i + 1]) || str[i + 1] == delimiter)
			word_count++;
	}
	if (word_count == 0)
		return (NULL);
	words = malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);

	i = 0;
	j = 0;

	while (j < word_count)
	{
		while (str[i] == delimiter && str[i] != '\0')
			i++;

		k = 0;
		while (str[i + k] != delimiter && str[i + k] != '\0')
			k++;

		words[j] = malloc((k + 1) * sizeof(char));

		if (!words[j])
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			words[j][m] = str[i++];
		words[j][m] = '\0';
		j++;
	}
	words[j] = NULL;
	return (words);
}
