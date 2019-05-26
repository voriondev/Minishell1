/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** env_checker
*/

#include "minishell1.h"
#include "my.h"
#include <stddef.h>

int match_existing(char *var, char *env_var)
{
    int len = my_strlen(var);
    int prefix_len = 0;

    for (prefix_len = 0; env_var[prefix_len] != '='; prefix_len++);
    if (len != prefix_len)
        return (0);
    for (int i = 0; i < len; i++) {
        if (var[i] != env_var[i])
            return (0);
    }
    return (1);
}

char *get_env_value(t_shell *shell, char *var)
{
    char *value = NULL;

    if (var == NULL)
        return (value);
    for (int i = 0; shell->env[i] != NULL; i++)
        if (match_existing(var, shell->env[i]) == 1)
            value = shell->env[i] + my_strlen(var) + 1;
    return (value);
}
