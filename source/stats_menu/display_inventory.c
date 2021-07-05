/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** display_inventory
*/

#include "../../include/my_rpg.h"

void display_use(int i, gameloop_t *game, screen_t *screen, sfVector2i pos_mouse)
{
    if (game->player1->inventory[i].equipable != 0)
        return;
    sfRectangleShape_setPosition(game->statmenu->usebutton, (sfVector2f) {1150, 312 + (i * 20)});
    sfText_setString(game->statmenu->buttontext, "use");
    sfText_setFont(game->statmenu->buttontext, game->statmenu->buttonfont);
    sfText_setCharacterSize(game->statmenu->buttontext, 16);
    sfText_setPosition(game->statmenu->buttontext, (sfVector2f) {1158, 311 + (i * 20)});
    sfText_setColor(game->statmenu->buttontext, sfGreen);
    detect_mouseover_use(i, game, screen, pos_mouse);
    sfRenderWindow_drawRectangleShape(screen->window, screen->game->statmenu->usebutton,
        NULL);
    sfRenderWindow_drawText(screen->window, game->statmenu->buttontext, NULL);
}

void display_equip(int i, gameloop_t *game, screen_t *screen, sfVector2i pos_mouse)
{
    if (game->player1->inventory[i].equipable != 1)
        return;
    sfRectangleShape_setPosition(game->statmenu->usebutton, (sfVector2f) {1150, 312 + (i * 20)});
    sfText_setString(game->statmenu->buttontext, "equip");
    sfText_setFont(game->statmenu->buttontext, game->statmenu->buttonfont);
    sfText_setCharacterSize(game->statmenu->buttontext, 16);
    sfText_setPosition(game->statmenu->buttontext, (sfVector2f) {1154, 311 + (i * 20)});
    sfText_setColor(game->statmenu->buttontext, sfGreen);
    if (game->player1->inventory[i].equiped == 1)
        sfText_setColor(game->statmenu->buttontext, sfYellow);
    detect_mouseover_equip(i, game, screen, pos_mouse);
    sfRenderWindow_drawRectangleShape(screen->window, screen->game->statmenu->usebutton,
        NULL);
    sfRenderWindow_drawText(screen->window, game->statmenu->buttontext, NULL);
}

void display_throw(int i, gameloop_t *game, screen_t *screen, sfVector2i pos_mouse)
{
    sfRectangleShape_setPosition(game->statmenu->usebutton, (sfVector2f) {1200,312 + (i * 20)});
    sfText_setString(game->statmenu->buttontext, "del");
    sfText_setFont(game->statmenu->buttontext, game->statmenu->buttonfont);
    sfText_setCharacterSize(game->statmenu->buttontext, 16);
    sfText_setPosition(game->statmenu->buttontext, (sfVector2f) {1209, 311 + (i * 20)});
    sfText_setColor(game->statmenu->buttontext, sfRed);
    detect_mouseover_throw(i, game, screen, pos_mouse);
    sfRenderWindow_drawRectangleShape(screen->window, screen->game->statmenu->usebutton,
        NULL);
    sfRenderWindow_drawText(screen->window, game->statmenu->buttontext, NULL);
}

void display_inventory_buttons(gameloop_t *game, screen_t *screen, sfVector2i pos_mouse)
{
    for (int i = 0; i < 8; i++) {
        if (game->player1->inventory[i].item_index != -1) {
            display_use(i, game, screen, pos_mouse);
            display_equip(i, game, screen, pos_mouse);
            display_throw(i, game, screen, pos_mouse);
        }
    }
}

void display_inventory(gameloop_t *game, screen_t *screen, sfVector2i pos_mouse)
{
    sfRenderWindow_drawText(screen->window, game->statmenu->inventory, NULL);
    sfText_setString(game->statmenu->item1, game->player1->inventory[0].item_name);
    sfRenderWindow_drawText(screen->window, game->statmenu->item1, NULL);
    sfText_setString(game->statmenu->item2, game->player1->inventory[1].item_name);
    sfRenderWindow_drawText(screen->window, game->statmenu->item2, NULL);
    sfText_setString(game->statmenu->item3, game->player1->inventory[2].item_name);
    sfRenderWindow_drawText(screen->window, game->statmenu->item3, NULL);
    sfText_setString(game->statmenu->item4, game->player1->inventory[3].item_name);
    sfRenderWindow_drawText(screen->window, game->statmenu->item4, NULL);
    sfText_setString(game->statmenu->item5, game->player1->inventory[4].item_name);
    sfRenderWindow_drawText(screen->window, game->statmenu->item5, NULL);
    sfText_setString(game->statmenu->item6, game->player1->inventory[5].item_name);
    sfRenderWindow_drawText(screen->window, game->statmenu->item6, NULL);
    sfText_setString(game->statmenu->item7, game->player1->inventory[6].item_name);
    sfRenderWindow_drawText(screen->window, game->statmenu->item7, NULL);
    sfText_setString(game->statmenu->item8, game->player1->inventory[7].item_name);
    sfRenderWindow_drawText(screen->window, game->statmenu->item8, NULL);
    display_inventory_buttons(game, screen, pos_mouse);
}