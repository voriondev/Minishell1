/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** exit
*/

#include "minishell1.h"
#include "my.h"
#include <stddef.h>

int execute_exit(t_shell *shell, char **args)
{
    if (args[1] != NULL && my_atoi(args[1]) != -1)
        shell->exit_status = my_atoi(args[1]);
    return (EXIT_SIGNAL);
}
