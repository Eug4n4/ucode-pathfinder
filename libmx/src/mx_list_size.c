#include "libmx.h"

int mx_list_size(t_list *list)
{
	int count = 0;
	t_list *head = list;

	while (head)
	{
		count++;
		head = head->next;
	}
	return count;
}




