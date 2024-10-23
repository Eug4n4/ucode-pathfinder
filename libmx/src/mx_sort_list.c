#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *a, void *b)) {
        t_list* node = lst;

        while(node)
        {
            t_list* next_node = node->next;
            while (next_node)
            {
				if (cmp(node->data,next_node->data))
				{
					void *temp = next_node->data;
					next_node->data = node->data;
					node->data = temp;
				}
				next_node = next_node->next;
            }
        	node = node->next;
        }
        return lst;

}




