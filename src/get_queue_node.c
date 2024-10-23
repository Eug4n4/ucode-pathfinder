#include "../inc/pathfinder.h"


t_pqnode *get_queue_unvisited_node(t_pqueue **queue)
{
    t_pqnode *head = (*queue)->head;

    while (head)
    {
        if (!head->data->is_visited)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

t_pqnode *get_queue_node_by_label(t_pqueue **queue, const char *label)
{
    t_pqnode *tmp = (*queue)->head;

    while (tmp)
    {
        if (!mx_strcmp(tmp->data->label, label))
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}



