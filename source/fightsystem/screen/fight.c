/*
** EPITECH PROJECT, 2021
** fight.c
** File description:
** .
*/

#include "../../../include/my_rpg.h"

void player_attack(player_stats_t *player_stats,
    monster_stats_t *monster_stats, int i)
{
    if (i == 1) {
        monster_stats->hp = monster_stats->hp - player_stats->attack;
        player_stats->hp = player_stats->hp - monster_stats->attack;
    } else if (i == 2) {
        if (monster_stats->defense <= 0) {
            monster_stats->hp -= player_stats->attack;
        } else {
            player_stats->hp -= monster_stats->attack * 2;
            monster_stats->defense -= 1;
        }
    } else {
        monster_stats->hp = monster_stats->hp - player_stats->attack * 2;
        player_stats->hp = player_stats->hp - monster_stats->magic * 0.50;
    }
}

void player_defense(player_stats_t *player_stats,
    monster_stats_t *monster_stats, int i)
{
    if (i == 1) {
        if (player_stats->defense <= 0) {
            player_stats->hp -= monster_stats->attack;
        } else {
            monster_stats->hp -= player_stats->attack * 2;
            player_stats->defense -= 1;
        }
    } else if (i == 2) {
        if (player_stats->maxhp - 10 >= player_stats->hp) {
            player_stats->hp += 10;
        }
    } else {
        player_stats->hp = player_stats->hp - monster_stats->magic * 2;
    }
}

void player_magic(player_stats_t *player_stats,
    monster_stats_t *monster_stats, int i)
{
    if (i == 1) {
        monster_stats->hp = monster_stats->hp - player_stats->magic * 0.5;
        player_stats->hp = player_stats->hp - monster_stats->attack * 2;
    } else if (i == 2) {
        monster_stats->hp = monster_stats->hp - player_stats->magic * 2;
    } else {
        monster_stats->hp = monster_stats->hp - player_stats->magic;
        player_stats->hp = player_stats->hp - monster_stats->magic;
    }
}

void player_run(player_stats_t *player_stats,
    monster_stats_t *monster_stats, window_t *win)
{
    if (player_stats->speed <= monster_stats->speed) {
        player_stats->hp = player_stats->hp - 50;
        win->end = 1;
    }
}

int my_fight(int i, player_stats_t *player_stats,
    monster_stats_t *monster_stats, window_t *win)
{
    int enem_turn = my_random(3);
    player_stats->prevhp = player_stats->hp;
    monster_stats->prevhp = monster_stats->hp;
    monster_stats->decision = enem_turn - 1;
    player_stats->decision = i - 1;
    switch (i) {
        case 1: player_attack(player_stats, monster_stats, enem_turn); break;
        case 2: player_defense(player_stats, monster_stats, enem_turn); break;
        case 3: player_magic(player_stats, monster_stats, enem_turn); break;
        case 4: player_run(player_stats, monster_stats, win); break;
    }
    if (player_stats->hp <= 0)
        win->end = -1;
    else if (monster_stats->hp <= 0) {
        win->end = 1;
    }
    printf("%d\n", player_stats->hp);
    printf("%d\n", monster_stats->hp);
    printf("%d\n", player_stats->attack);
    printf("%d\n", player_stats->decision);
    printf("%d\n", monster_stats->decision);
}