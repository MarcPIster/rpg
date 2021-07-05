/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** enter_combat
*/

#include "../../../include/my_rpg.h"

void change_state_button_left(fbutton_t *button, window_t *win,\
player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    if (win->pos.x >= 0 && win->pos.x < 400) {
        attack_button(button, win, player_stats, monster_stats);
    } else if (win->pos.x >= 400 && win->pos.x < 800) {
        defense_button(button, win, player_stats, monster_stats);
    }
}

void change_state_button_right(fbutton_t *button, window_t *win,\
player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    if (win->pos.x >= 0 && win->pos.x < 400) {
        magic_button(button, win, player_stats, monster_stats);
    } else if (win->pos.x >= 400 && win->pos.x < 800) {
        run_away_button(button, win, player_stats, monster_stats);
    }
}

void change_state_button(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    int check = 1;

    win->pos = sfMouse_getPosition((const sfWindow *) win->window);
    for (int i = 0; i < 5; i++)
        sfRectangleShape_setFillColor(button->rect[i], sfRed);
    if (win->pos.y >= 400 && win->pos.y < 500 && win->info_check != 1) {
        change_state_button_left(button, win, player_stats, monster_stats);
    } else if (win->pos.y >= 500 && win->pos.y < 600 && win->info_check != 1) {
        change_state_button_right(button, win, player_stats, monster_stats);
    } else {
        if (win->pos.y >= 5 && win->pos.y <= 45 && win->pos.x >= 5 && win->pos.x <= 45) {
            win->info = detect_info(button, win, player_stats, monster_stats);
        }
    }
}