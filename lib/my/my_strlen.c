/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** Day04 Task03
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int length = 0;

    if (str == NULL)
        return 0;
    while (str[length] != '\0')
        length++;
    return length;
}
