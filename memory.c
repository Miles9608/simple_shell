#include "shell.h"

/**
 * bfree - frees a pointer and nulls the pointer destination
 * @ptr: destination of the pointer to be freed
 *
 * Return: 1 on successfull, on failure 0.
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
