/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** check_signal
*/

#include "my.h"
#include <sys/wait.h>
#include <string.h>

void check_signal(int stat)
{
    if (WIFSIGNALED(stat) && WTERMSIG(stat) == SIGFPE)
        my_printf("Floating exception\n");
    if (WIFSIGNALED(stat) && WTERMSIG(stat) == SIGSEGV && WCOREDUMP(stat))
        my_printf("Segmentation fault (core dumped)\n");
    if (WIFSIGNALED(stat))
        my_printf("%s\n", strsignal(WTERMSIG(stat)));
}
