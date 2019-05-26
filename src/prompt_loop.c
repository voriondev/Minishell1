/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** prompt_loop
*/

#include "minishell1.h"
#include "my.h"
#include <stdlib.h>

int prompt_loop(t_shell *shell)
{
    int exit_status = 0;
    while (1) {
        if (get_input(shell) == (EOF_SIGNAL)) {
            exit_status = shell->exit_status;
            free(shell->builtins);
            free(shell->env);
            free(shell->path);
            return (exit_status);
        }
    }
    free(shell->builtins);
    free(shell->env);
    free(shell->path);
    return (0);
}
