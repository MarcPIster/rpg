/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** stats_menu
*/

#include "../../include/my_rpg.h"

int clicked_menu_icon(screen_t *screen, sfFloatRect menu_icon, gameloop_t *game, sfVector2i pos_mouse)
{    
    float menu_icon_right = menu_icon.left + menu_icon.width;
    float menu_icon_bottom = menu_icon.top + menu_icon.height;
    float elapsed_time = sfTime_asMilliseconds(sfClock_getElapsedTime(game->clicktimer));

    if (pos_mouse.x > menu_icon.left && pos_mouse.x < menu_icon_right &&
        pos_mouse.y > menu_icon.top && pos_mouse.y < menu_icon_bottom) {
            sfRectangleShape_setScale(game->statmenu->icon_rect, (sfVector2f) {1.1 , 1.1});
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && elapsed_time > 100) {
                sfClock_restart(game->clicktimer);
                return 1;
            }
    }
    else 
        sfRectangleShape_setScale(game->statmenu->icon_rect, (sfVector2f) {1 , 1});
    return 0;    
}

void open_stat_menu(gameloop_t *game, sfVector2i pos_mouse, screen_t *screen)
{
    sfFloatRect iconbounds = sfRectangleShape_getGlobalBounds(game->statmenu->icon_rect);
    if (game->menu_state == statmenuclosed &&
        clicked_menu_icon(screen, iconbounds, game, pos_mouse)) {
            game->menu_state = statmenuopen;
    }
    if (game->menu_state == statmenuopen &&
        clicked_menu_icon(screen, iconbounds, game, pos_mouse)) {
            game->menu_state = statmenuclosed;
    }
}

void stats_menu(gameloop_t *game, screen_t *screen)
{
    sfVector2i pos_mouse = sfMouse_getPosition(screen->window);

    sfRenderWindow_drawRectangleShape(screen->window, screen->game->statmenu->icon_rect,
        NULL);
    if (game->state != world)
        return;
    open_stat_menu(game, pos_mouse, screen);    
    if (game->menu_state == statmenuopen) {
        display_statmenu(game, screen, pos_mouse);
    }    
}