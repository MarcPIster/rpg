/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init help two
*/

#include "../../include/my_rpg.h"

button_t *init_back_h(button_t *button)
{
    button = malloc(sizeof(button_t));
    button->font = sfFont_createFromFile("./assets/font/font2.ttf");
    button->rect = sfRectangleShape_create();
    button->text = sfText_create();
    sfText_setString(button->text, "Back");
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, 50);
    button->pos = (sfVector2f) {540, 620};
    sfRectangleShape_setSize(button->rect, (sfVector2f) {200, 50});
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfText_setPosition(button->text, (sfVector2f) {580, 615});
    sfText_setColor(button->text, sfBlack);
    return button;
}

button_t **init_help_buttons(button_t **button)
{
    button = malloc(sizeof(button_t *) * 2);
    button[0] = init_back_h(button[0]);
    button[1] = NULL;
    return button;
}

text_t *init_help_head(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./assets/font/font2.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, "How To Play");
    sfText_setCharacterSize(text->text, 100);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f) {340, 50});
    return text;
}

text_t *control_header(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./assets/font/font2.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, "Controls");
    sfText_setCharacterSize(text->text, 45);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f) {550, 355});
    return text;
}

text_t *control_body(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./assets/font/font2.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, "W, A, S, D - movement");
    sfText_setCharacterSize(text->text, 40);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f) {430, 405});
    return text;
}