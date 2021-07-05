/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** pause buttons color shift
*/

#include "../../include/my_rpg.h"

void detect_mouse_over_button_pause_three(pause_t *pause, sfVector2f pos_mouse)
{
    if (pause->button[4]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= pause->button[4]->pos.x + 200 && \
        pause->button[4]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= pause->button[4]->pos.y + 50)
        sfRectangleShape_setFillColor(pause->button[4]->rect, \
        (sfColor) {100, 100, 100, 255});
    else
        sfRectangleShape_setFillColor(pause->button[4]->rect, sfWhite);
}

void detect_mouse_over_button_pause_two(pause_t *pause, sfVector2f pos_mouse)
{
    if (pause->button[2]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= pause->button[2]->pos.x + 200 && \
        pause->button[2]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= pause->button[2]->pos.y + 50)
        sfRectangleShape_setFillColor(pause->button[2]->rect, \
        (sfColor) {100, 100, 100, 255});
    else
        sfRectangleShape_setFillColor(pause->button[2]->rect, sfWhite);
    if (pause->button[3]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= pause->button[3]->pos.x + 200 && \
        pause->button[3]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= pause->button[3]->pos.y + 50)
        sfRectangleShape_setFillColor(pause->button[3]->rect, \
        (sfColor) {100, 100, 100, 255});
    else
        sfRectangleShape_setFillColor(pause->button[3]->rect, sfWhite);
    detect_mouse_over_button_pause_three(pause, pos_mouse);
}

void detect_mouse_over_button_pause(pause_t *pause, sfVector2f pos_mouse)
{
    if (pause->button[0]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= pause->button[0]->pos.x + 200 && \
        pause->button[0]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= pause->button[0]->pos.y + 50)
        sfRectangleShape_setFillColor(pause->button[0]->rect, \
        (sfColor) {100, 100, 100, 255});
    else
        sfRectangleShape_setFillColor(pause->button[0]->rect, sfWhite);
    if (pause->button[1]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= pause->button[1]->pos.x + 200 && \
        pause->button[1]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= pause->button[1]->pos.y + 50)
        sfRectangleShape_setFillColor(pause->button[1]->rect, \
        (sfColor) {100, 100, 100, 255});
    else
        sfRectangleShape_setFillColor(pause->button[1]->rect, sfWhite);
    detect_mouse_over_button_pause_two(pause, pos_mouse);
}