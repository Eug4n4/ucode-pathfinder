#include "libmx.h"

void swap(char **s1, char **s2)
{
	char *tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int partition(char** arr, int left, int right, int* swaps)
{
	int i = left - 1;
	int j = right + 1;
	int pivot = left + (right - left) / 2;
	int pivot_len = mx_strlen(arr[pivot]);

	while (true)
	{
		while (mx_strlen(arr[++i]) < pivot_len);
		while (mx_strlen(arr[--j]) > pivot_len);

		if (i >= j)
		{
			break;
		}

		if (mx_strlen(arr[i]) == mx_strlen(arr[j]))
		{
			continue;
		}
		swap(&arr[i], &arr[j]);
		*swaps += 1;

	}
	return j;
}

void quicksort(char **arr, int left, int right, int *swaps)
{
	if (left < right)
	{
		int pivot = partition(arr,left,right,swaps);

		quicksort(arr, left, pivot, swaps);
		quicksort(arr, pivot + 1, right, swaps);
	}

}

int mx_quicksort(char** arr, int left, int right)
{
	if (arr)
	{
		int swaps = 0;

		quicksort(arr,left,right,&swaps);
		return swaps;
	}
	return -1;

}




