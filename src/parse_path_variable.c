/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** parse_path_variable
*/

#include "minishell1.h"
#include "my.h"
#include <stdlib.h>

int parse_path_variable(t_shell *shell)
{
    char *path = get_env_value(shell, "PATH");

    if (path == NULL) {
        shell->path = NULL;
        return (0);
    }
    shell->path = my_split(path, ':');
    return (0);
}
