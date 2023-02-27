/*
** EPITECH PROJECT, 2023
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** main.c
*/

#include "generator.h"
#include "my.h"

int main(int ac, char **av)
{
    if (ac != 3 && ac != 4)
        return 84;
    else if (ac == 4 && my_strcmp(av[3], "perfect") != 0)
        return 84;
    if (generator(my_getnbr(av[1]), my_getnbr(av[2]), ac - 3) == 84)
        return 84;
    return 0;
}
