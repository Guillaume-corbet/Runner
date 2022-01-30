/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** character
*/

#include "my_runner.h"

void character_create(runner_t *ru)
{
    ru->jump = 0;
    ru->up = 45;
    ru->rect_character.top = 0;
    ru->rect_character.left = 0;
    ru->rect_character.width = 108;
    ru->rect_character.height = 140;
    ru->move_character.x = 150;
    ru->move_character.y = 730;
    ru->sprite_character = sfSprite_create();
    ru->texture_character = sfTexture_createFromFile("character.png", NULL);
    sfSprite_setTexture(ru->sprite_character, ru->texture_character, sfTrue);
}

void hitbox_spike_lost(runner_t *ru, rlist_spike *p_list_spike)
{
    ru->loser = 1;
}

void hitbox_spike(runner_t *ru, rlist_spike *p_list_spike)
{
    int count = 0;
    void *point;

    point = p_list_spike->p_head;
    while (count != p_list_spike->length) {
        if (ru->move_character.x >= p_list_spike->p_head->move_spike.x - 70
        && ru->move_character.x <= p_list_spike->p_head->move_spike.x + 70
        && ru->move_character.y <= p_list_spike->p_head->move_spike.y + 50
        && ru->move_character.y >= p_list_spike->p_head->move_spike.y - 100) {
            hitbox_spike_lost(ru, p_list_spike);
        }
        p_list_spike->p_head = p_list_spike->p_head->p_next;
        count = count + 1;
    }
    p_list_spike->p_head = point;
}

rlist_spike *character_main(runner_t *ru, rlist_spike *p_list_spike)
{
    ru->rect_character.left = ru->rect_character.left + 108;
    if (ru->jump == 1)
        ru->rect_character.left = 216;
    if (ru->rect_character.left >= 864)
        ru->rect_character.left = 0;
    if (ru->jump == 1) {
        if (ru->up > -50) {
            ru->move_character.y = ru->move_character.y - ru->up;
            ru->up = ru->up - 10;
        }
    }
    if (ru->up <= -50) {
        ru->jump = 0;
        ru->up = 45;
    }
    hitbox_spike(ru, p_list_spike);
    sfSprite_setPosition(ru->sprite_character, ru->move_character);
    sfSprite_setTextureRect(ru->sprite_character, ru->rect_character);
    sfRenderWindow_drawSprite(ru->window, ru->sprite_character, NULL);
    return (p_list_spike);
}