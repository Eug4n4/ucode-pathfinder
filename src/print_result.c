#include "../inc/pathfinder.h"


static void print_distance(t_graph **graph, t_pqueue **queue, t_pqnode *dest,
                           int *route)
{
    mx_printstr("Distance: ");
    int route_len = 0;
    t_pqnode *first = get_queue_node_by_label(queue, get_label_by_index(graph, route[0]));
    int price = first->price;

    while (route[++route_len] != -1);

    for (int k = 1; k < route_len; ++k)
    {
        t_pqnode *second = get_queue_node_by_label(queue, get_label_by_index(graph, route[k]));
        char *str_price = mx_itoa(second->price - price);
        mx_printstr(str_price);
        mx_strdel(&str_price);
        if (k + 1 != route_len)
        {
            mx_printstr(" + ");
        }
        price = second->price;
    }
    if (route_len > 2)
    {
        mx_printstr(" = ");
        char *sum_str = mx_itoa(dest->price);
        mx_printstr(sum_str);
        mx_strdel(&sum_str);
    }
    mx_printchar('\n');
}


static void print_route(t_graph **graph, t_pqueue **queue, int *route)
{
    mx_printstr("Route: ");
    for (int i = 0; route[i] != -1; ++i)
    {
        t_pqnode *n = get_queue_node_by_label(queue, get_label_by_index(graph, route[i]));
        mx_printstr(n->data->label);
        if (route[i + 1] != -1)
        {
            mx_printstr(" -> ");
        }
    }
    mx_printchar('\n');
}


static void print_path(t_pqnode *from, t_pqnode *to)
{
    mx_printstr("\nPath: ");
    mx_printstr(from->data->label);
    mx_printstr(" -> ");
    mx_printstr(to->data->label);
    mx_printchar('\n');
}


void print_paths(t_graph **graph, t_pqueue **queue, int next_idx)
{
    t_pqnode *source = (*queue)->head;

    for (int i = next_idx; i < (*graph)->count; ++i)
    {
        t_pqnode *dest = get_queue_node_by_label(queue, get_label_by_index(graph, i));
        if (!dest)
        {
            continue;
        }
        for (int j = 0; j < dest->count; ++j)
        {
            int *route = dest->routes[j];

            mx_printstr(BORDER);
            print_path(source, dest);
            print_route(graph, queue, route);
            print_distance(graph, queue, dest, route);
            mx_printstr(BORDER);
            mx_printchar('\n');
        }
    }
}




