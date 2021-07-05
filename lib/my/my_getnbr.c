/*
** EPITECH PROJECT, 2020
** emacs
** File description:
** task05
*/

int my_getnbr(char const *str)
{
    long int res = 0;
    int i = 0;
    int min = 0;

    while (str[i] == '-') {
        min++;
        i++;
    }
    while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10;
        res = res + (str[i]) - '0';
        i++;
    }
    if (min %2 != 0)
        res = res * (-1);
    if (res > 2147483647 || res < -2147483648)
        return 0;
    else
        return res;
}