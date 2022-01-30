/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** fond
*/

#include "my_runner.h"

void fond_create(runner_t *ru)
{
    ru->move_ground.x = 0;
    ru->move_ground.y = 0;
    ru->move_fond_second.x = 0;
    ru->move_fond_second.y = 0;
    ru->move_fond.x = 0;
    ru->move_fond.y = 0;
    ru->texture_fond = sfTexture_createFromFile("cloud.png", NULL);
    ru->texture_fond_second = sfTexture_createFromFile("wood.png", NULL);
    ru->texture_ground = sfTexture_createFromFile("ground.png", NULL);
    ru->sprite_fond = sfSprite_create();
    ru->sprite_fond_second = sfSprite_create();
    ru->sprite_ground = sfSprite_create();
    sfSprite_setTexture(ru->sprite_fond, ru->texture_fond, sfTrue);
    sfSprite_setTexture(ru->sprite_fond_second,
    ru->texture_fond_second, sfTrue);
    sfSprite_setTexture(ru->sprite_ground, ru->texture_ground, sfTrue);
}

void fond_main(runner_t *ru)
{
    ru->move_ground.x = ru->move_ground.x - 25;
    if (ru->move_ground.x <= -1900)
        ru->move_ground.x = 0;
    ru->move_fond_second.x = ru->move_fond_second.x - 10;
    if (ru->move_fond_second.x <= -1900)
        ru->move_fond_second.x = 0;
    ru->move_fond.x = ru->move_fond.x - 1;
    if (ru->move_fond.x <= -1900)
        ru->move_fond.x = 0;
    sfSprite_setPosition(ru->sprite_fond, ru->move_fond);
    sfSprite_setPosition(ru->sprite_fond_second, ru->move_fond_second);
    sfSprite_setPosition(ru->sprite_ground, ru->move_ground);
    sfRenderWindow_drawSprite(ru->window, ru->sprite_fond, NULL);
    sfRenderWindow_drawSprite(ru->window, ru->sprite_fond_second, NULL);
    sfRenderWindow_drawSprite(ru->window, ru->sprite_ground, NULL);
}