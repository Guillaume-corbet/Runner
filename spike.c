/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** spike
*/

#include "my_runner.h"

rlist_spike *spike_create(runner_t *ru, rlist_spike *p_list_spike)
{
    dlist_append_spike(p_list_spike);
    return (p_list_spike);
}

void spike_erase(runner_t *ru, rlist_spike *p_list_spike)
{
    if (p_list_spike->p_head->move_spike.x <= 99 && p_list_spike->length != 0) {
        sfSprite_destroy(p_list_spike->p_head->sprite_spike);
        sfTexture_destroy(p_list_spike->p_head->texture_spike);
        dlist_remove_spike(p_list_spike, 1);
        ru->scores = ru->scores + 1;
    }
}

rlist_spike *spike_main(runner_t *ru, rlist_spike *p_list_spike)
{
    int count = 0;
    void *point;

    spike_erase(ru, p_list_spike);
    point = p_list_spike->p_head;
    while (count != p_list_spike->length) {
        p_list_spike->p_head->move_spike.x =
        p_list_spike->p_head->move_spike.x - 35;
        sfSprite_setPosition(p_list_spike->p_head->sprite_spike,
        p_list_spike->p_head->move_spike);
        sfRenderWindow_drawSprite(ru->window,
        p_list_spike->p_head->sprite_spike, NULL);
        p_list_spike->p_head = p_list_spike->p_head->p_next;
        count = count + 1;
    }
    p_list_spike->p_head = point;
    return (p_list_spike);
}