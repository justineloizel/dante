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
    for (int j = 2; j < nb_column; j += 2) {
        maze[i][j] = WAY;

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
    for (int i = 2; i < nb_line; i += 2) {
        create_maze_line(maze, i, nb_column);
    }
    for (int i = 0; maze[i]; i++) {
        maze[i][0] = WAY;
    }

}
