/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** solver.h
*/

#ifndef SOLVER_H_
    #define SOLVER_H_
    #include "my.h"
    #include "myprintf.h"
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <string.h>
typedef struct infos {
    int size;
    int nb_cols;
    int nb_rows;
    char **map_str_tab;
    int **map_int_tab;
} infos_t;

typedef struct indexes {
    int row;
    int col;
} index_t;

int solver(char *filepath);
int fill_final_map(infos_t *map_infos, int row, int col);
int find_shortest_path(infos_t *map_infos, int row, int col);
char *load_file_in_str(char const *filepath);
void load_map_int(infos_t *map_infos);
int get_size(char *filepath);
int get_nb_rows(char *filepath);
int open_file(char const *filepath);
void load_map_char(char *filepath, infos_t *map_infos);
char **remove_end(char **map);
int check_map_size(infos_t *map, char **test);
#endif
