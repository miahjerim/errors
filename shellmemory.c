#include "shell.h"

/**
 * bfree - frees a pointer and sets it to NULL
 * @vv: Address of the pointer to be freed
 *
 * Return: 1 if the pointer is freed, 0 otherwise
 */

int bfree(void **vv)
{
	if (vv && *vv)
	{
		free(*vv);
		*vv = NULL;
		return (1);
	}
	return (0);
}