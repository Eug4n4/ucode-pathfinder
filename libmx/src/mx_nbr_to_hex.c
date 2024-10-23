#include "libmx.h"

static int count_digits(unsigned long n)
{
    int size = 0;

    while (n != 0)
    {
        n /= 16;
        size++;
    }

    return size;

}

char *mx_nbr_to_hex(unsigned long nbr)
{
    int size = count_digits(nbr);
    if (size == 0)
    {
        size++;
    }
    char *res = mx_strnew(size);

    if (res)
    {

        if (nbr == 0)
        {
            res[size - 1] = nbr + '0';
        }

        while (nbr)
        {
            int next_nbr = nbr % 16;
            if (next_nbr > 9)
            {
                char last_digit = next_nbr % 10 + '0';
                char hex_nbr = last_digit + '1';
                res[--size] = hex_nbr;
            }
            else
            {
                res[--size] = next_nbr + '0';
            }

            nbr /= 16;
        }

        return res;
    }
    return 0;

}




