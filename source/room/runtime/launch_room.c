/*
** EPITECH PROJECT, 2021
** launch_room.c
** File description:
** .
*/

#include "../../../include/my_rpg.h"


int room_main_loop(room *rm, game *gm, screen_t *screen)
{

    //while(sfRenderWindow_isOpen(screen->window)) {
        sfRenderWindow_clear(screen->window, sfBlack);
        //room_handle_events(rm, gm);
        room_draw(rm, gm, screen);
        //sfRenderWindow_display(screen->window);
    //}
}

int launch_room(room *rm, game *gm, screen_t *screen)
{
    room_main_loop(rm, gm, screen);
}