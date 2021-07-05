/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Day03 Task07
*/

void my_putchar(char c);

int count_digits(int nb)
{
    int nb_digits = 0;

    while (nb != 0) {
        nb /= 10;
        nb_digits++;
    }
    return nb_digits;
}

int power(int nb, int power)
{
    int output = nb;

    if (power == 0) {
        return 1;
    }
    for (int i = 1; i < power; i++) {
        output *= nb;
    }
    return output;
}

int my_put_nbr(int nb)
{
    int nb_digits = count_digits(nb);
    int const_nb = nb;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb == 0) {
        my_putchar('0');
        return 0;
    }
    if (const_nb == -2147483648) {
        my_put_nbr(214748364);
        my_put_nbr(8);
        return 0;
    }
    for (int i = nb_digits - 1; i >= 0; i--) {
        my_putchar(nb / power(10, i) % 10 + '0');
    }
    return 0;
}
