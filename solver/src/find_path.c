/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** find_path.c
*/

#include "solver.h"

static int path_right_up(infos_t *map, int row, int col)
{
    if (row < map->nb_rows - 1 && map->map_int_tab[row + 1][col] == 0) {
        map->map_int_tab[row + 1][col] = map->map_int_tab[row][col] + 1;
        if (find_shortest_path(map, row + 1, col) == 1)
            return 1;
    }
    if (col < map->nb_cols - 1 && map->map_int_tab[row][col + 1] == 0) {
        map->map_int_tab[row][col + 1] = map->map_int_tab[row][col] + 1;
        if (find_shortest_path(map, row, col + 1) == 1)
            return 1;
    }
    return 0;
}

int find_shortest_path(infos_t *map, int row, int col)
{
    if (row == 0 && col == 0)
        return 1;
    if (col > 0 && map->map_int_tab[row][col - 1] == 0) {
        map->map_int_tab[row][col - 1] = map->map_int_tab[row][col] + 1;
        if (find_shortest_path(map, row, col - 1) == 1)
            return 1;
    }
    if (row > 0 && map->map_int_tab[row - 1][col] == 0) {
        map->map_int_tab[row - 1][col] = map->map_int_tab[row][col] + 1;
        if (find_shortest_path(map, row - 1, col) == 1)
            return 1;
    }
    if (path_right_up(map, row, col) == 1)
        return 1;
    return 0;
}
