/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main menu buttons
*/

#include "../../include/my_rpg.h"

button_t *init_play_b(button_t *button)
{
    button = malloc(sizeof(button_t));
    button->font = sfFont_createFromFile("./assets/font/font2.ttf");
    button->rect = sfRectangleShape_create();
    button->text = sfText_create();
    sfText_setString(button->text, "Play");
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, 50);
    button->pos = (sfVector2f) {540, 320};
    sfRectangleShape_setSize(button->rect, (sfVector2f) {200, 50});
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfText_setPosition(button->text, (sfVector2f) {590, 315});
    sfText_setColor(button->text, sfBlack);
    return button;
}

button_t *init_help_b(button_t *button)
{
    button = malloc(sizeof(button_t));
    button->font = sfFont_createFromFile("./assets/font/font2.ttf");
    button->rect = sfRectangleShape_create();
    button->text = sfText_create();
    sfText_setString(button->text, "Help");
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, 50);
    button->pos = (sfVector2f) {540, 420};
    sfRectangleShape_setSize(button->rect, (sfVector2f) {200, 50});
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfText_setPosition(button->text, (sfVector2f) {590, 415});
    sfText_setColor(button->text, sfBlack);
    return button;
}

button_t *init_settings_b(button_t *button)
{
    button = malloc(sizeof(button_t));
    button->font = sfFont_createFromFile("./assets/font/font2.ttf");
    button->rect = sfRectangleShape_create();
    button->text = sfText_create();
    sfText_setString(button->text, "Settings");
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, 50);
    button->pos = (sfVector2f) {540, 520};
    sfRectangleShape_setSize(button->rect, (sfVector2f) {200, 50});
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfText_setPosition(button->text, (sfVector2f) {550, 515});
    sfText_setColor(button->text, sfBlack);
    return button;
}

button_t *init_exit_b(button_t *button)
{
    button = malloc(sizeof(button_t));
    button->font = sfFont_createFromFile("./assets/font/font2.ttf");
    button->rect = sfRectangleShape_create();
    button->text = sfText_create();
    sfText_setString(button->text, "Exit");
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, 50);
    button->pos = (sfVector2f) {540, 620};
    sfRectangleShape_setSize(button->rect, (sfVector2f) {200, 50});
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfText_setPosition(button->text, (sfVector2f) {590, 615});
    sfText_setColor(button->text, sfBlack);
    return button;
}

button_t **init_main_buttons(button_t **button)
{
    button = malloc(sizeof(button_t *) * 5);
    button[0] = init_play_b(button[0]);
    button[1] = init_help_b(button[1]);
    button[2] = init_settings_b(button[2]);
    button[3] = init_exit_b(button[3]);
    button[4] = NULL;
    return button;
}