/*
** EPITECH PROJECT, 2023
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** generator.c
*/

#include <string.h>
#include <stdlib.h>
#include "generator.h"
#include "my.h"
#include "myprintf.h"

char *fill_line(int nb_column, int line_object)
{
    char *line = malloc(sizeof(char ) * nb_column + 1);

    if (line == NULL)
        return NULL;
    for (int i = 0; i < nb_column; i++) {
        if (line_object) {
            line[i] = (char)line_object;
            continue;
        }
        if (i % 2)
            line[i] = WAY;
        else
            line[i] = WALLS;
    }
    line[nb_column] = '\0';
    return line;
}

char **create_simple_map(int nb_line, int nb_column)
{
    char **maze = malloc(sizeof(char *) * (nb_line + 1));

    if (maze == NULL)
        return NULL;
    maze[0] = fill_line(nb_column,WALLS);
    for (int i = 1; i < nb_line; i++) {
        if ((i % 2))
            maze[i] = fill_line(nb_column, WALLS);
        else
            maze[i] = fill_line(nb_column, WALLS);
    }
    maze[nb_line] = NULL;
    return maze;
}

int generator(int nb_line, int nb_column, int is_perfect)
{
    char **maze = create_simple_map(nb_line, nb_column);

    if (maze == NULL) {
        return 84;
    }
    create_maze_with_dsf(maze, nb_column, nb_line);
    if (!is_perfect)
        create_imperfect_maze(maze);
    my_puttab(maze);
    free_tab(maze);
    return 0;
}
