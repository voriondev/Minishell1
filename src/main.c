/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** main
*/

#include "minishell1.h"
#include "my.h"
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
    t_shell *shell;

    if (ac != 1 || av[1] != NULL) {
        my_printerr("Usage: ./mysh\n");
        return (84);
    }
    shell = malloc(sizeof(t_shell));
    if (shell == NULL)
        return (84);
    return (my_shell(shell, env));
}
