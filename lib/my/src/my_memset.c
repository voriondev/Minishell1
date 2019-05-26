/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_memset
*/

void my_memset(char *str, char c, int len)
{
    for (int i = 0; i < len; i++)
        str[i] = c;
}
