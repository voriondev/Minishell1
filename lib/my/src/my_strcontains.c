/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_strcontains
*/

int my_strcontains(char *to_find, char *result)
{
    int i = 0;
    int matching = 1;

    while (to_find[i] && result[i]) {
        if (to_find[i] != result[i]) {
            matching = 0;
            break;
        }
        i++;
    }
    return (matching);
}
