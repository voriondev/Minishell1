/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** get_input
*/

#include "minishell1.h"
#include "my.h"
#include <stdio.h>
#include <unistd.h>

int get_input(t_shell *shell)
{
    char *input = NULL;
    char *dir = NULL;
    size_t dir_len = 0;
    size_t len;

    my_printf("%s@$> ", getcwd(dir, dir_len));
    if (getline(&input, &len, stdin) == -1)
        return (EOF_SIGNAL);
    while (input[0] == '\n' || my_str_isempty(input) == 1) {
        my_printf("%s@$> ", getcwd(dir, dir_len));
        if (getline(&input, &len, stdin) == -1)
            return (EOF_SIGNAL);
    }
    return (intepret_command(shell, my_split(input, ' ')));
}
