#include "../inc/pathfinder.h"


void free_node(t_node *node)
{
    if (node)
    {
        free(node->label);
        free(node);
        node = NULL;
    }
}



