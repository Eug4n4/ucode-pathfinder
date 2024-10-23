#include "libmx.h"


void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len)
{
	if (little_len == 0)
	{
		return (void *)big;
	}
	if (big_len >= little_len)
	{
		unsigned char *bigptr = (unsigned char*)big;
		unsigned char *littleptr = (unsigned char*)little;

		for (size_t i = 0; i < big_len; ++i)
		{
			if (bigptr[0] == littleptr[0] && mx_memcmp(bigptr, little, little_len) == 0)
			{
				return bigptr;
			}
			++bigptr;
		}
	}

	return NULL;
}



