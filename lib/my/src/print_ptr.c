/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** print_ptr
*/

#include <stdarg.h>
#include "my.h"

int print_ptr(va_list list)
{
    unsigned int adress = va_arg(list, unsigned int);
    char *base = "0123456789abcdef";

    my_putstr("0x7ffe");
    my_put_un_nbr_base(adress, base);
    return (0);
}