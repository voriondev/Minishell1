/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** print_octal
*/

#include <stdarg.h>
#include "my.h"

int print_octal(va_list list)
{
    unsigned int oct = va_arg(list, unsigned int);
    char *base = "01234567";

    my_put_un_nbr_base(oct, base);
    return (0);
}