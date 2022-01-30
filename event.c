/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** event
*/

#include "my_runner.h"

void event_main(runner_t *ru, rlist_spike *p_list_spike)
{
    while (sfRenderWindow_pollEvent(ru->window, &ru->event)) {
        if (ru->event.type == sfEvtClosed)
            destroy(ru, p_list_spike);
        if (ru->event.key.code == sfKeySpace)
            ru->jump = 1;
        if (ru->event.key.code == sfKeyEscape)
            fonc_pause(ru, p_list_spike);
    }
}