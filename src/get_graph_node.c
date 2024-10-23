#include "../inc/pathfinder.h"


char *get_label_by_index(t_graph **graph, int index)
{
    return (*graph)->nodes[index]->label;
}

t_node *get_node_by_label(t_graph **graph, char *label)
{
    if ((*graph)->count)
    {
        for (int i = 0; i < (*graph)->count; ++i)
        {
            if (mx_strcmp(get_label_by_index(graph, i), label) == 0)
            {
                return (*graph)->nodes[i];
            }
        }
    }
    return NULL;
}




