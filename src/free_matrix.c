#include "../inc/pathfinder.h"


void free_matrix(t_matrix **matrix)
{
    for (int i = 0; i < (*matrix)->n; ++i)
    {
        free((*matrix)->matrix[i]);
    }
    free((*matrix)->matrix);
    (*matrix)->matrix = NULL;
    free(*matrix);
    *matrix = NULL;
}



