/*
** EPITECH PROJECT, 2021
** runtime_function.c
** File description:
** .
*/

#include "../../../include/my_rpg.h"

void room_draw(room *rm, game *gm, screen_t *screen)
{
    // Draw tiles
    draw_tiles(rm, gm, screen->window);
    draw_game(screen, screen->game);
    //sfRenderWindow_display(screen);
    

}

void room_handle_events(room *rm, game *gm)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(gm->render, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(gm->render);
    }
}

void room_update_anims(room *rm, game *gm)
{
    return;
}

void room_update_states(room *rm, game *gm)
{
    return;
}

void room_update_positions(room *rm, game *gm)
{
    return;
}