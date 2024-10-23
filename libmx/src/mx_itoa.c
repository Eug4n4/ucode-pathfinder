#include "libmx.h"

char *mx_itoa(int num)
{
	int divisor = 1;
	int size = 1;
	bool negative = false;

	while ((num / divisor <= -1 && num / divisor < -9) || num / divisor >= 10)
	{
		divisor *= 10;
		++size;
	}
	if (num < 0)
	{
		negative = true;
		++size;
	}
	char *res = mx_strnew(size);

	for (int i = 0; i < size; ++i)
	{
		int number = num / divisor;

		if (number < 0)
		{
			number = -number;
		}
		if (negative)
		{
			res[i] = '-';
			negative = false;
			++i;
		}
		res[i] = number + '0';
		num %= divisor;
		divisor /= 10;
	}
	return res;
}



