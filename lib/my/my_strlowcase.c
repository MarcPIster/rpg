/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** Day06 Task09
*/

int my_strlen(char const *str);

char *my_strlowcase(char *str)
{
    int str_len = my_strlen(str);

    for (int i = 0; i < str_len; i++)
        if (str[i] >= 65 && str[i] <= 97)
            str[i] += 32;
    return str;
}
