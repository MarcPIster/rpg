/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** Day06 Task06
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        if ((s1[i] - s2[i]) == 0)
            i++;
        else
            return (s1[i] - s2[i]);
    }
    return (s1[i] - s2[i]);
}