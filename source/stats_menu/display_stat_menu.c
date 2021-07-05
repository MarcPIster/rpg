/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** display_stat_menu
*/

#include "../../include/my_rpg.h"

void display_menu_stats1(gameloop_t *game, screen_t *screen)
{
    sfRenderWindow_drawText(screen->window, game->statmenu->level, NULL);
    sfText_setString(game->statmenu->curlvl, my_return_number(game->player1->level));
    sfRenderWindow_drawText(screen->window, game->statmenu->curlvl, NULL);
    sfRenderWindow_drawText(screen->window, game->statmenu->attack, NULL);
    sfText_setString(game->statmenu->curatk, my_return_number(game->player1->atk));
    sfRenderWindow_drawText(screen->window, game->statmenu->curatk, NULL);
    sfRenderWindow_drawText(screen->window, game->statmenu->defense, NULL);
    sfText_setString(game->statmenu->curdef, my_return_number(game->player1->def));
    sfRenderWindow_drawText(screen->window, game->statmenu->curdef, NULL);
    sfRenderWindow_drawText(screen->window, game->statmenu->speed, NULL);
    sfText_setString(game->statmenu->curspd, my_return_number(game->player1->speed));
    sfRenderWindow_drawText(screen->window, game->statmenu->curspd, NULL);
    sfRenderWindow_drawText(screen->window, game->statmenu->magic, NULL);
    sfText_setString(game->statmenu->curmag, my_return_number(game->player1->magic));
    sfRenderWindow_drawText(screen->window, game->statmenu->curmag, NULL);        
}

void display_menu_stats2(gameloop_t *game, screen_t *screen)
{
    sfRenderWindow_drawText(screen->window, game->statmenu->hpmax, NULL);
    sfText_setString(game->statmenu->curhpmax, my_return_number(game->player1->hpmax));
    sfRenderWindow_drawText(screen->window, game->statmenu->curhpmax, NULL);
    sfRenderWindow_drawText(screen->window, game->statmenu->hp, NULL);
    sfText_setString(game->statmenu->curhp, my_return_number(game->player1->hp));
    sfRenderWindow_drawText(screen->window, game->statmenu->curhp, NULL);
    sfRenderWindow_drawText(screen->window, game->statmenu->exp, NULL);
    sfText_setString(game->statmenu->curexp, my_return_number(game->player1->exp));
    sfRenderWindow_drawText(screen->window, game->statmenu->curexp, NULL);
}

void display_statmenu(gameloop_t *game, screen_t *screen, sfVector2i pos_mouse)
{
    sfRenderWindow_drawRectangleShape(screen->window, screen->game->statmenu->open_rect,
        NULL);
    display_menu_stats1(game, screen);
    display_menu_stats2(game, screen);
    sfRenderWindow_drawRectangleShape(screen->window, screen->game->statmenu->character,
        NULL);
    display_inventory(game, screen, pos_mouse);    
}