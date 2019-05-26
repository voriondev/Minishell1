/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_shell
*/

#include "minishell1.h"
#include "my.h"

int my_shell(t_shell *shell, char **env)
{
    shell->exit_status = 0;
    if (define_custom_env(shell) == -1) {
        my_printerr("An error occured while setting up custom environment.\n");
        return (84);
    }
    if (copy_env(shell, env) == -1)
        return (84);
    if (parse_path_variable(shell) == -1)
        return (84);
    return (prompt_loop(shell));
}
