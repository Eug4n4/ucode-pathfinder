#include "../inc/pathfinder.h"


void free_graph(t_graph **graph)
{
    for (int i = 0; i < (*graph)->count; ++i)
    {
        t_node *node = (*graph)->nodes[i];
        free_node(node);
    }
    free((*graph)->nodes);
    (*graph)->nodes = NULL;
    free(*graph);
    *graph = NULL;
}



