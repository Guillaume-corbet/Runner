/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** destroy
*/

#include "my_runner.h"

void destroy_spike(runner_t *ru, rlist_spike *p_list_spike)
{
    while (p_list_spike->length != 0) {
        sfSprite_destroy(p_list_spike->p_head->sprite_spike);
        sfTexture_destroy(p_list_spike->p_head->texture_spike);
        dlist_remove_spike(p_list_spike, 1);
    }
}

void destroy_music(runner_t *ru)
{
    sfMusic_stop(ru->music_ending);
    sfMusic_stop(ru->music);
    sfMusic_stop(ru->music_lose);
    sfMusic_destroy(ru->music);
    sfMusic_destroy(ru->music_ending);
    sfMusic_destroy(ru->music_lose);
}

void destroy(runner_t *ru, rlist_spike *p_list_spike)
{
    destroy_music(ru);
    sfText_destroy(ru->score);
    sfText_destroy(ru->score_number);
    sfText_destroy(ru->pause);
    sfFont_destroy(ru->font);
    destroy_spike(ru, p_list_spike);
    sfSprite_destroy(ru->sprite_character);
    sfSprite_destroy(ru->sprite_ground);
    sfSprite_destroy(ru->sprite_fond_second);
    sfSprite_destroy(ru->sprite_fond);
    sfTexture_destroy(ru->texture_character);
    sfTexture_destroy(ru->texture_ground);
    sfTexture_destroy(ru->texture_fond_second);
    sfTexture_destroy(ru->texture_fond);
    sfRenderWindow_destroy(ru->window);
    sfRenderWindow_close(ru->window);
}