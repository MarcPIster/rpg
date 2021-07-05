/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init pause
*/

#include "../../include/my_rpg.h"
#include "../../include/screen_structs.h"

button_t *continue_button(void)
{
    button_t *b = malloc(sizeof(button_t));

    b->font = sfFont_createFromFile("./assets/font/font2.ttf");
    b->rect = sfRectangleShape_create();
    b->text = sfText_create();
    sfText_setString(b->text, "Resume");
    sfText_setFont(b->text, b->font);
    sfText_setCharacterSize(b->text, 50);
    b->pos = (sfVector2f) {540, 220};
    sfRectangleShape_setSize(b->rect, (sfVector2f) {200, 50});
    sfRectangleShape_setPosition(b->rect, b->pos);
    sfText_setPosition(b->text, (sfVector2f) {550, 215});
    sfText_setColor(b->text, sfBlack);
    return b;
}

button_t *restart_button(void)
{
    button_t *b = malloc(sizeof(button_t));

    b->font = sfFont_createFromFile("./assets/font/font2.ttf");
    b->rect = sfRectangleShape_create();
    b->text = sfText_create();
    sfText_setString(b->text, "Restart");
    sfText_setFont(b->text, b->font);
    sfText_setCharacterSize(b->text, 50);
    b->pos = (sfVector2f) {540, 320};
    sfRectangleShape_setSize(b->rect, (sfVector2f) {200, 50});
    sfRectangleShape_setPosition(b->rect, b->pos);
    sfText_setPosition(b->text, (sfVector2f) {560, 315});
    sfText_setColor(b->text, sfBlack);
    return b;
}

button_t *option_button(void)
{
    button_t *b = malloc(sizeof(button_t));

    b->font = sfFont_createFromFile("./assets/font/font2.ttf");
    b->rect = sfRectangleShape_create();
    b->text = sfText_create();
    sfText_setString(b->text, "Settings");
    sfText_setFont(b->text, b->font);
    sfText_setCharacterSize(b->text, 50);
    b->pos = (sfVector2f) {540, 420};
    sfRectangleShape_setSize(b->rect, (sfVector2f) {200, 50});
    sfRectangleShape_setPosition(b->rect, b->pos);
    sfText_setPosition(b->text, (sfVector2f) {550, 415});
    sfText_setColor(b->text, sfBlack);
    return b;
}

button_t *main_menu_button(void)
{
    button_t *b = malloc(sizeof(button_t));

    b->font = sfFont_createFromFile("./assets/font/font2.ttf");
    b->rect = sfRectangleShape_create();
    b->text = sfText_create();
    sfText_setString(b->text, "Main");
    sfText_setFont(b->text, b->font);
    sfText_setCharacterSize(b->text, 50);
    b->pos = (sfVector2f) {540, 520};
    sfRectangleShape_setSize(b->rect, (sfVector2f) {200, 50});
    sfRectangleShape_setPosition(b->rect, b->pos);
    sfText_setPosition(b->text, (sfVector2f) {580, 515});
    sfText_setColor(b->text, sfBlack);
    return b;
}

button_t *quit_button(void)
{
    button_t *b = malloc(sizeof(button_t));

    b->font = sfFont_createFromFile("./assets/font/font2.ttf");
    b->rect = sfRectangleShape_create();
    b->text = sfText_create();
    sfText_setString(b->text, "Exit");
    sfText_setFont(b->text, b->font);
    sfText_setCharacterSize(b->text, 50);
    b->pos = (sfVector2f) {540, 620};
    sfRectangleShape_setSize(b->rect, (sfVector2f) {200, 50});
    sfRectangleShape_setPosition(b->rect, b->pos);
    sfText_setPosition(b->text, (sfVector2f) {590, 615});
    sfText_setColor(b->text, sfBlack);
    return b;
}