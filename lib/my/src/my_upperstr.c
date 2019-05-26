/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_upperstr
*/

#include <stdlib.h>
#include "my.h"

char *my_upperstr(char *str)
{
    char *up_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        up_str[i] = str[i];
        if (up_str[i] >= 'a' && up_str[i] <= 'z')
            up_str[i] -= 32;
    }
    up_str[i] = '\0';
    return (up_str);
}
