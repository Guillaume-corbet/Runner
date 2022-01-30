/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner
*/

#include "my_runner.h"

char *int_to_str(int nb)
{
    int a = 0;
    char *str;

    str = malloc(sizeof(char) * 11);
    while (nb > 0) {
        str[a] = (nb % 10) + 48;
        nb = nb / 10;
        a = a + 1;
    }
    str[a] = '\0';
    str = my_revstr(str);
    return (str);
}

void create_game(runner_t *ru)
{
    ru->scores = 0;
    ru->count_point = 0;
    ru->n = 0;
    ru->winner = 0;
    ru->loser = 0;
    ru->clock_game = sfClock_create();
    ru->clock_map = sfClock_create();
    ru->font = sfFont_createFromFile("arial.ttf");
    window_create(ru);
    music_create(ru);
    fond_create(ru);
    character_create(ru);
    text_create(ru);
}

int main_game(runner_t *ru, rlist_spike *p_list_spike)
{
    if (ru->seconds_game > 0.05) {
        fond_main(ru);
        character_main(ru, p_list_spike);
        p_list_spike = spike_main(ru, p_list_spike);
        text_main(ru);
        sfRenderWindow_display(ru->window);
        event_main(ru, p_list_spike);
        sfClock_restart(ru->clock_game);
    }
    if (ru->loser == 1) {
        ending_lost(ru);
        destroy(ru, p_list_spike);
        return (84);
    } else if (ru->winner == 1) {
        ending_win(ru);
        destroy(ru, p_list_spike);
        return (84);
    }
    return (0);
}

int loop(runner_t *ru, rlist_spike *p_list_spike)
{
    ru->time_game = sfClock_getElapsedTime(ru->clock_game);
    ru->time_map = sfClock_getElapsedTime(ru->clock_map);
    ru->seconds_game = ru->time_game.microseconds / 1000000.0;
    ru->seconds_map = ru->time_map.microseconds / 1000000.0;
    if (ru->seconds_map > 0.10)
        reading_map(ru, p_list_spike);
    if ((main_game(ru, p_list_spike)) == 84)
        return (84);
}

int main(int argc, char **argv)
{
    runner_t *ru;
    rlist_spike *p_list_spike = NULL;
    int a = 0;

    ru = malloc(sizeof(runner_t));
    a = usage(ru, argc, argv);
    if (a == 42)
        return (0);
    else if (a == 84)
        return (84);
    p_list_spike = dlist_new_spike();
    create_game(ru);
    stock_map(ru, argv);
    while (sfRenderWindow_isOpen(ru->window)) {
        if (loop(ru, p_list_spike) == 84)
            return (0);
    }
    return (0);
}
