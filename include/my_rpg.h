/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** header file
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include "my.h"
#include "screen_structs.h"

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

#define TILESET_PATH 0

void check_door(screen_t *screen, gameloop_t *game);
void launch_equipgear_particles(gameloop_t *game);
void launch_useitem_particles(gameloop_t *game);
void launch_win_particles(gameloop_t *game);
void animate_fx(gameloop_t *game);
particles *init_fx(char *fx_file_path);
void abandon_quest(int i, quest_list *questlist, player *player1);
void free_char_table(char **table);
void quests_check(gameloop_t *game, screen_t *screen);
quest_list *init_all_quests(char *quest_csv_path);
questlog_t *init_quest_log(questlog_t *questlog);
void quest_log(gameloop_t *game, screen_t *screen);
void init_quests(questlog_t *questlog);
void detect_mouseover_abandon(int i, gameloop_t *game, screen_t *screen, sfVector2i pos_mouse);
quest_list *init_questlist(void);
void display_questlog(gameloop_t *game, screen_t *screen, sfVector2i pos_mouse);
npc_data *init_npcs(char *npcs_csv_path);
void npc_aggro(gameloop_t *game, screen_t *screen);
void animate_npc_movement(gameloop_t *game);
void interact_with_npc(gameloop_t *game, screen_t *screen);
item_list *init_itemslist(char *itemlist_csv_path);
item_list *init_inventory(void);
statmenu_t *init_statmenu(statmenu_t *statmenu);
fight_t *init_fight(fight_t *fight);
main_t *init_main(main_t *main);
button_t **init_main_buttons(button_t **button);
void analyse_events_main(screen_t *screen, main_t *main ,\
sfVector2f pos_mouse);
void detect_mouse_over_button(main_t *main, sfVector2f pos_mouse);
void draw_main(screen_t *screen, main_t *main, sfVector2f pos_mouse);
void detect_mouse_over_button_help(help_t *help, sfVector2f pos_mouse);
void draw_help(screen_t *screen, help_t *help, sfVector2f pos_mouse);
help_t *init_help(help_t *help);
void analyse_help_events(screen_t *screen, help_t *help, sfVector2f pos_mouse);
void analyse_setting_events(screen_t *screen, setting_t *setting, \
sfVector2f pos_mouse);
void detect_mouse_over_button_setting(setting_t *setting, sfVector2f pos_mouse);
setting_t *init_setting(setting_t *setting);
void draw_settings(screen_t *screen, setting_t *setting, sfVector2f pos_mouse);
void draw_game(screen_t *screen, gameloop_t *game);
void gameloop_events(screen_t *screen, gameloop_t *game);
mob_data *parse_monsters(char *monster_csv_path);
csv *parse_csv(char *filepath);
char **my_str_to_word_array(char *str, char sep);
char *read_file(char *filepath);
player *init_player(void);
void animate_player_movement(gameloop_t *game);
void move_player_up(gameloop_t *game, screen_t *screen);
void move_player_down(gameloop_t *game, screen_t *screen);
void move_player_left(gameloop_t *game, screen_t *screen);
void move_player_right(gameloop_t *game, screen_t *screen);
void update_animations(screen_t *screen, gameloop_t *game);
void move_idle_animation(gameloop_t *game);
void mob_aggro(gameloop_t *game, screen_t *screen);
void animate_mob_movement(gameloop_t *game);
void enter_combat(gameloop_t *game, screen_t *screen);
int check_in_move_radius(sfVector2f currentpos, sfVector2f tarpos, int range);
pause_t *init_pause(void);
void draw_pause(screen_t *screen, pause_t *pause, sfVector2f pos_mouse);
void analyse_events_pause(screen_t *screen, pause_t *pause , sfVector2f pos_mouse);
void detect_mouse_over_button_pause(pause_t *pause, sfVector2f pos_mouse);
screen_t *prep_struct(screen_t *screen);
button_t *init_back_h(button_t *button);
button_t **init_help_buttons(button_t **button);
text_t *init_help_head(text_t *text);
text_t *control_header(text_t *text);
text_t *control_body(text_t *text);
button_t *continue_button(void);
button_t *restart_button(void);
button_t *option_button(void);
button_t *main_menu_button(void);
button_t *quit_button(void);
text_t **init_text_setting(text_t **text);
text_t *how_quest(text_t *text);
text_t *description1(text_t *text);
text_t *description2(text_t *text);
text_t *description3(text_t *text);

