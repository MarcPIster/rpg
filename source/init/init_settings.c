/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_setttings
*/

#include "../../include/my_rpg.h"

button_t *init_back_s(button_t *button)
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

button_t **init_button_set(button_t **button)
{
    button = malloc(sizeof(button_t *) * 2);
    button[0] = init_back_s(button[0]);
    button[1] = NULL;
    return button;
}

setting_t *init_vol_min(setting_t *setting)
{
    setting->minus = sfSprite_create();
    setting->vm = sfTexture_createFromFile(\
    "./assets/sprites/volume/volume_minus.png", NULL);
    sfSprite_setTexture(setting->minus, setting->vm, sfTrue);
    sfSprite_setScale(setting->minus, (sfVector2f) {0.1, 0.1});
    sfSprite_setPosition(setting->minus, (sfVector2f) {490, 300});
    setting->volm = sfRectangleShape_create();
    setting->posminus = (sfVector2f) {490, 300};
    sfRectangleShape_setFillColor(setting->volm, sfWhite);
    sfRectangleShape_setSize(setting->volm, (sfVector2f) {98, 77.6});
    sfRectangleShape_setPosition(setting->volm, setting->posminus);
    return setting;
}

setting_t *init_vol_max(setting_t *setting)
{
    setting->plus = sfSprite_create();
    setting->vp = sfTexture_createFromFile(\
    "./assets/sprites/volume/volume_plus.png", NULL);
    sfSprite_setTexture(setting->plus, setting->vp, sfTrue);
    sfSprite_setScale(setting->plus, (sfVector2f) {0.1, 0.1});
    sfSprite_setPosition(setting->plus, (sfVector2f) {692, 300});
    setting->volp = sfRectangleShape_create();
    setting->posplus = (sfVector2f) {692, 300};
    sfRectangleShape_setFillColor(setting->volp, sfWhite);
    sfRectangleShape_setSize(setting->volp, (sfVector2f) {98, 77.6});
    sfRectangleShape_setPosition(setting->volp, setting->posplus);
    return setting;
}

setting_t *init_setting(setting_t *setting)
{
    setting = malloc(sizeof(setting_t));
    setting->button = init_button_set(setting->button);
    setting->text = init_text_setting(setting->text);
    setting = init_vol_min(setting);
    setting = init_vol_max(setting);
    setting->prev_s = 0;
    return setting;
}