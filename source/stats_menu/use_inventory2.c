/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** use_inventory2
*/

#include "../../include/my_rpg.h"

void throw_item(int i, item_list *inventory, player *player1, gameloop_t *game)
{
    if (inventory[i].equiped == 1)
        equip_item(i, inventory, player1, game);
    printf("thorwing item %d\n", i+1);
    inventory[i].item_name = "-EMPTY-";
    inventory[i].item_index = -1;
    inventory[i].use_hp = 0;
    inventory[i].use_hpmax = 0;
    inventory[i].use_atk = 0;
    inventory[i].use_def = 0;
    inventory[i].use_speed = 0;
    inventory[i].use_mvspeed = 0;
    inventory[i].use_mag = 0;
    inventory[i].equipable = 0;
    inventory[i].equiped = 0;
}

void use_item(int i, item_list *inventory, player *player1, gameloop_t *game)
{
    launch_useitem_particles(game);
    printf("using item %d\n", i+1);
    player1->hp += inventory[i].use_hp;
    player1->hpmax += inventory[i].use_hpmax;
    player1->atk += inventory[i].use_atk;
    player1->def += inventory[i].use_def;
    player1->speed += inventory[i].use_speed;
    player1->movespeed += inventory[i].use_mvspeed;
    player1->magic += inventory[i].use_mag;
    if (player1->hp > player1->hpmax)
        player1->hp = player1->hpmax;
    throw_item(i, inventory, player1, game);
}

void equip_item(int i, item_list *inventory, player *player1, gameloop_t *game)
{
    int equneq = 1;
    if (inventory[i].equiped == 1) {
        equneq = -1;
        inventory[i].equiped = 0;
    }
    else
        inventory[i].equiped = 1;
    if (inventory[i].equiped == 1)
        launch_equipgear_particles(game);
    printf("wearing %d item %d\n",equneq, i+1);
    player1->hp += inventory[i].use_hp * equneq;
    player1->hpmax += inventory[i].use_hpmax * equneq;
    player1->atk += inventory[i].use_atk * equneq;
    player1->def += inventory[i].use_def * equneq;
    player1->speed += inventory[i].use_speed * equneq;
    player1->movespeed += inventory[i].use_mvspeed * equneq;
    player1->magic += inventory[i].use_mag * equneq;
    if (player1->hp > player1->hpmax)
        player1->hp = player1->hpmax;
    
}