#include "libmx.h"

void mx_print_unicode(wchar_t c)
{
	char res[4];

	if (c <= 127)
	{
		mx_printchar(c);
	}
	else if (c <= 0x7FF)
	{
		res[0] = c >> 6 | 192;
		res[1] = (c & 63) | 128;
		write(STDOUT_FILENO, res, 2);

	}
	else if (c <= 0xFFFF)
	{
		res[0] = c >> 12 | 224;
		res[1] = (c >> 6 & 63) | 128;
		res[2] = (c & 63) | 128;
		write(STDOUT_FILENO, res, 3);

	}
	else if (c <= 0x1FFFFF)
	{
		res[0] = (c >> 18 & 7) | 240;
		res[1] = (c >> 12 & 63) | 128;
		res[2] = (c >> 6 & 63) | 128;
		res[3] = (c & 63) | 128;
		write(STDOUT_FILENO, res, 4);
	}

}



