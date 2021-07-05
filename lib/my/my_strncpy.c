/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** Day06 Task02
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int str_len = my_strlen(src);

    if (n <= 0)
        return 0;
    if (n > str_len) {
        for (int i = 0; i < str_len; i++) {
            dest[i] = src[i];
        }
        dest[str_len] = '\0';
    } else {
        for (int i = 0; i < n; i++)
            dest[i] = src[i];
        dest[str_len] = '\0';
    }
    return dest;
}
