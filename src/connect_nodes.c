#include "../inc/pathfinder.h"

void connect_nodes(t_graph **graph, t_matrix **matrix, t_node *first,
                   t_node *second, int price)
{
    int n1 = get_node_index(graph, first);
    int n2 = get_node_index(graph, second);

    (*matrix)->matrix[n1][n2] = price;
    (*matrix)->matrix[n2][n1] = price;
}



