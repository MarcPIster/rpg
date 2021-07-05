/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** animate_player_movement
*/

#include "../../include/my_rpg.h"

void move_up_animation(gameloop_t *game)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->player1->anim_clock);

    if (elapsed_time.microseconds < 400000 / game->player1->movespeed)
        return;
    if (game->player1->animation_rect.left >= ANIM_SQ_W * 2 ||
        game->player1->animation_rect.top != ANIM_SQ_H * 3) {
            game->player1->animation_rect.top = ANIM_SQ_H * 3;
            game->player1->animation_rect.left = 0;    
    }
    else if (game->player1->animation_rect.left < ANIM_SQ_W * 2 &&
        game->player1->animation_rect.top == ANIM_SQ_H * 3) {
        game->player1->animation_rect.left += ANIM_SQ_W;
    }
    sfSprite_setTextureRect(game->player1->player1_sprite,
    game->player1->animation_rect);
    sfClock_restart(game->player1->anim_clock);
}

void move_left_animation(gameloop_t *game)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->player1->anim_clock);

    if (elapsed_time.microseconds < 400000 / game->player1->movespeed)
        return;
    if (game->player1->animation_rect.left >= ANIM_SQ_W * 2 ||
        game->player1->animation_rect.top != ANIM_SQ_H) {
            game->player1->animation_rect.top = ANIM_SQ_H;
            game->player1->animation_rect.left = 0;    
    }
    else if (game->player1->animation_rect.left < ANIM_SQ_W * 2 &&
        game->player1->animation_rect.top == ANIM_SQ_H) {
        game->player1->animation_rect.left += ANIM_SQ_W;
    }
    sfSprite_setTextureRect(game->player1->player1_sprite,
    game->player1->animation_rect);
    sfClock_restart(game->player1->anim_clock);
}

void move_down_animation(gameloop_t *game)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->player1->anim_clock);

    if (elapsed_time.microseconds < 400000 / game->player1->movespeed)
        return;
    if (game->player1->animation_rect.left >= ANIM_SQ_W * 2 ||
        game->player1->animation_rect.top != 0) {
            game->player1->animation_rect.top = 0;
            game->player1->animation_rect.left = 0;    
    }
    else if (game->player1->animation_rect.left < ANIM_SQ_W * 2 &&
        game->player1->animation_rect.top == 0) {
        game->player1->animation_rect.left += ANIM_SQ_W;
    }
    sfSprite_setTextureRect(game->player1->player1_sprite,
    game->player1->animation_rect);
    sfClock_restart(game->player1->anim_clock);
}

void move_right_animation(gameloop_t *game)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->player1->anim_clock);

    if (elapsed_time.microseconds < 400000 / game->player1->movespeed)
        return;
    if (game->player1->animation_rect.left >= ANIM_SQ_W * 2 ||
        game->player1->animation_rect.top != ANIM_SQ_H * 2) {
            game->player1->animation_rect.top = ANIM_SQ_H * 2;
            game->player1->animation_rect.left = 0;    
    }
    else if (game->player1->animation_rect.left < ANIM_SQ_W * 2 &&
        game->player1->animation_rect.top == ANIM_SQ_H * 2) {
        game->player1->animation_rect.left += ANIM_SQ_W;
    }
    sfSprite_setTextureRect(game->player1->player1_sprite,
    game->player1->animation_rect);
    sfClock_restart(game->player1->anim_clock);
}

void animate_player_movement(gameloop_t *game)
{
    switch (game->player1->move_dir)
    {
    case 1:
        move_up_animation(game);
        break;
    case 2:
        move_left_animation(game);
        break;
    case 3:
        move_down_animation(game);
        break;
    case 5:
        move_idle_animation(game);  
        break;
    case 4:
        move_right_animation(game);
        break;
    }    
}