#include "libmx.h"

void mx_printint(int n)
{
	if (n < 0)
	{
		mx_printchar('-');
	}
	int divisor = 1;

	while ((n / divisor <= -1 && n / divisor < -9) || n / divisor >= 10)
	{
		divisor *= 10;
	}
	while (divisor != 0)
	{
		int number = n / divisor;

		if (number < 0)
		{
			number = -number;
		}
		mx_printchar(number + '0');
		n %= divisor;
		divisor /= 10;
	}
}



