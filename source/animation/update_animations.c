/*
** EPITECH PROJECT, 2021
** update_animations.c
** File description:
** .
*/


#include "../../include/my_rpg.h"

void update_player_move_anim(screen_t *screen, gameloop_t *game)
{
    game->player1->prev_pos.x = game->player1->position.x;
    game->player1->prev_pos.y = game->player1->position.y;
    game->player1->move_dir = MOVE_IDLE;
    sfSprite_setPosition(game->player1->player1_sprite, game->player1->position);
    sfRenderWindow_drawSprite(screen->window, game->player1->player1_sprite, NULL);
}

void update_mob_move_anim(screen_t *screen, gameloop_t *game)
{
    for (int i = 0; i < game->mob->unit_amount; i++) {
        if (game->mob[i].minspawnlevel == screen->level) {
            sfSprite_setPosition(game->mob[i].out_sprite, game->mob[i].position);
            sfRenderWindow_drawSprite(screen->window, game->mob[i].out_sprite, NULL);
        }
    }
}

void update_npc_move_anim(screen_t *screen, gameloop_t *game)
{
    for (int i = 0; i < game->npc->unit_amount; i++) {
        if (game->npc[i].minspawnlevel == screen->level) {
            sfSprite_setPosition(game->npc[i].npc_sprite, game->npc[i].position);
            sfRenderWindow_drawSprite(screen->window, game->npc[i].npc_sprite, NULL);
        }
    }
}

void update_fx_animation(screen_t *screen, gameloop_t *game)
{
    sfVector2f fxpos;
    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(game->part_fx[i].psprite, game->player1->position);
        if (i == 1) {
            fxpos.x = game->player1->position.x + 25;
            fxpos.y = game->player1->position.y + 30;
            sfSprite_setPosition(game->part_fx[i].psprite, fxpos);
        }
        sfSprite_setTextureRect(game->part_fx[i].psprite, game->part_fx[i].animation_rect);
        if (game->part_fx[i].active == 1)
            sfRenderWindow_drawSprite(screen->window, game->part_fx[i].psprite, NULL);
    }

}

void update_animations(screen_t *screen, gameloop_t *game)
{
    animate_player_movement(game);
    update_player_move_anim(screen, game);
    animate_mob_movement(game);
    update_mob_move_anim(screen, game);
    animate_npc_movement(game);
    update_npc_move_anim(screen, game);
    animate_fx(game);
    update_fx_animation(screen, game);
}