#include "../inc/pathfinder.h"


void free_pqueue(t_pqueue *head)
{
    while (head->head)
    {
        t_pqnode *tmp = head->head;
        head->head = head->head->next;
        free_node(tmp->data);
        for (int i = 0; i < tmp->count; ++i)
        {
            free(tmp->routes[i]);
        }
        if (tmp->routes)
        {
            free(tmp->routes);
        }
        free(tmp);
    }
    free(head);
}



