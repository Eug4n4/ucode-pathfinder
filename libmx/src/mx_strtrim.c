#include "libmx.h"


char *mx_strtrim(const char *str)
{
	if (str)
	{
		int start_idx = 0;
		int end_idx = mx_strlen(str) - 1;

		while (mx_isspace(str[start_idx]))
		{
			start_idx++;
		}
		while (end_idx >= 0 && mx_isspace(str[end_idx]))
		{
			end_idx--;
		}
		int size = end_idx - start_idx + 1;

		if (size <= 0)
		{
			return mx_strnew(0);
		}
		char *res = mx_strnew(size);

		if (res)
		{
			mx_strncpy(res, str + start_idx, size);
			return res;
		}

	}
	return NULL;

}



