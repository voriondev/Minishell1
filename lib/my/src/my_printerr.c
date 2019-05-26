/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** my_printerr
*/

#include <unistd.h>
#include "my.h"

int my_printerr(char *str)
{
    int len = my_strlen(str);

    write(2, str, len);
    return (len);
}