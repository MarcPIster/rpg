/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** use_inventory
*/

#include "../../include/my_rpg.h"

sfFloatRect getbuttonbounds(int throw, int i)
{
    sfFloatRect buttonbounds;

    buttonbounds.left = 1150;
    if (throw == 1)
        buttonbounds.left += 50;
    buttonbounds.top = 312 + (i * 20);
    buttonbounds.width = 40;
    buttonbounds.height = 20;
    return buttonbounds;
}

void detect_mouseover_use(int i, gameloop_t *game, screen_t *screen, sfVector2i pos_mouse)
{
    sfFloatRect buttonbounds = getbuttonbounds(0, i);

    float use_right = buttonbounds.left + buttonbounds.width;
    float use_bottom = buttonbounds.top + buttonbounds.height;
    float elapsed_time = sfTime_asMilliseconds(sfClock_getElapsedTime(game->clicktimer));
    if (game->player1->inventory[i].equipable != 0)
        return;
    if (pos_mouse.x > buttonbounds.left && pos_mouse.x < use_right &&
        pos_mouse.y > buttonbounds.top && pos_mouse.y < use_bottom) {
            sfRectangleShape_setScale(game->statmenu->usebutton, (sfVector2f) {1.1 , 1.1});
            sfText_setCharacterSize(game->statmenu->buttontext, 18);
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && elapsed_time > 100) {
                sfClock_restart(game->clicktimer);
                use_item(i, game->player1->inventory, game->player1, game);
                return;
            }
    }
    else {
        sfRectangleShape_setScale(game->statmenu->usebutton, (sfVector2f) {1 , 1});
        sfText_setCharacterSize(game->statmenu->buttontext, 16);
    }  
}

void detect_mouseover_equip(int i, gameloop_t *game, screen_t *screen, sfVector2i pos_mouse)
{
    sfFloatRect buttonbounds = getbuttonbounds(0, i);;

    float use_right = buttonbounds.left + buttonbounds.width;
    float use_bottom = buttonbounds.top + buttonbounds.height;
    float elapsed_time = sfTime_asMilliseconds(sfClock_getElapsedTime(game->clicktimer));
    if (game->player1->inventory[i].equipable != 1)
        return;
    if (pos_mouse.x > buttonbounds.left && pos_mouse.x < use_right &&
        pos_mouse.y > buttonbounds.top && pos_mouse.y < use_bottom) {
            sfRectangleShape_setScale(game->statmenu->usebutton, (sfVector2f) {1.1 , 1.1});
            sfText_setCharacterSize(game->statmenu->buttontext, 18);
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && elapsed_time > 100) {
                sfClock_restart(game->clicktimer);
                equip_item(i, game->player1->inventory, game->player1, game);
                return;
            }
    }
    else {
        sfRectangleShape_setScale(game->statmenu->usebutton, (sfVector2f) {1 , 1});
        sfText_setCharacterSize(game->statmenu->buttontext, 16);
    }   
}

void detect_mouseover_throw(int i, gameloop_t *game, screen_t *screen, sfVector2i pos_mouse)
{
    sfFloatRect buttonbounds = getbuttonbounds(1, i);;

    float use_right = buttonbounds.left + buttonbounds.width;
    float use_bottom = buttonbounds.top + buttonbounds.height;
    float elapsed_time = sfTime_asMilliseconds(sfClock_getElapsedTime(game->clicktimer));
    if (pos_mouse.x > buttonbounds.left && pos_mouse.x < use_right &&
        pos_mouse.y > buttonbounds.top && pos_mouse.y < use_bottom) {
            sfRectangleShape_setScale(game->statmenu->usebutton, (sfVector2f) {1.1 , 1.1});
            sfText_setCharacterSize(game->statmenu->buttontext, 18);
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && elapsed_time > 100) {
                sfClock_restart(game->clicktimer);
                throw_item(i, game->player1->inventory, game->player1, game);
                return;
            }
    }
    else {
        sfRectangleShape_setScale(game->statmenu->usebutton, (sfVector2f) {1 , 1});
        sfText_setCharacterSize(game->statmenu->buttontext, 16);
    }   
}