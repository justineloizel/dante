/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** load_file_map.c
*/

#include "solver.h"

char **remove_end(char **map)
{
    int j = 0;
    int i = 0;

    for (; map[i] != NULL; i++) {
        for (; map[i][j] != '\n'; j++);
        map[i][j] = '\0';
    }
    return map;
}

static int **modify_map(int **map, char **map_str, index_t *index)
{
    if (map_str[index->row][index->col] == '*') {
        map[index->row][index->col] = 0;
        return map;
    }
    if (map_str[index->row][index->col] == 'X') {
        map[index->row][index->col] = -1;
        return map;
    }
    if (map_str[index->row][index->col] == '\0') {
        map[index->row][index->col] = -2;
        return map;
    }
    return map;
}

static int **fill_zero(int **map, infos_t *map_infos)
{
    for (int i = 0; i != map_infos->nb_rows; i++) {
        for (int j = 0; j != map_infos->nb_cols; j++)
            map[i][j] = 0;
    }
    return map;
}

void load_map_int(infos_t *map_infos)
{
    int **map = NULL;
    index_t *index = malloc(sizeof(index_t));

    index->row = 0;
    map = malloc(sizeof(int *) * map_infos->nb_rows + 1);
    if (!map)
        return;
    for (int m = 0; m < map_infos->nb_rows; m++) {
        map[m] = malloc(sizeof(int) * map_infos->nb_cols + 1);
        if (!map[m])
            return;
    }
    map = fill_zero(map, map_infos);
    for (; index->row != map_infos->nb_rows; index->row++) {
        for (index->col = 0; index->col != map_infos->nb_cols; index->col++)
            map = modify_map(map, map_infos->map_str_tab, index);
    }
    map_infos->map_int_tab = map;
}
