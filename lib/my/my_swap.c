/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** Day04 Task01
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
