/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** animate_fx
*/

#include "../../include/my_rpg.h"

void launch_win_particles(gameloop_t *game)
{
    game->part_fx[2].active = 1;
    sfClock_restart(game->part_fx[2].anim_clock);
    sfClock_restart(game->part_fx[2].life_clock);
}

void launch_equipgear_particles(gameloop_t *game)
{
    game->part_fx[1].active = 1;
    sfClock_restart(game->part_fx[1].anim_clock);
    sfClock_restart(game->part_fx[1].life_clock);
}

void launch_useitem_particles(gameloop_t *game)
{
    game->part_fx[0].active = 1;
    sfClock_restart(game->part_fx[0].anim_clock);
    sfClock_restart(game->part_fx[0].life_clock);
}

void update_fx_texture(gameloop_t *game, int i)
{
    printf("animation left %d\n", game->part_fx[i].animation_rect.left);
    printf("whole image widt : %d\n", game->part_fx[i].image_width);
    printf("animation top %d\n", game->part_fx[i].animation_rect.top);
    printf("whole image geight : %d\n", game->part_fx[i].image_height);
    if (game->part_fx[i].animation_rect.left >= (game->part_fx[i].image_width - game->part_fx[i].animation_rect.width)) {
        game->part_fx[i].animation_rect.left = 0;
        if (game->part_fx[i].animation_rect.top < (game->part_fx[i].image_height - game->part_fx[i].animation_rect.height))
            game->part_fx[i].animation_rect.top = game->part_fx[i].animation_rect.top + game->part_fx[i].animation_rect.width;
        else
            game->part_fx[i].animation_rect.top = 0;
    }
    else 
        game->part_fx[i].animation_rect.left = game->part_fx[i].animation_rect.left + game->part_fx[i].animation_rect.width;
    sfSprite_setTextureRect(game->part_fx[i].psprite, game->part_fx[i].animation_rect);
    //sfSprite_setScale(game->part_fx[i].psprite, game->part_fx[i].scale);
    sfClock_restart(game->part_fx[i].anim_clock);     
}

void animate_fx(gameloop_t *game)
{
    sfTime elapsed_time;
    sfTime life_time;
    for (int i = 0; i < 3 ; i++) {
        elapsed_time = sfClock_getElapsedTime(game->part_fx[i].anim_clock);
        life_time = sfClock_getElapsedTime(game->part_fx[i].life_clock);
        if ( game->part_fx[i].active == 1) {
            if (life_time.microseconds >= (60000 * game->part_fx[i].anim_count)) {
                game->part_fx[i].animation_rect.top = 0;
                game->part_fx[i].animation_rect.left = 0;
                game->part_fx[i].active = 0;
                printf("time to delete\n");
            }
            if (elapsed_time.microseconds >= 60000) {
                update_fx_texture(game, i);
            }
        }      
    }
}