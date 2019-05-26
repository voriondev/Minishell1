/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** copy_env
*/

#include "minishell1.h"
#include "my.h"
#include <stdlib.h>

int copy_env(t_shell *shell, char **env)
{
    int var_count = 0;
    int j = 0;
    for (int i = 0; env[i] != NULL; i++)
        var_count++;
    shell->env = malloc(sizeof(char *) * (var_count + 1));
    if (shell->env == NULL) {
        my_printerr("An error occured while copying user environment.\n");
        return (-1);
    }
    for (j = 0; env[j] != NULL; j++)
        shell->env[j] = my_strcpy(shell->env[j], env[j]);
    shell->env[j] = NULL;
    return (0);
}
