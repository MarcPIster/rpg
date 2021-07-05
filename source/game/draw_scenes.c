/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** draw_scenes
*/


#include "../../include/my_rpg.h"

void draw_main(screen_t *screen, main_t *main, sfVector2f pos_mouse)
{
    analyse_events_main(screen, main, pos_mouse);
    sfRenderWindow_drawSprite(screen->window, screen->background, NULL);
    sfRenderWindow_drawText(screen->window, main->text[0]->text, NULL);
    sfRenderWindow_drawRectangleShape(screen->window, main->button[0]->rect, \
    NULL);
    sfRenderWindow_drawRectangleShape(screen->window, main->button[1]->rect, \
    NULL);
    sfRenderWindow_drawRectangleShape(screen->window, main->button[2]->rect, \
    NULL);
    sfRenderWindow_drawRectangleShape(screen->window, main->button[3]->rect, \
    NULL);
    detect_mouse_over_button(main, pos_mouse);
    sfRenderWindow_drawText(screen->window, main->button[0]->text, NULL);
    sfRenderWindow_drawText(screen->window, main->button[1]->text, NULL);
    sfRenderWindow_drawText(screen->window, main->button[2]->text, NULL);
    sfRenderWindow_drawText(screen->window, main->button[3]->text, NULL);
}

void draw_help(screen_t *screen, help_t *help, sfVector2f pos_mouse)
{
    analyse_help_events(screen, help, pos_mouse);
    sfRenderWindow_drawSprite(screen->window, screen->background, NULL);
    for (int i = 0; help->text[i] != NULL; i++) {
        sfRenderWindow_drawText(screen->window, help->text[i]->text, NULL);
    }
    sfRenderWindow_drawRectangleShape(screen->window, help->button[0]->rect, \
    NULL);
    detect_mouse_over_button_help(help, pos_mouse);
    sfRenderWindow_drawText(screen->window, help->button[0]->text, NULL);
}

void draw_settings(screen_t *screen, setting_t *setting, sfVector2f pos_mouse)
{
    analyse_setting_events(screen, setting, pos_mouse);
    sfRenderWindow_drawSprite(screen->window, screen->background, NULL);
    for (int i = 0; setting->text[i] != NULL; i++)
        sfRenderWindow_drawText(screen->window, setting->text[i]->text, NULL);
    sfRenderWindow_drawRectangleShape(screen->window, setting->button[0]->rect,\
    NULL);
    sfRenderWindow_drawRectangleShape(screen->window, setting->volm, NULL);
    sfRenderWindow_drawRectangleShape(screen->window, setting->volp, NULL);
    detect_mouse_over_button_setting(setting, pos_mouse);
    sfRenderWindow_drawText(screen->window, setting->button[0]->text, NULL);
    sfRenderWindow_drawSprite(screen->window, setting->minus, NULL);
    sfRenderWindow_drawSprite(screen->window, setting->plus, NULL);
}

void draw_game(screen_t *screen, gameloop_t *game)
{
    gameloop_events(screen, game);
    mob_aggro(game, screen);
    npc_aggro(game, screen);
    update_animations(screen, game);
    enter_combat(game, screen);
    interact_with_npc(game, screen);
    stats_menu(game, screen);
    quest_log(game, screen);
    quests_check(game, screen);
    check_door(screen, game);
}

void draw_pause(screen_t *screen, pause_t *pause, sfVector2f pos_mouse)
{
    analyse_events_pause(screen, screen->pause, pos_mouse);
    sfRenderWindow_drawSprite(screen->window, pause->sprite, NULL);
    sfRenderWindow_drawText(screen->window, pause->text[0]->text, NULL);
    sfRenderWindow_drawRectangleShape(screen->window, pause->button[0]->rect, \
    NULL);
    sfRenderWindow_drawRectangleShape(screen->window, pause->button[1]->rect, \
    NULL);
    sfRenderWindow_drawRectangleShape(screen->window, pause->button[2]->rect, \
    NULL);
    sfRenderWindow_drawRectangleShape(screen->window, pause->button[3]->rect, \
    NULL);
    sfRenderWindow_drawRectangleShape(screen->window, pause->button[4]->rect, \
    NULL);
    detect_mouse_over_button_pause(screen->pause, pos_mouse);
    sfRenderWindow_drawText(screen->window, pause->button[0]->text, NULL);
    sfRenderWindow_drawText(screen->window, pause->button[1]->text, NULL);
    sfRenderWindow_drawText(screen->window, pause->button[2]->text, NULL);
    sfRenderWindow_drawText(screen->window, pause->button[3]->text, NULL);
    sfRenderWindow_drawText(screen->window, pause->button[4]->text, NULL);
}