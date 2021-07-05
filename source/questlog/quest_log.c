/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** quest_log
*/

#include "../../include/my_rpg.h"

int clicked_questlog_icon(screen_t *screen, sfFloatRect menu_icon, gameloop_t *game, sfVector2i pos_mouse)
{    
    float menu_icon_right = menu_icon.left + menu_icon.width;
    float menu_icon_bottom = menu_icon.top + menu_icon.height;
    float elapsed_time = sfTime_asMilliseconds(sfClock_getElapsedTime(game->clicktimer));

    if (pos_mouse.x > menu_icon.left && pos_mouse.x < menu_icon_right &&
        pos_mouse.y > menu_icon.top && pos_mouse.y < menu_icon_bottom) {
            sfRectangleShape_setScale(game->questlog->icon_rect, (sfVector2f) {1.1 , 1.1});
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && elapsed_time > 100) {
                sfClock_restart(game->clicktimer);
                return 1;
            }
    }
    else 
        sfRectangleShape_setScale(game->questlog->icon_rect, (sfVector2f) {1 , 1});
    return 0;    
}

void open_quest_log(gameloop_t *game, sfVector2i pos_mouse, screen_t *screen)
{
    sfFloatRect iconbounds = sfRectangleShape_getGlobalBounds(game->questlog->icon_rect);
    if (game->quest_log_state == questlogclosed &&
        clicked_questlog_icon(screen, iconbounds, game, pos_mouse)) {
            game->quest_log_state = questlogopen;
    }
    if (game->quest_log_state == questlogopen &&
        clicked_questlog_icon(screen, iconbounds, game, pos_mouse)) {
            game->quest_log_state = questlogclosed;
    }
}

void quest_log(gameloop_t *game, screen_t *screen)
{
    sfVector2i pos_mouse = sfMouse_getPosition(screen->window);

    sfRenderWindow_drawRectangleShape(screen->window, screen->game->questlog->icon_rect,
        NULL);
    if (game->state != world)
        return;
    open_quest_log(game, pos_mouse, screen);
    if (game-> quest_log_state == questlogopen) {
        display_questlog(game, screen, pos_mouse);
    }
}