/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** enter_combat
*/

#include "../../../include/my_rpg.h"

int display_objects_helper(window_t *win, monster_stats_t *monster,
    int check, int change)
{
    if (check >= 20 && check < 50) {
        sfSprite_setPosition(win->sprite[monster->decision], \
        (sfVector2f) {430.0, 178.32});
        sfRenderWindow_drawSprite(win->window, \
        win->sprite[monster->decision], NULL);
    } else if (check >= 50) {
        check = 0;
        return 1;
    } else {
        sfSprite_setPosition(win->sprite[change], \
        (sfVector2f) {430.0, 178.32});
        sfRenderWindow_drawSprite(win->window ,win->sprite[change], NULL);
    }
    return 0;
}

void display_obejct_draw_rect(fbutton_t *button, window_t *win,
    player_stats_t *player, monster_stats_t *monster)
{
    sfSprite_setPosition(win->sprite[player->decision], \
    (sfVector2f) {330.0, 178.32});
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawRectangleShape(win->window, button->rect[i], NULL);
    sfRenderWindow_drawRectangleShape(win->window, win->player, NULL);
    sfRenderWindow_drawRectangleShape(win->window, win->enemy, NULL);
    for (int i = 0; i < 5; i++) {
        sfRenderWindow_drawText(win->window, win->text[i], NULL);
    }
    sfRenderWindow_display(win->window);
}

int display_objects_result(fbutton_t *button, window_t *win,
    player_stats_t *player, monster_stats_t *monster)
{
    static int change = 0;
    static int check = 0;

    sfRenderWindow_drawRectangleShape(win->window, win->background, NULL);
    sfRenderWindow_drawSprite(win->window, \
    win->sprite[player->decision], NULL);
    if (display_objects_helper(win, monster, check, change) == 1)
        return 1;
    display_hp_bars2(player, monster, win);
    display_obejct_draw_rect(button, win, player, monster);
    if (win->time >= 0.1) {
        sfClock_restart(win->clock);
        win->time = 0;
        change += 1;
        check += 1;
    }
    if (change == 3)
        change = 0;
    return 0;
}

void fight_result(fbutton_t *buttons, window_t *win,
    player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    while (sfRenderWindow_isOpen(win->window)) {
        win->time = sfTime_asSeconds(sfClock_getElapsedTime(win->clock));
        eventhandler_helper(win, buttons, player_stats, monster_stats);
        sfRenderWindow_clear(win->window, sfBlack);
        if (display_objects_result(buttons, win, \
        player_stats, monster_stats) == 1)
            break;
    }
}