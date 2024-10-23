#include "../inc/pathfinder.h"


int get_node_index(t_graph **graph, const t_node *node)
{
    for (int i = 0; i < (*graph)->count; ++i)
    {
        if (mx_strcmp((*graph)->nodes[i]->label, node->label) == 0)
        {
            return i;
        }
    }
    return -1;
}


