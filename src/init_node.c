#include "../inc/pathfinder.h"


t_pqnode *init_queue_node(t_node *data, int price)
{
    t_pqnode *node = malloc(sizeof(t_pqnode));

    if (!node)
    {
        return NULL;
    }
    node->data = init_node(data->label);
    node->price = price;
    node->count = 0;
    node->next = NULL;
    node->routes = NULL;
    return node;
}

t_node *init_node(const char *label)
{
    t_node *node = malloc(sizeof(t_node));

    if (!node)
    {
        return NULL;
    }
    node->label = mx_strdup(label);
    node->is_visited = false;
    return node;
}




