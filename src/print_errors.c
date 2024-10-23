#include "../inc/pathfinder.h"


void print_errors(char **argv, int *error)
{
    int filename_len;
    char *first = "error: file ";
    char *second = "error: line ";
    int first_len = mx_strlen(first);
    char *err = NULL;

    if (*error != ERR_INVAL_ARGS)
    {
        filename_len = mx_strlen(argv[1]);
    }
    switch (*error)
    {
        case ERR_INVAL_ARGS:
        {
            mx_printerr("usage: ./pathfinder [filename]\n");
            break;
        }
        case ERR_FILE_EXIST:
        {
            err = mx_strnew(28 + filename_len);
            mx_strcpy(err, first);
            mx_strcpy(err + first_len, argv[1]);
            mx_strcpy(err + first_len + filename_len, " does not exist\n");
            break;
        }
        case ERR_FILE_EOF:
        {
            err = mx_strnew(22 + filename_len);
            mx_strcpy(err, first);
            mx_strcpy(err + first_len, argv[1]);
            mx_strcpy(err + first_len + filename_len, " is empty\n");
            break;
        }
        case ERR_NUM_ISLANDS:
        {
            mx_printerr("error: invalid number of islands\n");
            break;
        }
        case ERR_DUP_ISLANDS:
        {
            mx_printerr("error: duplicate bridges\n");
            break;
        }
        case ERR_INVAL_SUM:
        {
            mx_printerr("error: sum of bridges lengths is too big\n");
            break;
        }
        default:
        {
            if (*error)
            {
                char *line = mx_itoa(*error);
                int len = mx_strlen(line);
                err = mx_strnew(26 + len);
                mx_strcpy(err, second);
                mx_strcpy(err + mx_strlen(second), line);
                mx_strcpy(err + mx_strlen(second) + len, " is not valid\n");
                mx_strdel(&line);
            }
            break;
        }
    }
    mx_printerr(err);
    mx_strdel(&err);
}



