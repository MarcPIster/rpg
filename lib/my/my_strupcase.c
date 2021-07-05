/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** Day06 Task08
*/

int my_strlen(char const *str);

char *my_strupcase(char *str)
{
    int str_len = my_strlen(str);

    for (int i = 0; i < str_len; i++)
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    return str;
}
