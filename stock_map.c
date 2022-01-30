/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** stock_map
*/

#include "my_runner.h"

char *get_next_line(int fd)
{
    BEGIN_GTL;
    if (a != -42) {
        free(buf);
    }
    buf = malloc(sizeof(char) * READ_SIZE);
    if (i == 0)
        ZERO_GTL;
    while (buffer[i] != '\n' && buffer[i] != '\0') {
        if (a == 0 || a == -1) {
            return (NULL);
        }
        UP_GTL;
        if (i == READ_SIZE) {
            UPGRADE_GTL;
        }
    }
    END_GTL;
    if (fd == 0)
        i = 0;
    return (buf);
}

void stock_map(runner_t *ru, char **argv)
{
    int fd = 0;

    fd = open(argv[1], O_RDONLY);
    ru->map = malloc(sizeof(char) * 100);
    ru->map = get_next_line(fd);
    close(fd);
}

void reading_map(runner_t *ru, rlist_spike *p_list_spike)
{
    if (ru->map[ru->n] == 'S') {
        p_list_spike = spike_create(ru, p_list_spike);
        sfClock_restart(ru->clock_map);
    }
    if (ru->map[ru->n] != '\0')
        sfClock_restart(ru->clock_map);
    else
        ru->n = ru->n - 1;
    ru->n = ru->n + 1;
    if (ru->seconds_map > 3) {
        ending(ru, p_list_spike);
    }
}
