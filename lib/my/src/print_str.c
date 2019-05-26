/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** print_str
*/

#include <stdarg.h>
#include "my.h"

int print_str(va_list list)
{
    my_putstr(va_arg(list, char *));
    return (0);
}