/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** Day05 Task07
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i = nb;

    if (i <= 1)
        return 2;
    while (!my_is_prime(i))
        i++;
    return i;
}
