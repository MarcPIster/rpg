/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** Day06 Task01
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; i < my_strlen(src); i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
