/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** Day08 Task04
*/

#include <stdlib.h>
#include <string.h>

void *malloc_w(size_t bytes)
{
    void *output = malloc(bytes);
    memset(output, 0, bytes);
    return output;
}

int count_words(char *str, char sep)
{
    int word_count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!in_word && str[i] != sep) {
            in_word = 1;
            word_count++;
        }
        if (str[i] == sep && in_word)
            in_word = 0;
    }
    return word_count;
}

int word_length(char *str, int index, char sep)
{
    int i;

    for (i = index; str[i] != '\0' && str[i] != sep; i++);
    return i - index;
}

char **my_str_to_word_array(char *str, char sep)
{
    char **output = malloc_w(sizeof(char *) * (count_words(str, sep) + 1));
    int in_word = 0;
    int j = -1;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!in_word && str[i] != sep) {
            in_word = 1;
            j++;
            k = 1;
            output[j] = malloc_w(sizeof(char) * (word_length(str, i, sep) +1));
            output[j][k - 1] = str[i];
        } else if (str[i] != sep) {
            output[j][k] = str[i];
            k++;
        }
        output[j][k] = (in_word && str[i] == sep) ? '\0' : output[j][k];
        in_word = (in_word && str[i] == sep) ? 0 : in_word;
    }
    output[count_words(str, sep)] = NULL;
    return output;
}