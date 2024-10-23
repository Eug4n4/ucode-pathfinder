#include "../inc/pathfinder.h"


t_matrix *init_matrix(int n)
{
    t_matrix *matrix = malloc(sizeof(t_matrix));

    if (!matrix)
    {
        return NULL;
    }
    matrix->n = n;
    matrix->matrix = malloc(sizeof(int *) * n);
    if (!matrix->matrix)
    {
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        matrix->matrix[i] = malloc(sizeof(int) * n);
        if (!matrix->matrix[i])
        {
            return NULL;
        }
        mx_memset(matrix->matrix[i], 0, sizeof(int) * n);
    }

    return matrix;
}




