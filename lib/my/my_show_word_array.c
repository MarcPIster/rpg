/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** Day08 Task03
*/

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);

int my_show_word_array(char * const *tab)
{
    int num_word = my_strlen(tab);
    int i = 0;

    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
