/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** enter_combat
*/

#include "../../../include/my_rpg.h"

void declare_text_helper(sfFont *font, sfText **text, int i)
{
    if (i == 2) {
        sfText_setString(text[i], "Magic");
        sfText_setPosition(text[i], (sfVector2f) {170, 537});
    } else if (i == 3) {
        sfText_setString(text[i], "Run away");
        sfText_setPosition(text[i], (sfVector2f) {560, 537});
    } else {
        sfText_setString(text[i], "vs");
        sfText_setPosition(text[i], (sfVector2f) {390, 185});
    }
}

void declare_text(sfFont *font, sfText **text)
{
    for (int i = 0; i < 5; i++) {
        text[i] = sfText_create();
        sfText_setCharacterSize(text[i], 20);
        sfText_setColor(text[i], sfWhite);
        if (i == 0) {
            sfText_setString(text[i], "Attack");
            sfText_setPosition(text[i], (sfVector2f) {160, 437});
        } else if (i == 1) {
            sfText_setString(text[i], "Defense");
            sfText_setPosition(text[i], (sfVector2f) {570, 437});
        } else {
            declare_text_helper(font, text, i);
        }
        sfText_setFont(text[i], font);
    }
}