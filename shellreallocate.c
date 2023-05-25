#include "shell.h"

/**
 * _memset - Fills a memory area with a constant byte
 * @v: Pointer to the memory area
 * @b: Byte to fill the memory area with
 * @n: Number of bytes to be filled
 * Return: Pointer to the memory area 'v'
 */
char *_memset(char *v, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		v[i] = b;
	return (v);
}

/**
 * ffree - Frees a string of strings
 * @xx: String of strings to be freed
 */
void ffree(char **xx)
{
	char **a = xx;

	if (!xx)
		return;
	while (*xx)
		free(*xx++);
	free(a);
}

/**
 * _realloc - Reallocates a block of memory
 * @xx: Pointer to the previous dynamically allocated block
 * @old_size: Size in bytes of the previous block
 * @new_size: Size in bytes of the new block
 *
 * Return: Pointer to the reallocated block of memory
 */
void *_realloc(void *xx, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!xx)
		return (malloc(new_size));
	if (!new_size)
		return (free(xx), NULL);
	if (new_size == old_size)
		return (xx);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)xx)[old_size];
	free(xx);
	return (p);
}
