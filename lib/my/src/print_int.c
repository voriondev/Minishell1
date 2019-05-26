/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** print_int
*/

#include <stdarg.h>
#include "my.h"

int print_int(va_list list)
{
    my_put_nbr(va_arg(list, int));
    return (0);
}