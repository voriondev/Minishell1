/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** print_m_hexa
*/

#include <stdarg.h>
#include "my.h"

int print_m_hexa(va_list list)
{
    unsigned int oct = va_arg(list, unsigned int);
    char *base = "0123456789ABCDEF";

    my_put_un_nbr_base(oct, base);
    return (0);
}