/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** Day06 Task05
*/

int my_strlen(char const *str);

int find_first_char(char *str, char const *to_find)
{
    int length = my_strlen(str);
    int to_find_length = my_strlen(to_find);
    int j;
    int k;
    int temp_length = 0;

    for (int i = 0; i < length; i++) {
        j = i;
        k = 0;
        while (str[j] == to_find[k]) {
            temp_length++;
            if (temp_length == to_find_length)
                return i;
            k++;
        }
        temp_length = 0;
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int first_char_pos = 0;

    first_char_pos = find_first_char(str, to_find);
    if (!my_strlen(to_find))
        return str;
    if (!first_char_pos)
        return 0;
    return &str[first_char_pos];
}
