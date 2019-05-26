/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int my_printf(const char *format, ...)
{
    int i = 0;
    va_list list;
    int	(*funcs[9])(va_list list);

    add_ptr(funcs);
    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%' && (get_flag(format[i + 1]) != -1)) {
            funcs[get_flag(format[i + 1])](list);
            i++;
        }
        else
            my_putchar(format[i]);
        i++;
    }
    va_end(list);
    return (0);
}
