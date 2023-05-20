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

