/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** solver.c
*/

#include <sys/resource.h>
#include "solver.h"

int check_map_size(infos_t *map, char **test)
{
    int len = map->nb_cols;

    for (int i = 0; test[i] != NULL; i++) {
        if (test[i + 1] == NULL && my_strlen(test[i]) == len)
            return 0;
        if (my_strlen(test[i]) - 1 != len) {
            return 1;
        }
    }
    return 0;
}

int solver(char *filepath)
{
    infos_t *map = malloc(sizeof(infos_t));

    map->size = get_size(filepath);
    load_map_char(filepath, map);
    if (map->map_str_tab == NULL ||
    map->map_str_tab[map->nb_rows -1][map->nb_cols - 1] == 'X' ||
    map->map_str_tab[0][0] == 'X')
        return 84;
    load_map_int(map);
    map->map_int_tab[map->nb_rows - 1][map->nb_cols - 1] = 1;
    if (find_shortest_path(map, map->nb_rows - 1,
    map->nb_cols - 1) == 0) {
        write(1, "no solution found.", 18);
        return 84;
    }
    fill_final_map(map, 0, 0);
    my_puttab(map->map_str_tab);
    return 0;
}

void upgrade_stack(void)
{
    struct rlimit rlim;

    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = rlim.rlim_max;
    setrlimit(RLIMIT_STACK, &rlim);
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
    if (ac == 2) {
        upgrade_stack();
        if (solver(av[1]) != 0)
            return 84;
    }
    return 0;
}
