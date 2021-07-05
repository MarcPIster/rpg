/*
** EPITECH PROJECT, 2021
** csv_parser.c
** File description:
** Prototypes in parsing.h
*/


#include "../../include/my_rpg.h"

void free_char_table(char **table)
{
    for (int i = 0; table[i]; i++)
        free(table[i]);
    free(table);
}

csv *parse_info(char *content)
{
    int comma_count = 0;
    int i;
    csv *output = malloc(sizeof(csv));
    char **content_lines = NULL;

    if (!content || !output)
        return NULL;
    for (i = 0; content[i] && content[i] != '\n'; i++)
        comma_count = (content[i] == ';') ? comma_count + 1 : comma_count;
    content_lines = my_str_to_word_array(content, '\n');
    for (i = 0; content_lines[i]; i++);
    output->n_rows = i - 1;
    output->n_columns = comma_count + 1;
    output->labels = my_str_to_word_array(content_lines[0], ';');
    free_char_table(content_lines);
    return output;
}

csv *parse_data(char *content, csv *output)
{
    char **content_lines = my_str_to_word_array(content, '\n');

    output->data = malloc(sizeof(char **) * (output->n_rows + 1));
    for (int i = 1; content_lines[i]; i++)
        output->data[i - 1] = my_str_to_word_array(content_lines[i], ',');
    output->data[output->n_rows] = NULL;
    free_char_table(content_lines);
    return output;
}

// Input : Filepath to file needing to be parsed
// Output : malloc'd pointer to structure containing malloc'd char *** + info
// MUST BE FREED : the returned pointer // the char *** // the char ** (labels)
csv *parse_csv(char *filepath)
{
    char *content = read_file(filepath);
    csv *output = parse_info(content);

    if (!output)
        return NULL;
    output = parse_data(content, output);
    return output;
}