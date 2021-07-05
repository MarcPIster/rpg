/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-mydefender-mickael.riess
** File description:
** my_return_number
*/

/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** my_lib
*/

#include "../../include/my_rpg.h"

void my_putchar(char c);

int my_exp(int exp, int i)
{
    while (i > 9) {
        i = i / 10;
        exp = exp * 10;
    }
    return (exp);
}

int do_minus(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    return (nb);
};

char *my_return_number(int nb)
{
    int pos = 0;
    int j = 0;
    int i = nb;
    int exp = 1;
    char *string = malloc(sizeof(char) * 40);
    nb = do_minus(nb);
    i = nb;
    exp = my_exp(exp, i);
    while (exp > 0) {
        if (exp == 1 && j == 1) {
            string[pos] = nb / exp % 10 + '1';
            pos++;
            exp = exp / 10;
        } else {
            string[pos] = nb / exp % 10 + '0';
            pos++;
            exp = exp / 10;
        }
    }
    string[pos] = '\0';
    return string;
}