/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** events main_menu
*/

#include "../../include/my_rpg.h"

void detect_mouse_over_button_two(main_t *main, sfVector2f pos_mouse)
{
    if (main->button[2]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= main->button[2]->pos.x + 200 && \
        main->button[2]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= main->button[2]->pos.y + 50)
        sfRectangleShape_setFillColor(main->button[2]->rect, \
        (sfColor) {100, 100, 100, 255});
    else
        sfRectangleShape_setFillColor(main->button[2]->rect, sfWhite);
    if (main->button[3]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= main->button[3]->pos.x + 200 && \
        main->button[3]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= main->button[3]->pos.y + 50)
        sfRectangleShape_setFillColor(main->button[3]->rect, \
        (sfColor) {100, 100, 100, 255});
    else
        sfRectangleShape_setFillColor(main->button[3]->rect, sfWhite);
}

void detect_mouse_over_button(main_t *main, sfVector2f pos_mouse)
{
    if (main->button[0]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= main->button[0]->pos.x + 200 && \
        main->button[0]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= main->button[0]->pos.y + 50)
        sfRectangleShape_setFillColor(main->button[0]->rect, \
        (sfColor) {100, 100, 100, 255});
    else
        sfRectangleShape_setFillColor(main->button[0]->rect, sfWhite);
    if (main->button[1]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= main->button[1]->pos.x + 200 && \
        main->button[1]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= main->button[1]->pos.y + 50)
        sfRectangleShape_setFillColor(main->button[1]->rect, \
        (sfColor) {100, 100, 100, 255});
    else
        sfRectangleShape_setFillColor(main->button[1]->rect, sfWhite);
    detect_mouse_over_button_two(main, pos_mouse);
}

int button_is_clicked_two(main_t *main, sfVector2f pos_mouse)
{
    if (main->button[2]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= main->button[2]->pos.x + 200 && \
        main->button[2]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= main->button[2]->pos.y + 50) {
            return 3;
    }
    if (main->button[3]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= main->button[3]->pos.x + 200 && \
        main->button[3]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= main->button[3]->pos.y + 50) {
            return 4;
    }
    return 0;
}

int button_is_clicked(main_t *main, sfVector2f pos_mouse)
{
    if (main->button[0]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= main->button[0]->pos.x + 200 && \
        main->button[0]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= main->button[0]->pos.y + 50)
        return 1;
    if (main->button[1]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= main->button[1]->pos.x + 200 && \
        main->button[1]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= main->button[1]->pos.y + 50) {
        return 2;
    }
    return button_is_clicked_two(main, pos_mouse);
}

void analyse_events_main(screen_t *screen, main_t *main , sfVector2f pos_mouse)
{
    int ret = 0;
    while (sfRenderWindow_pollEvent(screen->window, &main->event)) {
        if (main->event.type == sfEvtClosed) {
            sfRenderWindow_close(screen->window);
        }
        if (main->event.type == sfEvtMouseButtonPressed) {
            ret = button_is_clicked(main, pos_mouse);
        }
        if (ret == 1)
            screen->mode = 1;
        if (ret == 2)
            screen->mode = 2;
        if (ret == 3)
            screen->mode = 3;
        if (ret == 4)
            screen->mode = 4;
    }
}