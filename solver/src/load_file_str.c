/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** load_file_map.c
*/

#include "solver.h"

static int check_char(char **map, int i, int j)
{
    for (; map[i][j] != '\n'; j++) {
        if (map[i][j] != '*' && map[i][j] != 'X' &&
        map[i][j] != '\n' && map[i][j] != '\0') {
            my_printf(" i = %i  j = %i-----%c\n", i, j, map[i][j]);
            return 1;
        }
    }
    return 0;
}

static int check_content(char **map)
{
    int i = 0;
    int j = 0;

    for (; map[i] != NULL; i++) {
        if (check_char(map, i, j) == 1)
            return 1;
    }
    return 0;
}

static int get_nb_line(char *filepath)
{
    FILE *fp;
    size_t len = 0;
    char *line = NULL;
    int nb_line = 0;

    fp = fopen(filepath, "r");
    while ((getline(&line, &len, fp)) != -1) {
        nb_line += 1;
        free(line);
        line = NULL;
    }
    fclose(fp);
    return nb_line;
}

static char **check_errors(char **map)
{
    if (map[0] == NULL)
        return NULL;
    if (check_content(map) == 1)
        return NULL;
    map = remove_end(map);
    return map;
}

char **load_map_char(char *filepath, infos_t *map_infos)
{
    int i = 0;
    char **map = NULL;
    FILE *fp;
    size_t len = 0;
    char *line = NULL;
    int nb_line = 0;

    nb_line = get_nb_line(filepath);
    map_infos->nb_rows = nb_line;
    fp = fopen(filepath, "r");
    map = malloc(sizeof(char *) * (nb_line + 1));
    while ((getline(&line, &len, fp)) != -1) {
        map[i] = line;
        line = NULL;
        i++;
    }
    map[i] = NULL;
    map = check_errors(map);
    fclose(fp);
    return map;
}