room *create_room_struct(int min, int max, doorways *next);
doorways create_doorway_struct(int howmany, int max, int min);
void random_door_select(int lenght, int height, room *myroom);

// Launching room
int launch_room(room *rm, game *gm, screen_t *screen);

// Runtime functions
void room_draw(room *rm, game *gm, screen_t *screen);
void room_handle_events(room *rm, game *gm);

game *load_game(char **args, screen_t *screen);
int start_level(screen_t *screen);


//tiling
sfVector2i get_area_dimensions(int **area);
sfVector2f get_window_center(sfRenderWindow *render);
sfSprite *sprite_tiled_area(int **area, sfTexture **tileset, sfRenderWindow *render, sfVector2f start_position);
sfVector2f get_start_pos(room *rm, game *gm, sfRenderWindow *screen);
void draw_tiles(room *rm, game *gm, sfRenderWindow *screen);

//statmenu
char *my_return_number(int nb);
void stats_menu(gameloop_t *game, screen_t *screen);
void stats_menu_level(statmenu_t *statmenu);
void stats_menu_attack(statmenu_t *statmenu);
void stats_menu_defense(statmenu_t *statmenu);
void stats_menu_speed(statmenu_t *statmenu);
void stats_menu_magic(statmenu_t *statmenu);
void stats_menu_inventory(statmenu_t *statmenu);

void display_statmenu(gameloop_t *game, screen_t *screen, sfVector2i pos_mouse);
void display_inventory(gameloop_t *game, screen_t *screen,sfVector2i pos_mouse);
void detect_mouseover_use(int i, gameloop_t *game, screen_t *screen, sfVector2i pos_mouse);
void detect_mouseover_equip(int i, gameloop_t *game, screen_t *screen, sfVector2i pos_mouse);
void detect_mouseover_throw(int i, gameloop_t *game, screen_t *screen, sfVector2i pos_mouse);
void use_items(gameloop_t *game, screen_t *screen, sfVector2i pos_mouse);
void throw_item(int i, item_list *inventory, player *player1, gameloop_t *game);
void use_item(int i, item_list *inventory, player *player1, gameloop_t *game);
void equip_item(int i, item_list *inventory, player *player1, gameloop_t *game);

//fightsystem
player_stats_t *my_player_stats_generation(player_stats_t *player_stats, player *player, window_t *win);
monster_stats_t *my_monster_stats_generation(monster_stats_t *monster_stats, int player_level, mob_data *monster, window_t *win);
int my_random(int level);
int my_fight(int i, player_stats_t *player_stats, monster_stats_t *monster_stats, window_t *win);
void defense_button(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats);
void attack_button(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats);
void run_away_button(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats);
void magic_button(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats);
void change_state_button(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats);
void intro_scene(window_t *win, sfTexture *monster);
void declare_buttons(fbutton_t *button);
void declare_buttons_helper(fbutton_t *button);
void eventhandler_helper(window_t *win ,fbutton_t *button, player_stats_t *player, monster_stats_t *monster);
void display_objects(fbutton_t *button, window_t *win, sfText **text);
void fight_result(fbutton_t *buttons, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats);
void declare_text(sfFont *font, sfText **text);
void init_structures(window_t *win, gameloop_t *game, player_stats_t *player_stats, monster_stats_t *monster_stats);
int fightsystem(gameloop_t *game);
void put_back_stats(player *player, player_stats_t *player_s);
void display_hp_bars(player_stats_t *player_stats, monster_stats_t *monster_stats, window_t *win, fbutton_t *button);
void display_hp_bars2(player_stats_t *player_stats, monster_stats_t *monster_stats, window_t *win);
int detect_info(fbutton_t *button, window_t *win, player_stats_t *player, monster_stats_t *monster);

void destroy_everything(screen_t *s);
void destroy_gameloop(gameloop_t *g);
void destroy_player(player *p);
void destroy_npc(npc_data *n);
void destroy_questlog(questlog_t *q);
void destroy_mob(mob_data *m);
void destroy_room(room *r);

#endif /* !MY_RPG_H_ */
