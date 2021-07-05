/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** Day06 Task10
*/

int my_strlen(char const *str);
char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    int str_len = my_strlen(str);

    str = my_strlowcase(str);
    if (str[0] >= 97 && str[0] <= 122)
        str[0] -= 32;
    for (int i = 1; i < str_len; i++)
        if (str[i] >= 97 && str[i] <= 122)
            if (str[i - 1] == ' ' || str[i - 1] == '-' || str[i - 1] == '+')
                str[i] -= 32;
    return str;
}
