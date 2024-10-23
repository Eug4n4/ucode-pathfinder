#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count)
{
        if (s && arr)
        {
                int left = 0;
                int right = size - 1;

                while (left <= right)
                {
                        int mid = (right + left) / 2;

                        if (mx_strcmp(arr[mid], s) == 0)
                        {
                                *count += 1;
                                return mid;
                        }
                        if (mx_strcmp(arr[mid], s) > 0)
                        {
                                right = mid - 1;
                        }
                        else
                        {
                                left = mid + 1;
                        }
                        *count += 1;
                }
        }
        *count = 0;
        return -1;

}



