/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** firework
*/

#include "my_runner.h"

void firework_create(runner_t *ru)
{
    ru->rect_firework.top = 50;
    ru->rect_firework.left = 0;
    ru->rect_firework.width = 50;
    ru->rect_firework.height = 50;
    ru->mult.x = 20;
    ru->mult.y = 20;
    ru->pos_firework.x = 1200;
    ru->pos_firework.y = 200;
    ru->sprite_firework = sfSprite_create();
    ru->texture_firework = sfTexture_createFromFile("explosion.png", NULL);
    sfSprite_setTexture(ru->sprite_firework, ru->texture_firework, sfTrue);
    sfSprite_setPosition(ru->sprite_firework, ru->pos_firework);
    sfSprite_setScale(ru->sprite_firework, ru->mult);
}