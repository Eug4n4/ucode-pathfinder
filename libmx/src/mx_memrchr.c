#include "libmx.h"


void *mx_memrchr(const void *s, int c, size_t n)
{
	int len = mx_strlen((const char *)s);
	unsigned char *ptr = (unsigned char *)s;

	for (size_t i = 0; i < n; ++i)
	{
		if (ptr[len - i - 1] == c)
		{
			return &ptr[len - i - 1];
		}

	}
	void *found = mx_memchr(&ptr[len - 1], c, 1);

	return found ? found : NULL;

}



