#ifndef PATHFINDER_H
#define PATHFINDER_H
#define BORDER "========================================"
#define ERR_FILE_EXIST -1
#define ERR_FILE_EOF -2
#define ERR_NUM_ISLANDS -3
#define ERR_DUP_ISLANDS -4
#define ERR_INVAL_SUM -5
#define ERR_INVAL_ARGS -6
#define ERR_INVAL_LINE 1
#include "libmx.h"
#include <limits.h>

typedef struct s_node
{
	char *label;
	bool is_visited;
}                t_node;


typedef struct s_pqnode
{
	t_node *data;
	int price;
	int count;
	struct s_pqnode *next;
	int **routes;

}              t_pqnode;

typedef struct s_pqueue
{
	t_pqnode *head;

}              t_pqueue;

typedef struct s_graph
{
	int count;
	t_node **nodes;
}                t_graph;


typedef struct s_matrix
{
	int n;
	int **matrix;
}                t_matrix;

t_graph *init_graph(int islands);
void free_graph(t_graph **graph);


t_node *init_node(const char *label);
void free_node(t_node *node);
int get_node_index(t_graph **graph, const t_node *node);
t_node *get_node_by_label(t_graph **graph, char *label);
char *get_label_by_index(t_graph **graph, int index);
void connect_nodes(t_graph **graph, t_matrix **matrix, t_node *first, t_node *second, int price);
bool is_connection_exist(t_graph **graph, t_matrix **matrix, t_node *n1, t_node *n2);

t_matrix *init_matrix(int n);
void free_matrix(t_matrix **matrix);

int get_island_count(int fd);
int check_island_label(const char *label);

void print_errors(char **argv, int *error);
void find_errors(int argc, char **argv, int *error);
void check_file(char **argv, int *error);
void check_eof(int fd, int *error);
bool check_nodes(t_graph **graph, t_matrix **matrix, char **line,
	int *error, int cur_line);

t_pqueue *init_pqueue(t_node *root);
t_pqnode *get_queue_node_by_label(t_pqueue **queue, const char *label);
t_pqnode *get_queue_unvisited_node(t_pqueue **queue);
t_pqnode *init_queue_node(t_node *data, int price);
void insert(t_pqueue *queue, t_node *data, int est, int price);
void free_pqueue(t_pqueue *head);
void find_path(t_graph **graph, t_matrix **matrix);
void find_routes(t_graph **graph, t_matrix **matrix, t_pqnode *dest,
                 int *route, int idx, int start, int end);
void print_paths(t_graph **graph, t_pqueue **queue, int next_idx);
#endif // PATHFINDER_H



