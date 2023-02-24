/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** get_file_infos.c
*/

#include "solver.h"

int get_size(char *filepath)
{
    struct stat structure;
    int size = 0;
    int fd = 0;

    stat(filepath, &structure);
    fd = open_file(filepath);
    size = structure.st_size;
    close(fd);
    return size;
}

int open_file(char const *filepath)
{
    int fd = 0;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        write(2, "Cannot open file.\n", 18);
    return fd;
}
