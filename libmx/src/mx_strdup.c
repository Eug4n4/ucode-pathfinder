#include "libmx.h"


char *mx_strdup(const char *s)
{
	return mx_strndup(s, mx_strlen(s));
}



