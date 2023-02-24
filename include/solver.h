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
    char *map_str;
} infos_t;

typedef struct indexes {
    int row;
    int col;
} index_t;

int solver(char *filepath);
char *load_file_in_str(char const *filepath);
int **load_map_int(infos_t *map_infos);
int get_size(char *filepath);
int get_nb_rows(char *filepath);
int open_file(char const *filepath);
char **load_map_char(char *filepath, infos_t *map_infos);
int print_tab(int **tab, infos_t *map_infos);
char **remove_end(char **map);
#endif
