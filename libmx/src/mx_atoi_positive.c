#include "libmx.h"

int mx_atoi_positive(const char *str)
{
	int res = 0;

	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (mx_isdigit(str[i]))
		{
			res = res * 10 + (str[i] - '0');
		}
		else
		{
			return 0;
		}

	}
	return res;
}

