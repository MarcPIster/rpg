/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_help
*/

#include "../../include/my_rpg.h"

text_t *how_inventory(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./assets/font/font2.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, "I - open/close inventory");
    sfText_setCharacterSize(text->text, 40);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f) {425, 455});
    return text;
}

text_t *how_pause(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./assets/font/font2.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, "P - pause game");
    sfText_setCharacterSize(text->text, 40);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f) {470, 555});
    return text;
}

text_t **init_help_text(text_t **text)
{
    text = malloc(sizeof(text_t *) * 10);
    text[0] = init_help_head(text[0]);
    text[1] = control_header(text[1]);
    text[2] = control_body(text[2]);
    text[3] = how_inventory(text[3]);
    text[4] = how_pause(text[4]);
    text[5] = how_quest(text[5]);
    text[6] = description1(text[6]);
    text[7] = description2(text[7]);
    text[8] = description3(text[8]);
    text[9] = NULL;
    return text;
}

help_t *init_help(help_t *help)
{
    help = malloc(sizeof(help_t));
    help->button = init_help_buttons(help->button);
    help->text = init_help_text(help->text);
    return help;
}