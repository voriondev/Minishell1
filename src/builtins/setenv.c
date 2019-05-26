/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** setenv
*/

#include "minishell1.h"
#include "my.h"
#include <stdlib.h>

int check_syntax(char *var)
{
    if (my_str_isalpha(var) == 0) {
        my_printf("setenv: ");
        my_printf("Variable name must contain alphanumeric characters.\n");
        return (-1);
    }
    return (0);
}

int add_var_to_env(t_shell *shell, char *var, char *value)
{
    char **new_env;
    int old_size = 0;
    int i = 0;

    if (value == NULL)
        value = "";
    for (old_size = 0; shell->env[old_size] != NULL; old_size++);
    new_env = malloc(sizeof(char *) * (old_size + 2));
    if (new_env == NULL)
        return (-1);
    for (i = 0; shell->env[i] != NULL; i++)
        new_env[i] = my_strcpy(new_env[i], shell->env[i]);
    new_env[i] = my_strcat(my_strcat(var, "="), value);
    new_env[i + 1] = NULL;
    shell->env = new_env;
    return (0);
}

int change_env_value(t_shell *shell, char *var, char *value)
{
    int line = 0;

    if (value == NULL)
        value = "";
    for (line = 0; shell->env[line] != NULL; line++) {
        if (my_strcontains(var, shell->env[line]) == 1)
            break;
    }
    shell->env[line] = my_strcat(my_strcat(var, "="), value);
    if (my_strcmp("PATH", var) == 0)
        parse_path_variable(shell);
    return (0);
}

int execute_setenv(t_shell *shell, char **args)
{
    char *value = get_env_value(shell, args[1]);

    if (args[1] == NULL) {
        for (int i = 0; shell->env[i] != NULL; i++)
            my_printf("%s\n", shell->env[i]);
        return (0);
    }
    if (check_syntax(args[1]) == -1)
        return (0);
    if (value == NULL)
        add_var_to_env(shell, args[1], args[2]);
    if (value != NULL)
        change_env_value(shell, args[1], args[2]);
    return (0);
}
