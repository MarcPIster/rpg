/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** move_idle_animations
*/


#include "../../include/my_rpg.h"

void idle_up_animate(gameloop_t *game)
{
    game->player1->animation_rect.top = ANIM_SQ_H * 3;
    game->player1->animation_rect.left = ANIM_SQ_W;
    sfSprite_setTextureRect(game->player1->player1_sprite,
    game->player1->animation_rect);
    game->player1->prev_dir = MOVE_IDLE;
}

void idle_left_animate(gameloop_t *game)
{
    game->player1->animation_rect.top = ANIM_SQ_H;
    game->player1->animation_rect.left = ANIM_SQ_W;
    sfSprite_setTextureRect(game->player1->player1_sprite,
    game->player1->animation_rect);
    game->player1->prev_dir = MOVE_IDLE;
}

void idle_down_animate(gameloop_t *game)
{
    game->player1->animation_rect.top = 0;
    game->player1->animation_rect.left = ANIM_SQ_W;
    sfSprite_setTextureRect(game->player1->player1_sprite,
    game->player1->animation_rect);
    game->player1->prev_dir = MOVE_IDLE;

}

void idle_right_animate(gameloop_t *game)
{
    game->player1->animation_rect.top = ANIM_SQ_H * 2;
    game->player1->animation_rect.left = ANIM_SQ_W;
    sfSprite_setTextureRect(game->player1->player1_sprite,
    game->player1->animation_rect);
    game->player1->prev_dir = MOVE_IDLE;
}

void move_idle_animation(gameloop_t *game)
{
    sfTime elapsed_time = sfClock_getElapsedTime(game->player1->anim_clock);

    if (elapsed_time.microseconds > 600000 / game->player1->movespeed &&
        game->player1->move_dir == MOVE_IDLE) {
        switch (game->player1->prev_dir)
        {
        case 1:
            idle_up_animate(game);
            break;
        case 2:
            idle_left_animate(game);
            break;
        case 3:
            idle_down_animate(game);
            break;    
        case 4:
            idle_right_animate(game);
            break;
        }
    }
}