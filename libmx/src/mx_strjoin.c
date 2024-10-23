#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2)
{
	if (s1 && s2)
	{
		int len = mx_strlen(s1) + mx_strlen(s2);
		char *str = mx_strnew(len);

		if (str)
		{
			mx_strcpy(str, s1);
			mx_strcat(str + mx_strlen(s1), s2);
			return str;
		}
	}
	else if (s1)
	{
		return mx_strdup(s1);
	}
	else if (s2)
	{
		return mx_strdup(s2);
	}

	return NULL;

}



