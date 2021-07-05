/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_setttings
*/

#include "../../include/my_rpg.h"

text_t *setting_head(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./assets/font/font2.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, "Settings");
    sfText_setCharacterSize(text->text, 100);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f) {460, 50});
    return text;
}

text_t *text_vol(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./assets/font/font2.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, "volume");
    sfText_setCharacterSize(text->text, 50);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f) {560, 200});
    return text;
}

text_t **init_text_setting(text_t **text)
{
    text = malloc(sizeof(text_t *) * 3);
    text[0] = setting_head(text[0]);
    text[1] = text_vol(text[1]);
    text[2] = NULL;
    return text;
}