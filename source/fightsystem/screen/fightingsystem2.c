/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** fightsystem2
*/

#include "../../../include/my_rpg.h"

void put_back_stats(player *player, player_stats_t *player_s)
{
    player->level = player_s->level;
    player->magic = player_s->magic;
    player->speed = player_s->speed;
    player->def = player_s->defense;
    player->atk = player_s->attack;
    player->hp = player_s->hp;
}

void display_hp_bars(player_stats_t *player_stats, monster_stats_t *monster_stats, window_t *win, fbutton_t *button)
{
    float playerhp = ((float)player_stats->hp / (float)player_stats->maxhp);
    float monsterhp = ((float)monster_stats->hp / (float)monster_stats->maxhp);

    if (win->info == 1)
        win->info_check += 1;
        if (win->info_check == 2)
            win->info_check = 0;
    sfRectangleShape_setPosition(win->maxhpbar, (sfVector2f) {555, 260});
    sfRenderWindow_drawRectangleShape(win->window, win->maxhpbar, NULL);
    sfRectangleShape_setScale(win->mobcurhpbar, (sfVector2f) {monsterhp, 1.0});
    sfRenderWindow_drawRectangleShape(win->window, win->mobcurhpbar, NULL);    
    sfRectangleShape_setPosition(win->maxhpbar, (sfVector2f) {40, 260});
    sfRenderWindow_drawRectangleShape(win->window, win->maxhpbar, NULL);
    sfRectangleShape_setScale(win->plrcurhpbar, (sfVector2f) {playerhp, 1.0});
    sfRenderWindow_drawRectangleShape(win->window, win->plrcurhpbar, NULL);
    sfRenderWindow_drawText(win->window, monster_stats->name_t, NULL);
    sfRenderWindow_drawText(win->window, player_stats->name_t, NULL);
    if (win->info_check == 1) {
        sfRenderWindow_drawSprite(win->window, win->sprite[4], NULL);
        sfRenderWindow_drawSprite(win->window, button->rect[4], NULL);
    }
}

void display_hp_bars2(player_stats_t *player_stats, monster_stats_t *monster_stats, window_t *win)
{
    float playerhp = ((float)player_stats->prevhp / (float)player_stats->maxhp);
    float monsterhp = ((float)monster_stats->prevhp / (float)monster_stats->maxhp);

    sfRectangleShape_setPosition(win->maxhpbar, (sfVector2f) {555, 260});
    sfRenderWindow_drawRectangleShape(win->window, win->maxhpbar, NULL);
    sfRectangleShape_setScale(win->mobcurhpbar, (sfVector2f) {monsterhp, 1.0});
    sfRenderWindow_drawRectangleShape(win->window, win->mobcurhpbar, NULL);    
    sfRectangleShape_setPosition(win->maxhpbar, (sfVector2f) {40, 260});
    sfRenderWindow_drawRectangleShape(win->window, win->maxhpbar, NULL);
    sfRectangleShape_setScale(win->plrcurhpbar, (sfVector2f) {playerhp, 1.0});
    sfRenderWindow_drawRectangleShape(win->window, win->plrcurhpbar, NULL);
    sfRenderWindow_drawText(win->window, monster_stats->name_t, NULL);
    sfRenderWindow_drawText(win->window, player_stats->name_t, NULL);
}