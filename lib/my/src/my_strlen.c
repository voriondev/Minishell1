/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return (len);
}