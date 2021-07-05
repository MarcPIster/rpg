/*
** EPITECH PROJECT, 2021
** screen.h
** File description:
** .
*/

#ifndef SCREEN_STRUCTS_H
#define SCREEN_STRUCTS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <time.h>

#define MOVE_UP 1
#define MOVE_LEFT 2
#define MOVE_DOWN 3
#define MOVE_RIGHT 4
#define MOVE_IDLE 5

#define ANIM_SQ_H 48
#define ANIM_SQ_W 47

#define FRAMERATE 60

#define AGGRO_RADIUS 200

typedef struct doorways {
    int **shape;
    struct room *next_room;
    int arrival_doorway;
} doorways;


typedef struct room {
    // About the room itself
    int **tiling;
    doorways *connections;
    sfVector2f active_door;
} room;

typedef struct game {
    // Render Window
    sfRenderWindow *render;

    // Textures + data
    sfTexture **tileset;

    // Sprites
    sfSprite **tile_sprites;

    // Entities
    // This is where the player structure would go
} game;

typedef enum game_state {
    world,
    fight,
    menu,
    inventory,
    stats,
    npctalk,
} game_state_t;

typedef enum stat_menu_state {
    statmenuopen,
    statmenuclosed,
} stat_menu_state_t;

typedef enum questlog_state {
    questlogopen,
    questlogclosed,
} questlog_state_t;

typedef struct particles_s {
    char *name;
    sfTexture *effect;
    sfSprite *psprite;
    sfVector2f position;
    sfVector2f origin;
    sfIntRect animation_rect;
    int image_width;
    int image_height;
    int anim_count;
    sfClock *anim_clock;
    sfClock *life_clock;
    sfVector2f scale;
    int active;

} particles;
typedef enum pause_state_s {
    pauseopen,
    pauseclosed,
} pasue_state_t;

typedef struct item_list_s {
    char *item_name;
    int item_index;
    int use_hp;
    int use_hpmax;
    int use_atk;
    int use_def;
    int use_speed;
    int use_mvspeed;
    int use_mag;
    int equipable;
    int equiped;
} item_list;

typedef struct quest_list_s {
    char *quest_name;
    char *quest_text;
    int quest_index;
    int completed;
    int item_reward_index;
    int mob_to_kill_index;
    int exp_reward;
    int atk_reward;
    int magic_reward;
    int def_reward;
    int item_to_have_index;
} quest_list;

typedef struct player {
    int hp;
    int hpmax;
    int magic;
    int atk;
    int def;
    int level;
    int exp;
    int speed;
    sfTexture *walking;
    sfTexture *dying;
    sfTexture *portrait;
    sfTexture *battle;
    sfVector2f position;
    sfVector2f prev_pos;
    sfSprite *player1_sprite;
    sfVector2f origin;
    sfIntRect animation_rect;
    sfClock *anim_clock;
    item_list *inventory;
    quest_list *questlist;
    int movespeed;
    int move_dir;
    int prev_dir;

} player;

typedef struct npc_data {
    char *name;
    sfTexture *walking;
    sfTexture *portrait;
    sfVector2f position;
    sfVector2f prev_pos;
    sfSprite *npc_sprite;
    sfVector2f origin;
    sfVector2i animnums;
    sfIntRect anim_rect;
    sfClock *anim_clock;
    int hasspawned;
    int questnumber;
    int movespeed;
    int aggro;
    int aggrorange;
    int move_dir;
    int prev_dir;
    int unit_amount;
    int intalk;
    int minspawnlevel;
} npc_data;

typedef struct mob_data {
    char *name;
    int hp;
    int atk;
    int def;
    int magic;
    int speed;
    int movespeed;
    bool is_boss;
    int is_alive;
    int has_spawned;
    int aggro;
    int aggrorange;
    int infight;
    int *loot_table;
    int minspawnlevel;
    sfVector2f position;
    sfVector2f origin;
    sfIntRect anim_rect;
    sfVector2i animnums;
    sfClock *anim_clock;
    sfSprite *out_sprite;
    sfTexture *battle;
    sfTexture *dying;
    sfTexture *walking;
    sfTexture *portrait;
    int unit_amount;
} mob_data;

typedef struct csv {
    char ***data;
    char **labels;
    int n_columns;
    int n_rows;
} csv;

typedef struct button_s
{
    sfRectangleShape *rect;
    sfVector2f pos;
    sfFont *font;
    sfText *text;
} button_t;

typedef struct text_s
{
    sfText *text;
    sfFont *font;
} text_t;

