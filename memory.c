#include "shell.h"

/**
 * bfree - it free pointer
 * @ptr: free pointer
 *
 * Return: none
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
