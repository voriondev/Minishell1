/*
** EPITECH PROJECT, 2018
** My STR N COPY
** File description:
** Copy n chars from a string from a mem loc to another,
*/

#include <unistd.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0') {
        if (i < n) {
            dest[i] = src[i];
        }
        i++;
    }
    if (n >= i)
        dest[i] = '\0';
    return (dest);
}