typedef struct statmenu
{
    sfTexture *icontexture;
    sfTexture *opentexture;
    sfTexture *buttontexture;
    sfTexture *charface;
    sfRectangleShape *icon_rect;
    sfRectangleShape *open_rect;
    sfRectangleShape *character;
    sfRectangleShape *usebutton;
    sfVector2f iconpos;
    sfVector2f openpos;
    sfVector2f characterpos;
    sfFont *font;
    sfFont *buttonfont;
    sfText *inventory;
    sfText *buttontext;
    sfText *level;
    sfText *curlvl;
    sfText *attack;
    sfText *curatk;
    sfText *defense;
    sfText *curdef;
    sfText *speed;
    sfText *curspd;
    sfText *magic;
    sfText *curmag;
    sfText *hp;
    sfText *curhp;
    sfText *hpmax;
    sfText *curhpmax;
    sfText *exp;
    sfText *curexp;
    sfText *item1;
    sfText *item2;
    sfText *item3;
    sfText *item4;
    sfText *item5;
    sfText *item6;
    sfText *item7;
    sfText *item8;
} statmenu_t;

typedef struct questlog
{
    sfTexture *icontexture;
    sfTexture *opentexture;
    sfTexture *buttontexture;
    sfRectangleShape *icon_rect;
    sfRectangleShape *open_rect;
    sfRectangleShape *abandonbutton;
    sfVector2f iconpos;
    sfVector2f openpos;
    sfFont *font;
    sfFont *buttonfont;
    sfText *quests;
    sfText *buttontext;
    sfText *quest1;
    sfText *quest2;
    sfText *quest3;
    sfText *quest4;
    sfText *quest5;
    sfText *quest6;
    sfText *quest7;
    sfText *quest8;
} questlog_t;

typedef struct pause_s {
    button_t **button;
    text_t **text;
    sfSprite *sprite;
    sfTexture *texture;
    sfEvent event;
    pasue_state_t pasuestate;
} pause_t;

typedef struct gameloop_s
{
    sfEvent event;
    mob_data *mob;
    npc_data *npc;
    item_list *items;
    quest_list *questlibrary;
    particles *part_fx;
    player *player1;
    enum game_state state;
    statmenu_t *statmenu;
    questlog_t *questlog;
    enum stat_menu_state menu_state;
    enum questlog_state quest_log_state;
    sfClock *clicktimer;
    int mobfightindex;
    int npcinteractindex;
    room *rm;
    game *gm;
    sfMusic *victory;
} gameloop_t;

typedef struct help_s
{
    sfEvent event;
    button_t **button;
    text_t **text;
} help_t;

typedef struct setting_s
{
    sfEvent event;
    button_t **button;
    sfRectangleShape *volp;
    sfRectangleShape *volm;
    sfSprite *plus;
    sfSprite *minus;
    sfTexture *vp;
    sfTexture *vm;
    text_t **text;
    sfVector2f posplus;
    sfVector2f posminus;
    int prev_s;
} setting_t;

typedef struct fight_s
{
    sfRectangleShape *fightwindow;
    sfTexture *background;
} fight_t;

typedef struct main_s
{
    button_t **button;
    text_t **text;
    sfSprite *sprite;
    sfTexture *texture;
    sfEvent event;
} main_t;

typedef struct screen_s
{
    sfRenderWindow *window;
    sfVideoMode video;
    sfEvent event;
    float volume;
    int mode;
    main_t *main;
    help_t *help;
    pause_t *pause;
    setting_t *setting;
    gameloop_t *game;
    fight_t *fight;
    sfMusic *soundtrack;
    sfMusic *battle_start;
    sfMusic *death;
    sfSprite *background;
    sfTexture *bgt;
    int level;
    int max_reached;
} screen_t;

// ffightsystems
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
    sfTexture *greenhpbar;
    sfTexture *redhpbar;
    sfTexture *backgroundpng;
    sfRectangleShape *plrcurhpbar;
    sfRectangleShape *mobcurhpbar;
    sfRectangleShape *maxhpbar;
    sfRectangleShape *background;
    sfSprite **sprite;
    sfTexture **texture;
    sfClock *clock;
    sfText **text;
    float time;
    int info_check;
    int info;
    int end;
    sfTexture *player_text;
} window_t;

typedef struct player_stats_s {
    sfText *name_t;
    char *name;
    int level;
    int hp;
    int prevhp;
    int maxhp;
    int attack;
    int defense;
    int magic;
    int speed;
    int decision;
} player_stats_t;

typedef struct monster_stats_s {
    sfText *name_t;
    char *name;
    int hp;
    int prevhp;
    int maxhp;
    int attack;
    int defense;
    int magic;
    int speed;
    int decision;
} monster_stats_t;

#endif