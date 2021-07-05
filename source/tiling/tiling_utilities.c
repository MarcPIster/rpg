/*
** EPITECH PROJECT, 2021
** tiling_utilities.c
** File description:
** .
*/


#include "../../include/my_rpg.h"


sfVector2i get_area_dimensions(int **area)
{
    sfVector2i output;

    output.x = 0;
    output.y = 0;
    for (; area[output.y]; output.y++);
    for (; area[0][output.x]; output.x++);
    return output;
}

sfVector2f get_window_center(sfRenderWindow *render)
{
    sfVector2u window_size = sfRenderWindow_getSize(render);
    sfVector2f output;

    output.x = window_size.x / 2;
    output.y = window_size.y / 2;
    return output;
}

sfVector2f get_start_pos(room *rm, game *gm, sfRenderWindow  *screen)
{
    int tile_size = sfTexture_getSize(gm->tileset[0]).x;
    sfVector2f center = get_window_center(screen);
    sfVector2i dimensions = get_area_dimensions(rm->tiling);
    sfVector2f output;

    output.x = center.x - ((dimensions.x / 2) * tile_size);
    output.y = center.y - ((dimensions.y / 2) * tile_size);
    return output;
}