#include "main.h"

/**
 * memory_set - fills memory
 * @n:pointer to the memory
 * @nm:byte to fill the memory
 * @i:number of bytes
 *
 * Return:pointer to the memory
 */
char *memory_set(char *n, char nm, unsigned int i)
{
	unsigned int x;

	for (x = 0; x < i; x++)
	{
		*(n + x) = nm;
	}
	return (n);
}
/**
 * free_sh - free a tring
 * @strng:string
 */
void free_sh(char **strng)
{
	if (!strng)
		return;
	char **j = strng;

	while (*j != NULL)
	{
		free(*j);
		j++;
	}
	free(strng);
}
/**
 * real_sh - reallocates memory block
 * @dest:pointer tothe old block of memory
 * @old_ms:size of the old memory
 * @new_ms:size of the new memory
 *
 * Return:pointer to the new memory
 */
void *real_sh(void *dest, unsigned int old_ms, unsigned int new_ms)
{
	char *i;

	if (!dest)
		return (malloc(new_ms));
	if (!new_ms)
	{
		free(dest);
		return (NULL);
	}

	if (new_ms == old_ms)
		return (dest);
	i = malloc(new_ms);
	if (!i)
		return (NULL);
	/*copy contents from the previous block to the new block*/
	unsigned int copy_size = old_ms < new_ms ? old_ms : new_ms;
	char *source = dest;
	char *destination = i;
	unsigned int p;

	for (p = 0; p < copy_size; p++)
		destination[p] = source[p];

	free(dest);
	return (i);
}
