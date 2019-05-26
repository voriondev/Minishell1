/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_str_isempty
*/
#include "my.h"

int my_str_isempty(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] !=' ' && str[i] != '\t' && str[i] != '\r' && str[i] != '\n')
            return (0);
    }
    return (1);
}
