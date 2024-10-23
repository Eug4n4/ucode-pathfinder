#include "../inc/pathfinder.h"


t_pqueue *init_pqueue(t_node *root)
{
    t_pqueue *pq = malloc(sizeof(t_pqueue));

    if (!pq)
    {
        return NULL;
    }
    pq->head = init_queue_node(root, 0);
    return pq;
}



