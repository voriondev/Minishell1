/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** print_bin
*/

#include <stdarg.h>
#include "my.h"

int print_bin(va_list list)
{
    unsigned int bin = va_arg(list, unsigned int);
    char *base = "01";

    my_put_un_nbr_base(bin, base);
    return (0);
}