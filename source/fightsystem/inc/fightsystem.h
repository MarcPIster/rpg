/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** header file
*/

#ifndef FIGHTSYSTEM_H_
#define FIGHTSYSTEM_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

typedef struct fight_buttons_s {
    sfRectangleShape **rect;
    sfVector2f *pos;
} fbutton_t;

typedef struct window_stats_s {
    sfVideoMode mode;
    sfEvent event;
    sfRenderWindow* window;
    sfVector2i pos;
    sfVector2i pos_pics;
    sfRectangleShape *player;
    sfRectangleShape *enemy;
    sfSprite **sprite;
    sfTexture **texture;
    sfClock *clock;
    sfText **text;
    float time;
    int end;
} window_t;

typedef struct player_stats_s {
    int level;
    int hp;
    int attack;
    int defense;
    int magic;
    int speed;
    int decision;
} player_stats_t;

typedef struct monster_stats_s {
    int hp;
    int attack;
    int defense;
    int magic;
    int speed;
    int decision;
} monster_stats_t;

player_stats_t *my_player_stats_generation(player_stats_t *player_stats);
monster_stats_t *my_monster_stats_generation(monster_stats_t *monster_stats, int player_level);
int my_random(int level);
int my_fight(int i, player_stats_t *player_stats, monster_stats_t *monster_stats, window_t *win);
void defense_button(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats);
void attack_button(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats);
void run_away_button(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats);
void magic_button(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats);
void change_state_button(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats);
void intro_scene(window_t *win);
void declare_buttons(fbutton_t *button);
void declare_buttons_helper(fbutton_t *button);
void eventhandler_helper(window_t *win ,fbutton_t *button, player_stats_t *player, monster_stats_t *monster);
void display_objects(fbutton_t *button, window_t *win, sfText **text);
void fight_result(fbutton_t *buttons, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats);
void declare_text(sfFont *font, sfText **text);
void init_structures(window_t *win, fbutton_t *buttons, player_stats_t *player_stats, monster_stats_t *monster_stats);
int fightsystem();

#endif /* !FIGHTSYSTEM_H_ */