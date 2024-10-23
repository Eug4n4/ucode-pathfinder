#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len)
{
	int src_len = mx_strlen(src);
	int bytes = 0;

	mx_memcpy(dst, src, len);
	len -= src_len;
	while (len > bytes)
	{
		dst[src_len + bytes] = '\0';
		++bytes;
	}
	return dst;

}



