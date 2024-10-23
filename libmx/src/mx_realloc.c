#include "libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
	if (!size && ptr)
	{
		free(ptr);
		return NULL;
	}
	if (!ptr)
	{
		return malloc(size);
	}

	size_t allocated = malloc_usable_size(ptr);

	if (allocated >= size)
	{
		return ptr;
	}
	void *res = malloc(size);

	mx_memmove(res, ptr, allocated);
	free(ptr);
	return res;

}






