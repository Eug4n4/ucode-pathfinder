#include "../inc/pathfinder.h"


static void start(int fd, int *error)
{
    char *line[3] = {NULL, NULL, NULL};
    char delim = '-';
    int islands = get_island_count(fd);
    unsigned long long sum = 0;
    t_graph *graph = init_graph(islands);
    t_matrix *matrix = init_matrix(islands);
    bool first = false;
    bool second = false;
    t_node *existed = NULL;
    t_node *first_existed = NULL;
    char *str = NULL;
    int current_line = 2;
    int i = 0;

    while (mx_read_line(&str, 1, delim, fd) != -1)
    {
        line[i++] = mx_strdup(str);
        if (!first)
        {
            delim = ',';
            first = true;
        }
        else if (!second)
        {
            delim = '\n';
            second = true;
        }
        else
        {
            if (check_nodes(&graph, &matrix, line, error, current_line))
            {
                break;
            }
            first_existed = get_node_by_label(&graph, line[0]);
            existed = get_node_by_label(&graph, line[1]);
            if (!first_existed && !existed)
            {
                if (graph->count + 2 <= islands)
                {
                    graph->nodes[graph->count++] = init_node(line[0]);
                    graph->nodes[graph->count++] = init_node(line[1]);
                    first_existed = graph->nodes[graph->count - 2];
                    existed = graph->nodes[graph->count - 1];
                }
                else
                {
                    *error = ERR_NUM_ISLANDS;
                    break;
                }
            }
            else if (!first_existed)
            {
                if (graph->count != islands)
                {
                    graph->nodes[graph->count++] = init_node(line[0]);
                    first_existed = graph->nodes[graph->count - 1];
                }
                else
                {
                    *error = ERR_NUM_ISLANDS;
                    break;
                }
            }
            else if (!existed)
            {
                if (graph->count != islands)
                {
                    graph->nodes[graph->count++] = init_node(line[1]);
                    existed = graph->nodes[graph->count - 1];
                }
                else
                {
                    *error = ERR_NUM_ISLANDS;
                    break;
                }
            }
            int price = mx_atoi_positive(line[2]);

            sum += price;
            if (sum <= INT_MAX)
            {
                connect_nodes(&graph, &matrix, first_existed, existed, price);
                mx_strdel(&line[0]);
                mx_strdel(&line[1]);
                mx_strdel(&line[2]);
                first = false;
                second = false;
                i = 0;
                delim = '-';
                ++current_line;
            }
            else
            {
                *error = ERR_INVAL_SUM;
                break;
            }
        }
        mx_strdel(&str);
    }
    if (*error == 0)
    {
        if (first && graph->count != current_line)
        {
            *error = current_line;
        }
        else if (graph->count != islands)
        {
            *error = ERR_NUM_ISLANDS;
        }
        else
        {
            find_path(&graph, &matrix);
        }
    }
    mx_strdel(&str);
    mx_strdel(&line[0]);
    mx_strdel(&line[1]);
    mx_strdel(&line[2]);
    free_matrix(&matrix);
    free_graph(&graph);
}


int main(int argc, char **argv)
{
    int error = 0;

    find_errors(argc, argv, &error);
    if (!error)
    {
        int fd = open(argv[1], O_RDONLY);

        start(fd, &error);
        close(fd);
        if (error)
        {
            print_errors(argv, &error);
        }
    }
}



