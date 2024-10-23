#include "libmx.h"

int mx_get_char_index(const char *str, char c)
{
	if (str)
	{
		int str_len = mx_strlen(str);
		char *res = mx_memchr(str, c, str_len);

		if (res)
		{
			return str_len - mx_strlen(res);
		}
		return -1;
	}
	return -2;

}



