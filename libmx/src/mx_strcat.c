#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2)
{
	int size1 = mx_strlen(s1);
	int size2 = mx_strlen(s2);

	for (int i = size1, j = 0; j < size2; ++i, ++j)
	{
		if (s1)
		{
			s1[i] = s2[j];
		}
		else
		{
			return s1;
		}
	}
	return s1;
}



