/*
** EPITECH PROJECT, 2023
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** generator.h
*/
#ifndef GENERATOR_H_
	#define GENERATOR_H_
int generator(int nb_line, int nb_column, int is_perfect);
void create_perfect_maze(char **maze, int nb_line, int nb_column);
void create_imperfect_maze(char **maze);

typedef enum element {
    WALLS = 'X',
    WAY = '*'
}element_t;


//DFS
typedef struct node {
    int i;
    int j;
    struct node *next;
    struct node *prev;
}node_t;

typedef struct linked_list {
    node_t *head;
    node_t *tail;
}linked_list_t;

typedef struct info_pos {
    int i;
    int j;
    int nb_line;
    int nb_column;
}info_pos_t;
void delete_node(linked_list_t *list, node_t *target);
void add_node(linked_list_t *list, int i, int j);
void create_maze_with_dsf(char** maze, int nb_column, int nb_line);
#endif /*GENERATOR_H_*/

