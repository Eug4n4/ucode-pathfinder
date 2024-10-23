#include "libmx.h"

void mx_printerr(const char *s)
{
	if (s)
	{
		int length = mx_strlen(s);
		write(STDERR_FILENO, s, length);
	}
}

