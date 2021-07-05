/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** animate_npc_movement
*/

#include "../../include/my_rpg.h"

void aggro_up_animation2(gameloop_t *game, int i)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->npc[i].anim_clock);

    if (elapsed_time.microseconds < 300000 / (game->npc[i].movespeed / 60))
        return;
    if (game->npc[i].anim_rect.left >=
        game->npc[i].anim_rect.width * game->npc[i].animnums.x ||
        game->npc[i].anim_rect.top != game->npc[i].anim_rect.height * 3) {
            game->npc[i].anim_rect.top = game->npc[i].anim_rect.height * 3;
            game->npc[i].anim_rect.left = 0;    
    }
    else if (game->npc[i].anim_rect.left <
        game->npc[i].anim_rect.width * game->npc[i].animnums.x &&
        game->npc[i].anim_rect.top == game->npc[i].anim_rect.height * 3) {
        game->npc[i].anim_rect.left += game->npc[i].anim_rect.width;
    }
    sfSprite_setTextureRect(game->npc[i].npc_sprite,
    game->npc[i].anim_rect);
    sfClock_restart(game->npc[i].anim_clock);
}

void aggro_left_animation2(gameloop_t *game, int i)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->npc[i].anim_clock);

    if (elapsed_time.microseconds < 300000 / (game->npc[i].movespeed / 60))
        return;
    if (game->npc[i].anim_rect.left >=
        game->npc[i].anim_rect.width * game->npc[i].animnums.x ||
        game->npc[i].anim_rect.top != game->npc[i].anim_rect.height) {
            game->npc[i].anim_rect.top = game->npc[i].anim_rect.height;
            game->npc[i].anim_rect.left = 0;    
    }
    else if (game->npc[i].anim_rect.left <
        game->npc[i].anim_rect.width * game->npc[i].animnums.x &&
        game->npc[i].anim_rect.top == game->npc[i].anim_rect.height) {
        game->npc[i].anim_rect.left += game->npc[i].anim_rect.width;
    }
    sfSprite_setTextureRect(game->npc[i].npc_sprite,
    game->npc[i].anim_rect);
    sfClock_restart(game->npc[i].anim_clock);
}

void aggro_down_animation2(gameloop_t *game, int i)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->npc[i].anim_clock);

    if (elapsed_time.microseconds < 300000 / (game->npc[i].movespeed / 60))
        return;
    if (game->npc[i].anim_rect.left >=
        game->npc[i].anim_rect.width * game->npc[i].animnums.x ||
        game->npc[i].anim_rect.top != 0) {
            game->npc[i].anim_rect.top = 0;
            game->npc[i].anim_rect.left = 0;    
    }
    else if (game->npc[i].anim_rect.left <
        game->npc[i].anim_rect.width * game->npc[i].animnums.x &&
        game->npc[i].anim_rect.top == 0) {
        game->npc[i].anim_rect.left += game->npc[i].anim_rect.width;
    }
    sfSprite_setTextureRect(game->npc[i].npc_sprite,
    game->npc[i].anim_rect);
    sfClock_restart(game->npc[i].anim_clock);
}

void aggro_right_animation2(gameloop_t *game, int i)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->npc[i].anim_clock);

    if (elapsed_time.microseconds < 300000 / (game->npc[i].movespeed / 60))
        return;
    if (game->npc[i].anim_rect.left >=
        game->npc[i].anim_rect.width * game->npc[i].animnums.x ||
        game->npc[i].anim_rect.top != game->npc[i].anim_rect.height * 2) {
            game->npc[i].anim_rect.top = game->npc[i].anim_rect.height * 2;
            game->npc[i].anim_rect.left = 0;    
    }
    else if (game->npc[i].anim_rect.left <
        game->npc[i].anim_rect.width * game->npc[i].animnums.x &&
        game->npc[i].anim_rect.top == game->npc[i].anim_rect.height * 2) {
        game->npc[i].anim_rect.left += game->npc[i].anim_rect.width;
    }
    sfSprite_setTextureRect(game->npc[i].npc_sprite,
    game->npc[i].anim_rect);
    sfClock_restart(game->npc[i].anim_clock);
}

void animate_npc_movement(gameloop_t *game)
{
    sfVector2i direction;

    for (int i = 0; i < game->npc->unit_amount; i++) {
        if (game->npc[i].aggro != 0){
            switch (game->npc[i].aggro)
            {
            case 1:
                aggro_up_animation2(game, i);
                break;
            case 2:
                aggro_left_animation2(game, i);
                break;
            case 3:
                aggro_down_animation2(game, i);
                break;
            case 4:
                aggro_right_animation2(game, i);
                break;
            }   
        }
    }
}