/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_atoi
*/

int	my_atoi(char *nb)
{
    int	res = 0;
    while (*nb) {
        if (*nb >= '0' && *nb <= '9') {
            res *= 10;
            res += *nb - '0';
        }
        else if (*nb == '\n' || *nb == '\0')
            break;
        else
            return (-1);
        nb++;
    }
    return (res);
}
