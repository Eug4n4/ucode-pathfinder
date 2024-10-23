#include "libmx.h"

static long long get_content_len(int fd)
{
    long long length = 0;
    char buf = '\0';

    while (read(fd, &buf, sizeof(char)) > 0)
    {
        length++;
    }
    close(fd);

    return length;
}

char *mx_file_to_str(const char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1)
    {
        return NULL;
    }
    long long size = get_content_len(fd);
    fd = open(file, O_RDONLY);

    if (fd == -1)
    {
        return NULL;
    }
    char *res = mx_strnew(size);

    if (res)
    {
        read(fd, res, size);
        close(fd);
        return res;
    }
    close(fd);
    return NULL;
}



