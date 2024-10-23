#include "libmx.h"

char *mx_strndup(const char *s1, size_t n)
{
	size_t len = mx_strlen(s1);

	if (len > n)
	{
		char *str = mx_strnew(n);

		if (str)
		{
			return mx_strncpy(str, s1, n);
		}
	}
	else
	{
		char *str = mx_strnew(len);

		if (str)
		{
			return mx_strncpy(str, s1, len);
		}
	}
	return NULL;
}



