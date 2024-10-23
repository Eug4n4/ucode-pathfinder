#include "libmx.h"

void mx_push_back(t_list **list, void *data)
{
	if (list)
	{
		t_list *new_node = mx_create_node(data);

		if (!*list)
		{
			*list = new_node;
			return;
		}
		t_list *head = *list;

		while (head->next != NULL)
		{
			head = head->next;
		}
		head->next = new_node;
	}

}



