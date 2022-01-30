/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** ending
*/

#include "my_runner.h"

int ending_lost(runner_t *ru)
{
    sfMusic_stop(ru->music);
    sfMusic_play(ru->music_lose);
    while (ru->event.key.code != sfKeyEscape && ru->event.type != sfEvtClosed) {
        sfRenderWindow_pollEvent(ru->window, &ru->event);
        sfRenderWindow_drawText(ru->window, ru->lose, NULL);
        sfRenderWindow_display(ru->window);
    }
}

int ending_win(runner_t *ru)
{
    sfMusic_stop(ru->music);
    sfMusic_play(ru->music_ending);
    while (ru->event.key.code != sfKeyEscape && ru->event.type != sfEvtClosed) {
        sfRenderWindow_pollEvent(ru->window, &ru->event);
        sfRenderWindow_drawText(ru->window, ru->win, NULL);
        sfRenderWindow_display(ru->window);
    }
}