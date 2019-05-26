/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** env
*/

#include "minishell1.h"
#include "my.h"
#include <stddef.h>

int execute_env(t_shell *shell, char **args)
{
    if (args[1] != NULL)
        return (0);
    for (int i = 0; shell->env[i] != NULL; i++)
        my_printf("%s\n", shell->env[i]);
    return (0);
}
