/*
** EPITECH PROJECT, 2023
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** generator.h
*/
#ifndef GENERATOR_H_
	#define GENERATOR_H_
int generator(int nb_line, int nb_column, int is_perfect);
void create_perfect_maze(char **maze, int nb_line, int nb_column);

typedef enum element {
    WALLS = 'X',
    WAY = '*'
}element_t;
#endif /*GENERATOR_H_*/

