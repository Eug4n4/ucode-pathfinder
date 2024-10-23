#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len)
{
	unsigned char tmp[len];
	mx_memset(tmp, 0, len);
	mx_memcpy(tmp, src, len);
	return mx_memcpy(dst, tmp, len);

}



