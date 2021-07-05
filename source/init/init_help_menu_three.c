/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init hel
*/

#include "../../include/my_rpg.h"

text_t *how_quest(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./assets/font/font2.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, "Q - open/close questlog");
    sfText_setCharacterSize(text->text, 40);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f) {430, 505});
    return text;
}

text_t *description1(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./assets/font/font2.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, "Find and talk to the NPC's.");
    sfText_setCharacterSize(text->text, 40);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f) {380, 175});
    return text;
}

text_t *description2(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./assets/font/font2.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, "To beat the game complete the quest.");
    sfText_setCharacterSize(text->text, 40);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f) {300, 225});
    return text;
}

text_t *description3(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./assets/font/font2.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, \
    "To increase your chance of victory use your items.");
    sfText_setCharacterSize(text->text, 40);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f) {150, 275});
    return text;
}