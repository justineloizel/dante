/*
** EPITECH PROJECT, 2023
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** dfs.c
*/

#include <stdlib.h>
#include <time.h>
#include "generator.h"
#include "myprintf.h"

int verify_arround(char **maze, int i, int j)
{
    if (maze[i][j] != WALLS)
        return 0;
    if (j > 0 && (maze[i][j - 1] == WAY))
        return 0;
    if (maze[i][j + 1] == WAY)
        return 0;
    return 1;
}

int verify_possibility(char **maze, info_pos_t *info)
{
    int possibility = 0;

    if (info->i >= 2 && verify_arround(maze, info->i - 2, info->j))
        possibility++;
    if (info->i < info->nb_line - 2 && verify_arround(maze, info->i + 2, info->j))
        possibility++;
    if (info->j >= 2 && verify_arround(maze, info->i, info->j - 2))
        possibility++;
    if (info->j < info->nb_column - 2 && verify_arround(maze, info->i, info->j + 2))
        possibility++;
    return possibility;
}

void create_maze_with_dsf(char** maze, int nb_column, int nb_line)
{
    info_pos_t info = {0, 0, nb_line, nb_column};
    linked_list_t list = {NULL, NULL};

    add_node(&list, info.i, info.j);
    srand(time(NULL));
    while (list.head != NULL) {

    }
}
