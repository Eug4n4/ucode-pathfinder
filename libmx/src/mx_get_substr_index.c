#include "libmx.h"


int mx_get_substr_index(const char *str, const char *sub)
{
	if (!str || !sub)
	{
		return -2;
	}
	int str_len = mx_strlen(str);
	char *match = mx_strstr(str, sub);

	if (match)
	{
		return str_len - mx_strlen(match);
	}
	return -1;
}



