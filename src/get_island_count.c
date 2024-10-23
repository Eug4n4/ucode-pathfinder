#include "../inc/pathfinder.h"


int get_island_count(int fd)
{
    char *str = NULL;
    mx_read_line(&str, 1, '\n', fd);
    if (str)
    {
        int count = mx_atoi_positive(str);

        mx_strdel(&str);
        return count;
    }
    return 0;
}




