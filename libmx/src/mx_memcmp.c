#include "libmx.h"


int mx_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
	{
		return 0;
	}
	unsigned char *ucs1 = (unsigned char *)s1;
	unsigned char *ucs2 = (unsigned char *)s2;

	for (size_t i = 0; i < n; ++i)
	{
		if (ucs1[i] != ucs2[i])
		{
			return ucs1[i] - ucs2[i];
		}
	}

	return *ucs1 - *ucs2;
}




