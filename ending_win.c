/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** ending_win
*/

#include "my_runner.h"

void ending_castle(runner_t *ru, rlist_spike *p_list_spike)
{
    ru->move_character.x = ru->move_character.x + 40;
    ru->rect_firework.top = ru->rect_firework.top + 50;
    if (ru->rect_firework.top == 350)
        ru->rect_firework.top = 50;
    sfSprite_setTextureRect(ru->sprite_firework, ru->rect_firework);
    sfRenderWindow_drawSprite(ru->window, ru->sprite_fond, NULL);
    sfRenderWindow_drawSprite(ru->window, ru->sprite_fond_second, NULL);
    if (ru->move_character.x <= 1560)
        sfRenderWindow_drawSprite(ru->window, ru->sprite_firework, NULL);
    sfRenderWindow_drawSprite(ru->window, ru->sprite_ground, NULL);
    sfRenderWindow_drawSprite(ru->window, ru->sprite_castle, NULL);
    if (ru->move_character.x <= 1560)
        character_main(ru, p_list_spike);
    sfRenderWindow_display(ru->window);
    sfClock_restart(ru->clock_map);
}

void ending(runner_t *ru, rlist_spike *p_list_spike)
{
    sfMusic_stop(ru->music);
    sfClock_restart(ru->clock_map);
    castle_create(ru);
    firework_create(ru);
    sfMusic_play(ru->music_ending);
    while (ru->move_character.x <= 1560) {
        ru->time_map = sfClock_getElapsedTime(ru->clock_map);
        ru->seconds_map = ru->time_map.microseconds / 1000000.0;
        if (ru->seconds_map >= 0.1)
            ending_castle(ru, p_list_spike);
    }
    ru->winner = 1;
}