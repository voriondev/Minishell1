/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** print_hexa
*/

#include "my.h"
#include <stdarg.h>

int print_hexa(va_list list)
{
    unsigned int oct = va_arg(list, unsigned int);
    char *base = "0123456789abcdef";

    my_put_un_nbr_base(oct, base);
    return (0);
}