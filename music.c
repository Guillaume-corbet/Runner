/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** music
*/

#include "my_runner.h"

void music_create(runner_t *ru)
{
    ru->music = sfMusic_createFromFile("Nyan_Cat.ogg");
    ru->music_ending = sfMusic_createFromFile("musique_ending.ogg");
    ru->music_lose = sfMusic_createFromFile("musique_lose.ogg");
    sfMusic_play(ru->music);
    sfMusic_setLoop(ru->music, sfTrue);
}