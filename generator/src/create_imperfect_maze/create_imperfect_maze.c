/*
** EPITECH PROJECT, 2023
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** create_imperfect_maze.c
*/

#include <stdlib.h>
#include "generator.h"

void modify_line_maze(char *line)
{
    for (int i = 0; line[i]; i++) {
        if (line[i] == WALLS && !(rand() % 3))
            line[i] = WAY;
    }
}

void create_imperfect_maze(char **maze)
{
    for (int i = 0; maze[i]; i++)
        modify_line_maze(maze[i]);
}
