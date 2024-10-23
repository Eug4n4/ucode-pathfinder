#include "../inc/pathfinder.h"

bool is_connection_exist(t_graph **graph, t_matrix **matrix, t_node *n1,
                         t_node *n2)
{
    int first = get_node_index(graph, n1);
    int second = get_node_index(graph, n2);
    int res = (*matrix)->matrix[first][second];

    return res;
}


