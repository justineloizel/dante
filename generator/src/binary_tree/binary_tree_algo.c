/*
** EPITECH PROJECT, 2023
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** binary_tree_algo.c
*/

#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "generator.h"

void create_maze_line(char **maze, int i, int nb_column)
{
    int random;
    if (maze[i] == NULL)
        return;
    for (int j = 1; j < nb_column; j += 2) {
        random = rand() % 2;
        if (random == 1)
            maze[i - 1][j] = WAY;
        else {
            maze[i][j - 1] = WAY;
        }
    }
}

void create_perfect_maze(char **maze, int nb_line, int nb_column)
{
    srand(time(NULL));
    for (int i = 1; i < nb_line; i += 2) {
        create_maze_line(maze, i, nb_column);
    }
    for (int i = 0; maze[nb_line - 1][i]; i++) {
        if (rand() % 2)
            maze[nb_line - 1][i] = WAY;
    }
    maze[0][0] = WAY;
    maze[nb_line - 1][nb_column - 1] = WAY;
    maze[nb_line - 1][nb_column - 2] = WAY;
}
