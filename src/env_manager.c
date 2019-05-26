/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_setpath
*/

#include "minishell1.h"
#include <stdlib.h>

int setup_builtins(t_shell *shell)
{
    shell->builtins = malloc(sizeof(t_builtins));

    if (shell->builtins == NULL)
        return (-1);
    shell->builtins->builtins_cmd[0] = "cd";
    shell->builtins->builtins_ptr[0] = &execute_cd;
    shell->builtins->builtins_cmd[1] = "env";
    shell->builtins->builtins_ptr[1] = &execute_env;
    shell->builtins->builtins_cmd[2] = "exit";
    shell->builtins->builtins_ptr[2] = &execute_exit;
    shell->builtins->builtins_cmd[3] = "setenv";
    shell->builtins->builtins_ptr[3] = &execute_setenv;
    shell->builtins->builtins_cmd[4] = "unsetenv";
    shell->builtins->builtins_ptr[4] = &execute_unsetenv;
    shell->builtins->builtins_cmd[5] = NULL;
    shell->builtins->builtins_ptr[5] = NULL;
    return (0);
}

int define_custom_env(t_shell *shell)
{
    if (setup_builtins(shell) == -1)
        return (-1);
    return (0);
}
