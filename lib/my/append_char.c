/*
** EPITECH PROJECT, 2020
** append_char.c
** File description:
** .
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

char *append_char(char *string, char c)
{
    int string_len = my_strlen(string);
    char *output = malloc(sizeof(char) * (string_len + 2));

    output = my_strcpy(output, string);
    output[string_len] = c;
    output[string_len + 1] = '\0';
    return output;
}