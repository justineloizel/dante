/*
** EPITECH PROJECT, 2023
** B-CPE-200-REN-2-1-dante-tom.lefoix
** File description:
** dfs_list.c
*/

#include <stdlib.h>
#include "generator.h"

static node_t *init_node(int i, int j)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL)
        return NULL;
    node->next = NULL;
    node->prev = NULL;
    node->i = i;
    node->j = j;
    return node;
}

void add_node(linked_list_t *list, int i, int j)
{
    if (list->head == NULL) {
        list->head = init_node(i, j);
        list->tail = list->head;
        return;
    }
    list->tail->next = init_node(i, j);
    list->tail->next->prev = list->tail;
    list->tail = list->tail->next;
}

void delete_node(linked_list_t *list, node_t *target)
{
    node_t *node = list->tail;

    for (; node != NULL && node != target;
        node = node->prev);
    if (node == NULL)
        return;
    if (list->head == node)
        list->head = node->next;
    if (list->tail == node)
        list->tail = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    free(node);
}
