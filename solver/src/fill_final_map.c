/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** fill_numbers.c
*/

#include "solver.h"

static int fill_final_loop(infos_t *map, int row, int col)
{
    if (row > 0 && (map->map_int_tab[row][col] - 1) ==
    (map->map_int_tab[row - 1][col])) {
        map->map_str_tab[row][col] = 'o';
        if (fill_final_map(map, row - 1, col) == 1)
            return 1;
    }
    if (col > 0 && (map->map_int_tab[row][col] - 1) ==
    (map->map_int_tab[row][col - 1])) {
        map->map_str_tab[row][col] = 'o';
        if (fill_final_map(map, row, col - 1) == 1)
            return 1;
    }
    return 0;
}

int fill_final_map(infos_t *map, int row, int col)
{
    if (row == map->nb_rows - 1 && col == map->nb_cols -1) {
        map->map_str_tab[row][col] = 'o';
        return 1;
    }
    if (col < map->nb_cols - 1 && (map->map_int_tab[row][col] - 1) ==
    (map->map_int_tab[row][col + 1])) {
        map->map_str_tab[row][col] = 'o';
        if (fill_final_map(map, row, col + 1) == 1)
            return 1;
    }
    if (row < map->nb_rows - 1 && (map->map_int_tab[row][col] - 1) ==
    (map->map_int_tab[row + 1][col])) {
        map->map_str_tab[row][col] = 'o';
        if (fill_final_map(map, row + 1, col) == 1)
            return 1;
    }
    if (fill_final_loop(map, row, col) == 1)
        return 1;
    return 0;
}
