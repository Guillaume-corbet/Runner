/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** pause
*/

#include "my_runner.h"

void fonc_pause(runner_t *ru, rlist_spike *p_list_spike)
{
    sfMusic_pause(ru->music);
    while (ru->event.key.code != sfKeySpace) {
        sfRenderWindow_pollEvent(ru->window, &ru->event);
        sfRenderWindow_drawText(ru->window, ru->pause, NULL);
        sfRenderWindow_display(ru->window);
        if (ru->event.type == sfEvtClosed)
            destroy(ru, p_list_spike);
        sfMusic_play(ru->music);
    }
    sfClock_restart(ru->clock_map);
}