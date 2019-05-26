/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_str_isalpha
*/

#include "my.h"

int my_str_isalpha(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z') || str[i] == '_')
            i++;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            i++;
        else
            return (0);
    }
    return (1);
}
