/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** my_getnbr
*/

int	my_getnbr(char *nb)
{
    int	i = 0;
    int	res = 0;
    while (*nb) {
        if (*nb >= '0' && *nb <= '9') {
            res *= 10;
            res += *nb - '0';
        }
        else
            return (-1);
        nb++;
    }
    return (res);
}