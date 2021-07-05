/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** enter_combat
*/

#include "../../../include/my_rpg.h"

sfVector2f calculate_move_offset(sfVector2f dest, sfVector2f current_point)
{
    sfVector2f tmp = (sfVector2f) {dest.x - current_point.x,\
    dest.y - current_point.y};
    int x = 0;
    int y = 0;

    if (tmp.x < 0 || tmp.y < 0) {
        if (tmp.x < 0)
            x = 1;
        if (tmp.y < 0)
            y = 1;
    }
    tmp = (sfVector2f) {tmp.x / (tmp.x + tmp.y) * 0.50,\
    tmp.y / (tmp.y + tmp.x) * 0.50};
    if (x == 1 || y == 1) {
        if (x == 1)
            tmp.x *= -1;
        if (y == 1)
            tmp.y *= -1;
    }
    return tmp;
}

void intro_scene_helper(window_t *win, sfVector2f pos_p, sfVector2f pos_e)
{
    //sfRectangleShape_setTexture()
    sfRectangleShape_setTexture(win->player, win->player_text, sfTrue);
    sfRectangleShape_setPosition(win->player, pos_p);
    sfRectangleShape_setPosition(win->enemy, pos_e);
    sfRectangleShape_setSize(win->player, (sfVector2f) {200, 200});
    sfRectangleShape_setSize(win->enemy, (sfVector2f) {320, 240});
    sfRectangleShape_setFillColor(win->player, sfWhite);
    sfRectangleShape_setFillColor(win->enemy, sfWhite);
}

void intro_scene(window_t *win, sfTexture *monster)
{
    sfVector2f pos_p = (sfVector2f) {-450, -180};
    sfVector2f pos_e = (sfVector2f) {1000, 200};
    sfVector2f offset = (sfVector2f) {0, 0};

    sfRectangleShape_setTexture(win->enemy, monster, sfTrue);
    intro_scene_helper(win, pos_p, pos_e);
    while (1) {
        usleep(100);
        printf("%f, %f \n", pos_p.x, pos_p.y);
        sfRenderWindow_clear(win->window, sfBlack);
        offset = calculate_move_offset((sfVector2f) {50, 70}, pos_p);
        pos_p = (sfVector2f) {pos_p.x + offset.x, pos_p.y + offset.y};
        sfRectangleShape_setPosition(win->player, pos_p);
        offset = calculate_move_offset((sfVector2f) {480, 0}, pos_e);
        pos_e = (sfVector2f) {pos_e.x + offset.x, pos_e.y + offset.y};
        sfRectangleShape_setPosition(win->enemy, pos_e);
        sfRenderWindow_drawRectangleShape(win->window, win->player, NULL);
        sfRenderWindow_drawRectangleShape(win->window, win->enemy, NULL);
        sfRenderWindow_display(win->window);
        if (pos_e.x >= 479 && pos_e.y <= 1)
            break;
    }
}