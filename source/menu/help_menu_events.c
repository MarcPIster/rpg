/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** help events
*/

#include "../../include/my_rpg.h"

void detect_mouse_over_button_help(help_t *help, sfVector2f pos_mouse)
{
    if (help->button[0]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= help->button[0]->pos.x + 200 && \
        help->button[0]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= help->button[0]->pos.y + 50)
        sfRectangleShape_setFillColor(help->button[0]->rect, \
        (sfColor) {100, 100, 100, 255});
    else
        sfRectangleShape_setFillColor(help->button[0]->rect, sfWhite);
}

int button_is_clicked_help(help_t *help, sfVector2f pos_mouse)
{
    if (help->button[0]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= help->button[0]->pos.x + 200 && \
        help->button[0]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= help->button[0]->pos.y + 50)
        return 1;
    return 0;
}

void analyse_help_events(screen_t *screen, help_t *help, sfVector2f pos_mouse)
{
    int ret = 0;
    while (sfRenderWindow_pollEvent(screen->window, &help->event)) {
        if (help->event.type == sfEvtClosed) {
            sfRenderWindow_close(screen->window);
        }
        if (help->event.type == sfEvtMouseButtonPressed) {
            ret = button_is_clicked_help(help, pos_mouse);
        }
        if (ret == 1)
            screen->mode = 0;
    }
}