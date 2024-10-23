#include "libmx.h"

void mx_pop_front(t_list **list)
{
	if (list)
	{
		if (*list != NULL)
		{
			t_list *temp = *list;

			*list = (*list)->next;
			free(temp);
		}
	}

}



