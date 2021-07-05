/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** enter_combat
*/

#include "../../../include/my_rpg.h"

void declare_buttons_helper(fbutton_t *button)
{
    button->rect[4] = sfRectangleShape_create();
    button->pos[4] = (sfVector2f) {5, 5};
    sfRectangleShape_setPosition(button->rect[4], button->pos[4]);
    sfRectangleShape_setSize(button->rect[4], \
    (sfVector2f) {40.0, 40.0});
    sfRectangleShape_setFillColor(button->rect[4], sfRed);
    sfRectangleShape_setOutlineColor(button->rect[4], sfBlack);
    sfRectangleShape_setOutlineThickness(button->rect[4], 2.0);
    for (int i = 0; i < 4; i++) {
        sfRectangleShape_setPosition(button->rect[i], button->pos[i]);
        sfRectangleShape_setSize(button->rect[i], \
        (sfVector2f) {400.0, 100.0});
        sfRectangleShape_setFillColor(button->rect[i], sfRed);
        sfRectangleShape_setOutlineColor(button->rect[i], sfBlack);
        sfRectangleShape_setOutlineThickness(button->rect[i], 2.0);
    }
}

void declare_buttons(fbutton_t *button)
{
    button->pos = malloc(sizeof(sfVector2f *) * 5);
    button->rect = malloc(sizeof(sfRectangleShape *) * 5);

    for (int i = 0; i < 4; i++) {
        button->rect[i] = sfRectangleShape_create();
        if (!button->rect[i] || !button->pos)
            exit(84);
        if (i >= 2) {
            button->pos[i].x = 400;
            if (i == 2)
                button->pos[i].y = 400;
            else
                button->pos[i].y = 500;
        } else {
            button->pos[i].x = 0;
            if (i == 0)
                button->pos[i].y = 400;
            else
                button->pos[i].y = 500;
        }
    }
}