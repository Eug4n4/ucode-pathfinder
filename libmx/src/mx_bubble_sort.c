#include "libmx.h"

int mx_bubble_sort(char **arr, int size)
{
	int count = 0;

	if (arr)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = i + 1; j < size; ++j)
			{
				if (mx_strcmp(arr[i],arr[j]) > 0)
				{
					char *temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					++count;
				}
			}
		}
	}

	return count;
}


