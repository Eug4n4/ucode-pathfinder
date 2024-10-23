#include "../inc/pathfinder.h"


void insert(t_pqueue *queue, t_node *data, int est, int price)
{
    t_pqnode *new_node = init_queue_node(data, est + price);
    t_pqnode *head = queue->head;
    t_pqnode *prev = NULL;

    while (head)
    {
        if (!mx_strcmp(head->data->label, data->label))
        {
            if (head->price > new_node->price)
            {
                head->price = new_node->price;
                free_node(new_node->data);
                free(new_node);
                if (prev)
                {
                    prev->next = head->next;
                }
                new_node = head;
                break;
            }

            free_node(new_node->data);
            free(new_node);
            new_node = NULL;
            break;
        }
        prev = head;
        head = head->next;
    }
    if (new_node)
    {
        head = queue->head;
        while (head)
        {
            if (head->next)
            {
                if (new_node->price > head->price &&
                    new_node->price <= head->next->price)
                {
                    new_node->next = head->next;
                    head->next = new_node;
                    break;
                }
            }
            else
            {
                head->next = new_node;
                break;
            }
            head = head->next;
        }
    }
}



