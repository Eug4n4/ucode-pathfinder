#include "../inc/pathfinder.h"


int check_island_label(const char *label)
{
    int len = mx_strlen(label);

    if (!len)
    {
        return -1;
    }
    for (int i = 0; i < len; i++)
    {
        if (!mx_isalpha(label[i]))
        {
            return -1;
        }
    }
    return 0;
}


bool check_nodes(t_graph **graph, t_matrix **matrix, char **line, int *error,
                 int cur_line)
{
    int state1 = check_island_label(line[0]);
    int state2 = check_island_label(line[1]);

    if (state1 == -1 || state2 == -1)
    {
        *error = cur_line;
        return true;
    }
    t_node *n1 = get_node_by_label(graph, line[0]);
    t_node *n2 = get_node_by_label(graph, line[1]);

    if (n1 && n2 && is_connection_exist(graph, matrix, n1, n2))
    {
        *error = ERR_DUP_ISLANDS;
        return true;
    }
    if (!mx_strcmp(line[0], line[1]))
    {
        *error = cur_line;
        return true;
    }
    int price = mx_atoi_positive(line[2]);

    if (!price)
    {
        *error = cur_line;
        return true;
    }
    return false;
}



