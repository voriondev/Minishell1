/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_strcpy
*/

#include "my.h"
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
