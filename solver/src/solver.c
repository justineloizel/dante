/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** solver.c
*/

#include "solver.h"

int print_tab(int **tab, infos_t *map_infos)
{
    for (int i = 0; i != map_infos->nb_rows; i++) {
        for (int j = 0; j != map_infos->nb_cols; j++)
            my_printf("%d", tab[i][j]);
        my_printf("\n");
    }
    return 0;
}

int solver(char *filepath)
{
    infos_t *map_infos = malloc(sizeof(infos_t));

    map_infos->size = get_size(filepath);
    map_infos->map_str_tab = load_map_char(filepath, map_infos);
    if (map_infos->map_str_tab == NULL)
        return 84;
    map_infos->nb_cols = ((map_infos->size - map_infos->nb_rows)
    / map_infos->nb_rows);
    load_map_int(map_infos);
    map_infos->map_int_tab[map_infos->nb_rows - 1][map_infos->nb_cols - 1] = 1;
    find_shortest_path(map_infos, map_infos->nb_rows - 1,
    map_infos->nb_cols - 1);
    fill_final_map(map_infos, 0, 0);
    my_puttab(map_infos->map_str_tab);
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 2) {
        my_printf("%z", "Too many arguments.\n");
        return 84;
    }
    if (ac < 2) {
        my_printf("%z", "Too few arguments.\n");
        return 84;
    }
    if (ac == 2)
        if (solver(av[1]) != 0)
            return 84;
    return 0;
}
