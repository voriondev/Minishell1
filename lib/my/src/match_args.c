/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** match_args
*/

#include <stdarg.h>
#include "my.h"

int get_flag(char c)
{
    int pos = 0;
    char *flags = "%csidbopxX";

    while (*flags) {
        if (*flags == c)
            return (pos);
        pos++;
        flags++;
    }
    return (-1);
}

void add_ptr(int (**funcs)(va_list list))
{
    funcs[0] = &print_mod;
    funcs[1] = &print_char;
    funcs[2] = &print_str;
    funcs[3] = &print_int;
    funcs[4] = &print_int;
    funcs[5] = &print_bin;
    funcs[6] = &print_octal;
    funcs[7] = &print_ptr;
    funcs[8] = &print_hexa;
    funcs[9] = &print_m_hexa;
}
