/*
** EPITECH PROJECT, 2020
** my_strncomp
** File description:
** Day06 Task07
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int s1_len = my_strlen(s1);
    int s2_len = my_strlen(s2);
    int max_len = s1_len;

    if (s2_len > s1_len)
        max_len = s2_len;
    if (n > max_len)
        n = max_len;
    for (int i = 0; i < n; i++) {
        if (s1[i] - s2[i] != 0)
            return s1[i] - s2[i];
    }
    return 0;
}
