/*
** EPITECH PROJECT, 2018
** MY.H HEADER
** File description:
** HEADER FILE
*/

#include <stdarg.h>

#ifndef MY_H_
#define MY_H_

int my_strlen(char const *str);
int	my_getnbr(char *nb);
int my_printerr(char *str);
int my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_put_nbr_base(int nbr, char *base);
int my_put_un_nbr_base(unsigned int nbr, char *base);
int get_flag(char c);
void add_ptr(int (**funcs)(va_list list));
int my_printf(const char *format, ...);
int my_str_isnum(char const *str);
int print_char(va_list list);
int print_str(va_list list);
int print_int(va_list list);
int print_bin(va_list list);
int print_octal(va_list list);
int print_ptr(va_list list);
int print_hexa(va_list list);
int print_m_hexa(va_list list);
int print_mod(va_list list);
char **my_str_to_word_array(char const *str);
int my_strcmp(char *to_find, char *result);
char *my_strncpy(char *dest, char const *src, int n);
char *my_upperstr(char *str);
int	my_atoi(char *nb);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
void my_memset(char *str, char c, int len);
int my_strcontains(char *to_find, char *result);
int my_str_isempty(char *str);
char **my_split(char *str, char splitter);
int my_str_isalpha(char *str);

#endif
