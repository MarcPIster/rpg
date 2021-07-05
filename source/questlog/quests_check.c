/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** quests_check
*/

#include "../../include/my_rpg.h"

void reward_player(player *player1, int i, gameloop_t *game)
{
    player1->exp = player1->exp + player1->questlist[i].exp_reward;
    player1->atk = player1->atk + player1->questlist[i].atk_reward;
    player1->def = player1->def + player1->questlist[i].def_reward;
    player1->magic = player1->magic + player1->questlist[i].magic_reward;

    for (int a = 0; a < 8; a++) {
        if (player1->inventory[a].item_index == -1 && player1->questlist[i].quest_index != -1) {
            player1->inventory[a] = game->items[player1->questlist[i].item_reward_index];
            break;
        }
    }
    sfMusic_play(game->victory);
    launch_win_particles(game);
}

void check_looted_item(int i, gameloop_t *game)
{
    int itemtarget = game->player1->questlist[i].item_to_have_index;
    if (game->player1->questlist[i].item_to_have_index < 0)
        return;
    for (int a = 0; a < 8; a++) {
        if (game->player1->inventory[a].item_index == itemtarget){
            printf("Item is in the bag quest complete\n");
            reward_player(game->player1, i, game);
            abandon_quest(i, game->player1->questlist, game->player1);;
        }
    }
}

void check_killed_target(int i, gameloop_t *game)
{
    int mobtarget = game->player1->questlist[i].mob_to_kill_index;
    if (game->player1->questlist[i].mob_to_kill_index < 0)
        return;
    char *mobname = game->mob[mobtarget].name;
    for (int a = 0; a < game->mob->unit_amount; a++) {
        if (!my_strcmp(game->mob[a].name, mobname) && game->mob[a].is_alive == 0) {
            printf("Monster killed quest success!\n");
            reward_player(game->player1, i, game);
            abandon_quest(i, game->player1->questlist, game->player1);
        }
    }
}

void quests_check(gameloop_t *game, screen_t *screen)
{
    for (int i = 0; i < 8; i++) {
        if (game->player1->questlist[i].quest_index != -1) {
            check_killed_target(i, game);
            check_looted_item(i, game);
        }
    }
}