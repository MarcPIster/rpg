/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Day04 Task02
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
