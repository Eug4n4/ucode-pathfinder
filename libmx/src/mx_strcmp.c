#include "libmx.h"

int mx_strcmp(const char *s1, const char *s2)
{
	int s1_len = mx_strlen(s1);
	int s2_len = mx_strlen(s2);

	if (s1_len < s2_len)
	{
		return mx_memcmp(s1, s2, s2_len);
	}
	return mx_memcmp(s1, s2, s1_len);

}



