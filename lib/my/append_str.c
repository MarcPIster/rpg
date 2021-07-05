/*
** EPITECH PROJECT, 2020
** append_str.c
** File description:
** .
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char **append_str(char **table, char *string)
{
    int length = 0;

    while (table[length] != NULL)
        length++;
    table[length] = malloc(sizeof(char) * (my_strlen(string) + 1));
    table[length] = my_strcpy(table[length], string);
    table[length + 1] = NULL;
    return table;
}