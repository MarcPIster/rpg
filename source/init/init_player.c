/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** init_player
*/

#include "../../include/my_rpg.h"

void init_playerv2(player *player1)
{
    char *walking = "./assets/sprites/player/walking1.png";
    char *dying = "./assets/sprites/player/ace1.png";
    char *portrait = "./assets/sprites/player/dying1.png";
    char *battle = "./assets/sprites/player/ace1.png";
    player1->movespeed = 2;
    player1->position.x = 640;
    player1->position.y = 360;
    player1->prev_pos = player1->position;
    player1->walking = sfTexture_createFromFile(walking, NULL);
    player1->battle = sfTexture_createFromFile(battle, NULL);
    player1->dying = sfTexture_createFromFile(dying, NULL);
    player1->portrait = sfTexture_createFromFile(portrait, NULL);
    player1->player1_sprite = sfSprite_create();
    sfSprite_setOrigin(player1->player1_sprite, player1->origin);
    sfSprite_setTextureRect(player1->player1_sprite, player1->animation_rect);
    sfSprite_setTexture(player1->player1_sprite, player1->walking, 0);
}

void init_playerv3(player *player1)
{
    player1->level = 1;
    player1->atk = 10;
    player1->def = 10;
    player1->speed = 10;
    player1->magic = 10;
    player1->hp = 100;
    player1->hpmax = 100;
    player1->exp = 0;
}

player *init_player(void)
{
    player *player1 = malloc(sizeof(player));

    /* player1->origin.x = 64 / 2;
    player1->origin.y = 64 / 2; */
    player1->animation_rect.top = 0;
    player1->animation_rect.left = 0;
    player1->animation_rect.width = 47;
    player1->animation_rect.height = 47;
    player1->origin.x = player1->animation_rect.width / 2;
    player1->origin.y = player1->animation_rect.height / 2;
    player1->anim_clock = sfClock_create();
    player1->move_dir = MOVE_DOWN;
    player1->prev_dir = MOVE_DOWN;
    init_playerv2(player1);
    init_playerv3(player1);
    player1->inventory = init_inventory();
    player1->questlist = init_questlist();
    return player1;
}