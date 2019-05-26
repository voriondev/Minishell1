/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_put_un_nbr_base
*/

#include "my.h"

int my_put_un_nbr_base(unsigned int nbr, char *base)
{
    int len = my_strlen(base);
    unsigned int index = nbr % len;
    nbr = nbr / len;

    if (nbr > 0)
        my_put_nbr_base(nbr, base);
    my_putchar(base[index]);
    return (0);
}