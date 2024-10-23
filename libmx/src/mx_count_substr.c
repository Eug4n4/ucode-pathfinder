#include "libmx.h"

int mx_count_substr(const char *str, const char *sub)
{
	if (str && sub)
	{
		int count = 0;
		const char *res = str;
		int sub_len = mx_strlen(sub);

		while (*res && *sub)
		{
			res = mx_strstr(res, sub);
			if (res)
			{
				count++;
				res = res + sub_len;
			}
			else
			{
				break;
			}
		}
		return count;
	}
	return -1;

}



