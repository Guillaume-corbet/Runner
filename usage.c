/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** usage
*/

#include "my_runner.h"

int usage(runner_t *ru, int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        write(1, "USAGE\n", 6);
        write(1, "     ./my_runner map.txt\n\n", 26);
        write(1, "USER INTERACTIONS\n", 18);
        write(1, "     SPACE_KEY Jump\n", 20);
        write(1, "     ESCAPE_KEY Pause\n", 23);
        write(1, "     when lose or win ESCAPE to exit", 37);
        return (42);
    }
    if (argc == 1) {
        return (84);
    }
    return (0);
}