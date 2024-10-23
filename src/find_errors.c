#include "../inc/pathfinder.h"

void find_errors(int argc, char **argv, int *error)
{
    if (argc != 2)
    {
        *error = ERR_INVAL_ARGS;
    }
    if (!*error)
    {
        check_file(argv, error);
    }
    print_errors(argv, error);
}



