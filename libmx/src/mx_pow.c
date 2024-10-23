#include "libmx.h"

double mx_pow(double n, unsigned int pow)
{
	double res = 1;

	if ((int)pow > 0)
	{
		for (unsigned int i = 0; i < pow; i++)
		{
			res *= n;
		}
	}
	return res;
}



