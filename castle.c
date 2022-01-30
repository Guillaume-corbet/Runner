/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** castle
*/

#include "my_runner.h"

void castle_create(runner_t *ru)
{
    ru->pos_castle.x = 1400;
    ru->pos_castle.y = 268;
    ru->sprite_castle = sfSprite_create();
    ru->texture_castle = sfTexture_createFromFile("castle_mrio.png", NULL);
    sfSprite_setTexture(ru->sprite_castle, ru->texture_castle, sfTrue);
    sfSprite_setPosition(ru->sprite_castle, ru->pos_castle);
}