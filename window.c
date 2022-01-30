/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** window
*/

#include "my_runner.h"

void window_create(runner_t *ru)
{
    ru->video_mode.width = 1900;
    ru->video_mode.height = 1050;
    ru->video_mode.bitsPerPixel = 32;
    ru->window = sfRenderWindow_create(ru->video_mode,
    "Runner", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(ru->window, 60);
}