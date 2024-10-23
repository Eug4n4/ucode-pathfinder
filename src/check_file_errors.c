#include "../inc/pathfinder.h"


void check_first_line(int fd, int *error)
{
    char *str = NULL;
    mx_read_line(&str, 1, '\n', fd);
    int number = mx_atoi_positive(str);

    if (str[0] == '0')
    {
        *error = ERR_INVAL_LINE;
    }
    else
    {
        char *str_number = mx_itoa(number);

        if (mx_strcmp(str, str_number))
        {
            *error = ERR_INVAL_LINE;
        }
        mx_strdel(&str_number);
    }
    mx_strdel(&str);
}


void check_eof(int fd, int *error)
{
    char buf;

    if (read(fd, &buf, sizeof(char)) <= 0)
    {
        *error = ERR_FILE_EOF;
    }
    else
    {
        close(fd);
    }
}


void check_file(char **argv, int *error)
{
    int fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        *error = ERR_FILE_EXIST;
    }
    else
    {
        check_eof(fd, error);
        if (*error != ERR_FILE_EOF)
        {
            fd = open(argv[1], O_RDONLY);
            check_first_line(fd, error);
            close(fd);
        }
    }
}



