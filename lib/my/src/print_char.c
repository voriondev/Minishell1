/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** print_char
*/

#include <stdarg.h>
#include "my.h"

int print_char(va_list list)
{
    my_putchar(va_arg(list, int));
    return (0);
}