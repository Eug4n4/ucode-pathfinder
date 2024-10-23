#include "libmx.h"

int mx_count_words(const char *str, char delimiter)
{
	if (str)
	{
		int count = 0;

		for(int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == delimiter)
			{
				continue;
			}
			if (str[i + 1] == delimiter || str[i + 1] == '\0')
			{
				count++;
			}

		}
		return count;
	}
	return -1;

}



