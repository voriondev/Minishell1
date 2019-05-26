/*
** EPITECH PROJECT, 2018
** My STR IS NUM
** File description:
** Check if a string is a number or not
*/

#include <unistd.h>

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}