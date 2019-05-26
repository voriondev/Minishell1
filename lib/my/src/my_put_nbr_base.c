/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_put_nbr_base
*/

#include "my.h"
#include <stdlib.h>

int my_put_nbr_base(int nbr, char *base)
{
    int base_len = my_strlen(base);

    if (nbr < 0) {
        nbr *= -1;
        my_putchar('-');
    }
    if (!nbr)
        return (0);
    else
        my_put_nbr_base(nbr / base_len, base);
    my_putchar(base[nbr % base_len]);
    return (0);
}