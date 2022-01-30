/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** text
*/

#include "my_runner.h"

void text_create_second(runner_t *ru)
{
    sfText_setFont(ru->score, ru->font);
    sfText_setFont(ru->score_number, ru->font);
    sfText_setFont(ru->pause, ru->font);
    sfText_setFont(ru->lose, ru->font);
    sfText_setFont(ru->win, ru->font);
    sfText_setCharacterSize(ru->score, 30);
    sfText_setCharacterSize(ru->score_number, 30);
    sfText_setCharacterSize(ru->pause, 60);
    sfText_setCharacterSize(ru->lose, 60);
    sfText_setCharacterSize(ru->win, 60);
    sfText_setPosition(ru->pause, ru->pos_pause);
    sfText_setPosition(ru->score, ru->pos_score);
    sfText_setPosition(ru->score_number, ru->pos_score_number);
    sfText_setPosition(ru->lose, ru->pos_pause);
    sfText_setPosition(ru->win, ru->pos_pause);
}

void text_create(runner_t *ru)
{
    ru->pos_score.x = 1650;
    ru->pos_score.y = 0;
    ru->pos_score_number.x = 1800;
    ru->pos_score_number.y = 0;
    ru->pos_pause.x = 800;
    ru->pos_pause.y = 450;
    ru->scores = 0;
    ru->score = sfText_create();
    ru->score_number = sfText_create();
    ru->pause = sfText_create();
    ru->lose = sfText_create();
    ru->win = sfText_create();
    text_create_second(ru);
}

void text_main(runner_t *ru)
{
    sfText_setString(ru->score_number, int_to_str(ru->scores));
    sfText_setString(ru->score, "score =");
    sfText_setString(ru->pause, "PAUSE");
    sfText_setString(ru->lose, "LOSER");
    sfText_setString(ru->win, "WINNER");
    sfRenderWindow_drawText(ru->window, ru->score, NULL);
    sfRenderWindow_drawText(ru->window, ru->score_number, NULL);
}