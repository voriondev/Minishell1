/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** unsetenv
*/

#include "minishell1.h"
#include "my.h"
#include <stddef.h>
#include <stdlib.h>

int check_unset_syntax(char *var)
{
    if (my_str_isalpha(var) == 0) {
        return (-1);
    }
    return (0);
}

int remove_line_from_array(t_shell *shell, char *line)
{
    char **new_env;
    int line_index = 0;
    int arr_size = 0;
    int i = 0;
    int j = 0;

    for (line_index = 0; shell->env[line_index]; line_index++)
        if (!my_strcmp(shell->env[line_index], line))
            break;
    for (arr_size = 0; shell->env[arr_size]; arr_size++);
    new_env = malloc(sizeof(char *) * arr_size);
    if (new_env == NULL)
        return (-1);
    for (i = 0; i < line_index; i++)
        new_env[i] = my_strcpy(new_env[i], shell->env[i]);
    for (j = i + 1; j < arr_size; i++, j++)
        new_env[i] = my_strcpy(new_env[i], shell->env[j]);
    new_env[i] = NULL;
    free(shell->env);
    shell->env = new_env;
    return (0);
}

int remove_from_env(t_shell *shell, char *var)
{
    char *line = NULL;
    if (get_env_value(shell, var) == NULL)
        return (0);
    else
        line = my_strcat(my_strcat(var, "="), get_env_value(shell, var));
    if (line == NULL)
        return (0);
    else
        remove_line_from_array(shell, line);
    return (0);
}

int execute_unsetenv(t_shell *shell, char **args)
{
    if (args[1] == NULL)
        return (0);
    if (check_unset_syntax(args[1]) == -1)
        return (0);
    remove_from_env(shell, args[1]);
    return (0);
}
