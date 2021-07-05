/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** settings events
*/


#include "../../include/my_rpg.h"

void detect_mouse_over_vol(setting_t *setting, sfVector2f pos_mouse)
{
    if (setting->posplus.x <= pos_mouse.x && \
    pos_mouse.x <= setting->posplus.x + 98 && \
    setting->posplus.y <= pos_mouse.y && \
    pos_mouse.y <= setting->posplus.y + 77.6)
        sfRectangleShape_setFillColor(setting->volp, \
        (sfColor) {100, 100, 100, 255});
    else
        sfRectangleShape_setFillColor(setting->volp, sfWhite);
    if (setting->posminus.x <= pos_mouse.x && \
    pos_mouse.x <= setting->posminus.x + 98 && \
    setting->posminus.y <= pos_mouse.y && \
    pos_mouse.y <= setting->posminus.y + 77.6)
        sfRectangleShape_setFillColor(setting->volm, \
        (sfColor) {100, 100, 100, 255});
    else
        sfRectangleShape_setFillColor(setting->volm, sfWhite);
}

void detect_mouse_over_button_setting(setting_t *setting, sfVector2f pos_mouse)
{
    if (setting->button[0]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= setting->button[0]->pos.x + 200 && \
        setting->button[0]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= setting->button[0]->pos.y + 50)
        sfRectangleShape_setFillColor(setting->button[0]->rect, \
        (sfColor) {100, 100, 100, 255});
    else
        sfRectangleShape_setFillColor(setting->button[0]->rect, sfWhite);
    detect_mouse_over_vol(setting, pos_mouse);
}

int button_is_clicked_setting(setting_t *setting, sfVector2f pos_mouse)
{
    if (setting->button[0]->pos.x <= pos_mouse.x && \
        pos_mouse.x <= setting->button[0]->pos.x + 200 && \
        setting->button[0]->pos.y <= pos_mouse.y && \
        pos_mouse.y <= setting->button[0]->pos.y + 50)
        return 1;
    return 0;
}

void change_vol(screen_t *s, sfVector2f pos_mouse)
{
    if (s->setting->posplus.x <= pos_mouse.x && \
    pos_mouse.x <= s->setting->posplus.x + 98 && \
    s->setting->posplus.y <= pos_mouse.y && \
    pos_mouse.y <= s->setting->posplus.y + 77.6)
        if (s->volume < 100) {
            s->volume += 5;
            sfMusic_setVolume(s->soundtrack, s->volume);
            sfMusic_setVolume(s->death, s->volume);
        }
    if (s->setting->posminus.x <= pos_mouse.x && \
    pos_mouse.x <= s->setting->posminus.x + 98 && \
    s->setting->posminus.y <= pos_mouse.y && \
    pos_mouse.y <= s->setting->posminus.y + 77.6)
        if (s->volume > 0) {
            s->volume -= 5;
            sfMusic_setVolume(s->soundtrack, s->volume);
            sfMusic_setVolume(s->death, s->volume);
        }
}

void analyse_setting_events(screen_t *screen, setting_t *setting, \
sfVector2f pos_mouse)
{
    int ret = 0;
    while (sfRenderWindow_pollEvent(screen->window, &setting->event)) {
        if (setting->event.type == sfEvtClosed) {
            sfRenderWindow_close(screen->window);
        }
        if (setting->event.type == sfEvtMouseButtonPressed) {
            change_vol(screen, pos_mouse);
            ret = button_is_clicked_setting(setting, pos_mouse);
        }
        if (ret == 1)
            screen->mode = setting->prev_s;
    }
}