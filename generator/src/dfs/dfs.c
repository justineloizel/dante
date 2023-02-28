/*
** EPITECH PROJECT, 2023
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** dfs.c
*/

#include <stdlib.h>
#include <time.h>
#include "generator.h"
#include "my.h"

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

    if (info->i >= 2 && verify_arround(maze, info->i - 2, info->j)) {
        info->table_possibility[possibility] = NORTH;
        possibility++;
    }
    if (SOUTH_POS && verify_arround(maze, info->i + 2, info->j)) {
        info->table_possibility[possibility] = SOUTH;
        possibility++;
    }
    if (info->j >= 2 && verify_arround(maze, info->i, info->j - 2)) {
        info->table_possibility[possibility] = WEST;
        possibility++;
    }
    if (EAST_POS && verify_arround(maze, info->i, info->j + 2)) {
        info->table_possibility[possibility] = EAST;
        possibility++;
    }
    return possibility;
}

void apply_choice(info_pos_t *info, int possibility, char **maze,
linked_list_t *list_node)
{
    int choice = rand() % possibility;

    if (possibility > 1)
        add_node(list_node, info->i, info->j);
    if (info->table_possibility[choice] == NORTH)
        DIR_NORTH;
    if (info->table_possibility[choice] == SOUTH)
        DIR_SOUTH;
    if (info->table_possibility[choice] == EAST)
        DIR_EAST;
    if (info->table_possibility[choice] == WEST)
        DIR_WEST;
    info->table_possibility[0] = -1;
    info->table_possibility[1] = -1;
    info->table_possibility[2] = -1;
    info->table_possibility[3] = -1;
}

void check_no_possibility(char **maze, info_pos_t *info, linked_list_t *list)
{
    info->i = list->tail->i;
    info->j = list->tail->j;
    delete_node(list, list->tail);
    while (verify_possibility(maze, info) == 0 && list->tail != NULL) {
        info->i = list->tail->i;
        info->j = list->tail->j;
        delete_node(list, list->tail);
    }
}

void create_maze_with_dsf(char** maze, int nb_column, int nb_line)
{
    info_pos_t info = {0, 0, nb_line, nb_column, {-1, -1, -1, -1}};
    linked_list_t list = {NULL, NULL};
    int possibility = 0;

    add_node(&list, info.i, info.j);
    srand(time(NULL));
    maze[0][0] = WAY;
    while (list.head != NULL) {
        possibility = verify_possibility(maze, &info);
        if (possibility)
            apply_choice(&info, possibility, maze, &list);
        else
            check_no_possibility(maze, &info, &list);
    }
    maze[nb_line - 1][nb_column -1] = WAY;
    if (!(nb_column % 2))
        maze[nb_line - 1][nb_column - 2] = WAY;
}
