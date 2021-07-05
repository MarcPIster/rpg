/*
** EPITECH PROJECT, 2021
** stats_generation.c
** File description:
** .
*/

#include "../../../include/my_rpg.h"

int my_random(int level)
{
    srand(time(NULL));
    int num = rand() % level + 1;
    return (num);
}

player_stats_t *my_player_stats_generation(player_stats_t *player_stats, player *player, window_t *win)
{
    sfFont *font = sfFont_createFromFile("source/fightsystem/fonts/font.otf");

    player_stats->level = player->level;
    player_stats->hp = player->hp;
    player_stats->maxhp = player->hpmax;
    player_stats->attack = player->atk;
    player_stats->defense = player->def;
    player_stats->magic = player->magic;
    player_stats->speed = player->speed;
    player_stats->name_t = sfText_create();
    sfText_setString(player_stats->name_t, "Player");
    sfText_setColor(player_stats->name_t, sfWhite);
    sfText_setCharacterSize(player_stats->name_t, 20);
    sfText_setFont(player_stats->name_t, font);
    sfText_setPosition(player_stats->name_t, (sfVector2f) {50, 235});
    return (player_stats);
}

monster_stats_t *my_monster_stats_generation(monster_stats_t *monster_stats, int player_level, mob_data *monster, window_t *win)
{
    sfFont *font = sfFont_createFromFile("source/fightsystem/fonts/font.otf");

    monster_stats->hp = monster->hp + ((monster->hp /10) * my_random(player_level + 1));  //10 * my_random(player_level + 1);
    monster_stats->maxhp = monster_stats->hp;
    monster_stats->attack = monster->atk + ((monster->atk / 10) * my_random(player_level + 1));//2 * my_random(player_level + 1);
    monster_stats->defense = monster->def + ((monster->atk / 10) * my_random(player_level + 1));//2 * my_random(player_level + 1);
    monster_stats->magic = monster->magic + ((monster->magic / 10) * my_random(player_level + 1));//2 * my_random(player_level + 1);
    monster_stats->speed = monster->speed + ((monster->speed / 10)  *my_random(player_level + 1));//2 * my_random(player_level + 1);
    monster_stats->name_t = sfText_create();
    sfText_setString(monster_stats->name_t, monster->name);
    sfText_setColor(monster_stats->name_t, sfWhite);
    sfText_setCharacterSize(monster_stats->name_t, 20);
    sfText_setFont(monster_stats->name_t, font);
    sfText_setPosition(monster_stats->name_t, (sfVector2f) {570, 235});
    printf("mob2 hp : %d\n", monster_stats->hp);
    printf("mob2 atk : %d\n", monster_stats->attack);
    printf("mob2 def : %d\n", monster_stats->defense);
    printf("mob2 magic : %d\n", monster_stats->magic);
    printf("mob2 speed : %d\n", monster_stats->speed);
    return (monster_stats);
}