/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** my_put_nbr
*/

#include <unistd.h>

void my_putchar(char c);
void my_putstr(char *c);

void my_put_nbr(int nb)
{
    int i = 1;

    if (nb == -2147483648)
        my_putstr("-2147483648");
    else {
        if (nb < 0) {
            my_putchar('-');
            nb *= -1;
        }
        while ((nb / i) >= 10)
            i *= 10;
        while (i > 0) {
            my_putchar((nb / i) % 10 + '0');
            i /= 10;
        }
    }
}
