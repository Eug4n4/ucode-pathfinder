#include "../inc/pathfinder.h"


t_graph *init_graph(int islands)
{
    t_graph *graph = malloc(sizeof(t_graph));

    if (!graph)
    {
        return NULL;
    }
    graph->nodes = malloc(sizeof(t_node *) * islands);
    if (!graph->nodes)
    {
        return NULL;
    }
    graph->count = 0;

    return graph;
}




