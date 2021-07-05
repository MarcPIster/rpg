/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** animate_mob_movement
*/

#include "../../include/my_rpg.h"

void aggro_up_animation(gameloop_t *game, int i)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->mob[i].anim_clock);

    if (elapsed_time.microseconds < 300000 / (game->mob[i].movespeed / 60))
        return;
    if (game->mob[i].anim_rect.left >=
        game->mob[i].anim_rect.width * game->mob[i].animnums.x ||
        game->mob[i].anim_rect.top != game->mob[i].anim_rect.height * 3) {
            game->mob[i].anim_rect.top = game->mob[i].anim_rect.height * 3;
            game->mob[i].anim_rect.left = 0;    
    }
    else if (game->mob[i].anim_rect.left <
        game->mob[i].anim_rect.width * game->mob[i].animnums.x &&
        game->mob[i].anim_rect.top == game->mob[i].anim_rect.height * 3) {
        game->mob[i].anim_rect.left += game->mob[i].anim_rect.width;
    }
    sfSprite_setTextureRect(game->mob[i].out_sprite,
    game->mob[i].anim_rect);
    sfClock_restart(game->mob[i].anim_clock);
}

void aggro_left_animation(gameloop_t *game, int i)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->mob[i].anim_clock);

    if (elapsed_time.microseconds < 300000 / (game->mob[i].movespeed / 60))
        return;
    if (game->mob[i].anim_rect.left >=
        game->mob[i].anim_rect.width * game->mob[i].animnums.x ||
        game->mob[i].anim_rect.top != game->mob[i].anim_rect.height) {
            game->mob[i].anim_rect.top = game->mob[i].anim_rect.height;
            game->mob[i].anim_rect.left = 0;    
    }
    else if (game->mob[i].anim_rect.left <
        game->mob[i].anim_rect.width * game->mob[i].animnums.x &&
        game->mob[i].anim_rect.top == game->mob[i].anim_rect.height) {
        game->mob[i].anim_rect.left += game->mob[i].anim_rect.width;
    }
    sfSprite_setTextureRect(game->mob[i].out_sprite,
    game->mob[i].anim_rect);
    sfClock_restart(game->mob[i].anim_clock);
}

void aggro_down_animation(gameloop_t *game, int i)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->mob[i].anim_clock);

    if (elapsed_time.microseconds < 300000 / (game->mob[i].movespeed / 60))
        return;
    if (game->mob[i].anim_rect.left >=
        game->mob[i].anim_rect.width * game->mob[i].animnums.x ||
        game->mob[i].anim_rect.top != 0) {
            game->mob[i].anim_rect.top = 0;
            game->mob[i].anim_rect.left = 0;    
    }
    else if (game->mob[i].anim_rect.left <
        game->mob[i].anim_rect.width * game->mob[i].animnums.x &&
        game->mob[i].anim_rect.top == 0) {
        game->mob[i].anim_rect.left += game->mob[i].anim_rect.width;
    }
    sfSprite_setTextureRect(game->mob[i].out_sprite,
    game->mob[i].anim_rect);
    sfClock_restart(game->mob[i].anim_clock);
}

void aggro_right_animation(gameloop_t *game, int i)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->mob[i].anim_clock);

    if (elapsed_time.microseconds < 300000 / (game->mob[i].movespeed / 60))
        return;
    if (game->mob[i].anim_rect.left >=
        game->mob[i].anim_rect.width * game->mob[i].animnums.x ||
        game->mob[i].anim_rect.top != game->mob[i].anim_rect.height * 2) {
            game->mob[i].anim_rect.top = game->mob[i].anim_rect.height * 2;
            game->mob[i].anim_rect.left = 0;    
    }
    else if (game->mob[i].anim_rect.left <
        game->mob[i].anim_rect.width * game->mob[i].animnums.x &&
        game->mob[i].anim_rect.top == game->mob[i].anim_rect.height * 2) {
        game->mob[i].anim_rect.left += game->mob[i].anim_rect.width;
    }
    sfSprite_setTextureRect(game->mob[i].out_sprite,
    game->mob[i].anim_rect);
    sfClock_restart(game->mob[i].anim_clock);
}

void animate_mob_movement(gameloop_t *game)
{
    sfVector2i direction;

    for (int i = 0; i < game->mob->unit_amount; i++) {
        if (game->mob[i].aggro != 0){
            switch (game->mob[i].aggro)
            {
            case 1:
                aggro_up_animation(game, i);
                break;
            case 2:
                aggro_left_animation(game, i);
                break;
            case 3:
                aggro_down_animation(game, i);
                break;
            case 4:
                aggro_right_animation(game, i);
                break;
            }   
        }
    }
}