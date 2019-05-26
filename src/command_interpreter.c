/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** command_interpreter
*/

#include "minishell1.h"
#include "my.h"
#include <unistd.h>

int check_for_builtins(t_shell *shell, char **splitted_cmd)
{
    for (int i = 0; shell->builtins->builtins_cmd[i]; i++) {
        if (my_strcmp(splitted_cmd[0], shell->builtins->builtins_cmd[i]) == 0)
            return (shell->builtins->builtins_ptr[i](shell, splitted_cmd));
    }
    return (2);
}

int intepret_command(t_shell *shell, char **splitted_cmd)
{
    if (check_for_builtins(shell, splitted_cmd) == 0)
        return (0);
    else if (check_for_builtins(shell, splitted_cmd) == EXIT_SIGNAL)
        return (EOF_SIGNAL);
    else
        run_binary_file(shell, splitted_cmd);
    return (0);
}
