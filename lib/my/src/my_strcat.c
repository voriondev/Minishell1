/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_strcat
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int total_length = my_strlen(dest) + my_strlen(src) + 1;
    char *new_str = malloc(sizeof(char) * total_length);
    int i = 0;

    for (i = 0; dest[i] != '\0'; i++)
        new_str[i] = dest[i];
    for (int j = 0; src[j] != '\0'; j++, i++)
        new_str[i] = src[j];
    new_str[i] = '\0';
    return (new_str);
}
