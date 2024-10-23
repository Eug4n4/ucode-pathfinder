#include "../inc/pathfinder.h"


static int queue_size(t_pqueue **queue)
{
    t_pqnode *tmp = (*queue)->head;
    int size = 0;

    while (tmp)
    {
        ++size;
        tmp = tmp->next;
    }
    return size;
}


static void create_paths(t_graph **graph, t_matrix **matrix, t_pqueue **queue,
                         int next_idx)
{
    int route[queue_size(queue)];
    int start = get_node_index(graph, (*queue)->head->data);
    route[0] = start;

    for (int j = next_idx; j < (*graph)->count; ++j)
    {
        for (int i = 0; i < (*graph)->count; ++i)
        {
            (*graph)->nodes[i]->is_visited = false;
        }
        t_pqnode *dest = get_queue_node_by_label(queue, get_label_by_index(graph, j));

        find_routes(graph, matrix, dest, route, 1, start, j);
    }
    print_paths(graph, queue, next_idx);
}


static void update_neighbours(t_graph **graph, t_matrix **matrix,
                              t_pqueue *queue, t_pqnode *first, int *total_sum)
{
    int sum = *total_sum;
    int idx = get_node_index(graph, first->data);
    int *prices = (*matrix)->matrix[idx];
    int min = prices[(*matrix)->n - 1];

    for (int j = 0; j < (*matrix)->n; ++j)
    {
        if (!(*graph)->nodes[j]->is_visited)
        {
            if (prices[j] != 0)
            {
                if (min == 0)
                {
                    min = prices[j];
                }
                if (prices[j] < min)
                {
                    min = prices[j];
                }
                insert(queue, (*graph)->nodes[j], sum, prices[j]);
            }
        }
    }
    *total_sum += min;
    (*graph)->nodes[idx]->is_visited = true;
}


void find_path(t_graph **graph, t_matrix **matrix)
{
    for (int i = 0; i < (*graph)->count - 1; ++i)
    {
        for (int j = 0; j < (*graph)->count; ++j)
        {
            (*graph)->nodes[j]->is_visited = false;
        }
        int sum = 0;
        t_node *first = (*graph)->nodes[i];
        t_pqueue *queue = init_pqueue(first);
        t_pqnode *head = queue->head;

        while (head)
        {
            update_neighbours(graph, matrix, queue, head, &sum);
            head->data->is_visited = true;
            head = get_queue_unvisited_node(&queue);
            if (!head)
            {
                break;
            }
            if (sum != head->price)
            {
                sum = head->price;
            }
        }
        create_paths(graph, matrix, &queue, i + 1);
        free_pqueue(queue);
    }
}



