#include "../inc/pathfinder.h"

static void resize_routes(t_pqnode *node)
{
    node->count++;
    node->routes = mx_realloc(node->routes, sizeof(int *) * node->count);
}


static void add_route(t_pqnode *dest, int *route)
{
    int route_len = 0;
    while (route[++route_len] != -1);

    int *res = malloc(sizeof(int) * (route_len + 1));

    if (res)
    {
        mx_memcpy(res, route, sizeof(int) * route_len);
        res[route_len] = -1;
        resize_routes(dest);
        dest->routes[dest->count - 1] = res;
    }
}


void find_routes(t_graph **graph, t_matrix **matrix, t_pqnode *dest, int *route,
                 int idx, int start, int end)
{
    static int price = 0;

    if (!dest)
    {
        return;
    }
    (*graph)->nodes[start]->is_visited = true;
    if (start == end)
    {
        route[idx] = -1;
        add_route(dest, route);
        (*graph)->nodes[end]->is_visited = false;
        return;
    }

    for (int i = 0; i < (*graph)->count; ++i)
    {
        if (!(*graph)->nodes[i]->is_visited && (*matrix)->matrix[start][i] > 0)
        {
            price += (*matrix)->matrix[start][i];
            if (price <= dest->price)
            {
                route[idx++] = i;
                find_routes(graph, matrix, dest, route, idx, i, end);
                --idx;
            }
            price -= (*matrix)->matrix[start][i];
        }
    }
    (*graph)->nodes[start]->is_visited = false;
}



