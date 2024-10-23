#include "libmx.h"


char *mx_strstr(const char *haystack, const char *needle)
{
        if (needle[0] == '\0')
        {
                return (char *)haystack;
        }
        return mx_memmem(haystack, mx_strlen(haystack), needle, mx_strlen(needle));

}



