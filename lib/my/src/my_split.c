/*
** EPITECH PROJECT, 2018
** MY STR TO WORD ARRAY
** File description:
** Print a string to an array
*/

#include <stdlib.h>
#include "my.h"

int is_split(char c, char split)
{
    return (c == split || c == '\0' || c == '\n' || c == '\t' ? 0 : 1);
}

int count_words(char *str, char split)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_split(str[i], split) == 1 && is_split(str[i+1], split) == 0)
            count++;
    }
    return (count);
}

char **my_split(char *str, char split)
{
    char **res = malloc((count_words(str, split) + 1) * sizeof(char *));
    int length = 0;
    int j = 0;

    if (res == NULL)
        return (NULL);
    for (int i = 0; str != NULL && str[i] != '\0'; i++) {
        if (is_split(str[i], split))
            length++;
        if (is_split(str[i], split) && is_split(str[i+1], split) == 0) {
            res[j] = malloc(length + 1);
            my_memset(res[j], '\0', length + 1);
            my_strncpy(res[j], &str[i - length + 1], length);
            length = 0;
            j++;
        }
    }
    res[j] = NULL;
    return (res);
}
