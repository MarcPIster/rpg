/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** Day05 Task04
*/

int my_compute_power_rec(int nb, int p)
{
    long long output = (long long)nb;

    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p > 0) {
        if (output < -2147483648 || output > 2147483647)
            return 0;
        output *= (long long)my_compute_power_rec(output, p - 1);
        return (int)output;
    }
}
