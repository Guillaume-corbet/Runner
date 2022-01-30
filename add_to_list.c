/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** add_to_list
*/

#include "my_runner.h"

void dlist_append_second_spike(rlist_spike *p_list, struct node_spike *p_new)
{
    if (p_list->p_tail == NULL) {
        p_new->p_prev = NULL;
        p_list->p_head = p_new;
        p_list->p_tail = p_new;
    } else {
        p_list->p_tail->p_next = p_new;
        p_new->p_prev = p_list->p_tail;
        p_list->p_tail = p_new;
    }
    p_list->length = p_list->length + 1;
}

void dlist_append_spike(rlist_spike *p_list)
{
    if (p_list != NULL) {
        struct node_spike *p_new = malloc(sizeof(*p_new));
        if (p_new != NULL) {
            p_new->move_spike.x = 2000;
            p_new->move_spike.y = 770;
            p_new->sprite_spike = sfSprite_create();
            p_new->texture_spike = sfTexture_createFromFile("spike.png", NULL);
            sfSprite_setTexture(p_new->sprite_spike,
            p_new->texture_spike, sfTrue);
            p_new->p_next = NULL;
            dlist_append_second_spike(p_list, p_new);
        }
    }
}