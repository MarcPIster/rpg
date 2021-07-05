/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** enter_combat
*/

#include "../../../include/my_rpg.h"

void init_structures_helper(window_t *win, player_stats_t *player_stats,
    monster_stats_t *monster_stats)
{
    for (int i = 0; i < 3; i++) {
        win->sprite[i] = sfSprite_create();
        if (i == 0) {
            win->texture[i] = sfTexture_createFromFile(
                "source/fightsystem/sprites_symbols/sword.png", NULL);
            sfSprite_setTexture(win->sprite[i], win->texture[i], sfTrue);
            sfSprite_setScale(win->sprite[i], (sfVector2f) {0.1, 0.1});
        } else if (i == 1) {
            win->texture[i] = sfTexture_createFromFile(
                "source/fightsystem/sprites_symbols/shield.png", NULL);
            sfSprite_setTexture(win->sprite[i], win->texture[i], sfTrue);
            sfSprite_setScale(win->sprite[i], (sfVector2f) {0.307, 0.307});
        } else {
            win->texture[i] = sfTexture_createFromFile(
                "source/fightsystem/sprites_symbols/magic.png", NULL);
            sfSprite_setTexture(win->sprite[i], win->texture[i], sfTrue);
            sfSprite_setScale(win->sprite[i], (sfVector2f) {0.072, 0.072});
        }
        sfSprite_setPosition(win->sprite[i], (sfVector2f) {330.0, 178.35});
    }
}

void init_rectangle_shapes(window_t *win)
{
    win->background = sfRectangleShape_create();
    sfRectangleShape_setSize(win->background, (sfVector2f) {800, 400});
    sfRectangleShape_setTexture(win->background, win->backgroundpng, sfTrue);
    win->sprite[4] = sfSprite_create();
    sfSprite_setTexture(win->sprite[4], win->texture[4], sfTrue);
    win->plrcurhpbar = sfRectangleShape_create();
    sfRectangleShape_setTexture(win->plrcurhpbar, win->greenhpbar, sfTrue);
    sfRectangleShape_setPosition(win->plrcurhpbar, (sfVector2f) {40, 260});
    sfRectangleShape_setSize(win->plrcurhpbar, (sfVector2f) {150, 30});
    win->mobcurhpbar = sfRectangleShape_create();
    sfRectangleShape_setTexture(win->mobcurhpbar, win->greenhpbar, sfTrue);
    sfRectangleShape_setPosition(win->mobcurhpbar, (sfVector2f) {555, 260});
    sfRectangleShape_setSize(win->mobcurhpbar, (sfVector2f) {150, 30});
    win->maxhpbar = sfRectangleShape_create();
    sfRectangleShape_setTexture(win->maxhpbar, win->redhpbar, sfTrue);
    sfRectangleShape_setSize(win->maxhpbar, (sfVector2f) {150, 30});
}

void load_textures(window_t *win)
{
    win->clock = sfClock_create();
    win->time = 0;
    win->end = 0;
    win->info = 0;
    win->info_check = 0;
    win->greenhpbar = sfTexture_createFromFile(
        "./assets/fight_background/health_bar_green.png", NULL);
    win->redhpbar = sfTexture_createFromFile(
        "./assets/fight_background/health_bar_red.png", NULL);
    win->backgroundpng = sfTexture_createFromFile(
        "./assets/fight_background/dungeonbackground.png", NULL);
    win->texture[4] = sfTexture_createFromFile(
        "source/fightsystem/sprites_symbols/battle_info.png", NULL);
    win->player_text = sfTexture_createFromFile(
        "source/fightsystem/sprites_symbols/player_fight.png", NULL);
}

void init_structures(window_t *win, gameloop_t *game,
    player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    win->mode = (sfVideoMode) {800, 600, 32};
    win->window =
    sfRenderWindow_create(win->mode, "SFML window", sfResize | sfClose, NULL);

    win->sprite = malloc(sizeof(sfSprite *) * 6);
    win->texture = malloc(sizeof(sfTexture *) * 5);
    win->text = malloc(sizeof(sfText *) * 10);
    win->player = sfRectangleShape_create();
    win->enemy = sfRectangleShape_create();
    load_textures(win);
    init_rectangle_shapes(win);
    if (!win->window || !win->sprite || !win->texture || !win->text)
        exit(84);
    init_structures_helper(win, player_stats, monster_stats);
    player_stats =
        my_player_stats_generation(player_stats, game->player1, win);
    monster_stats = \
    my_monster_stats_generation(monster_stats,
        player_stats->level, &game->mob[game->mobfightindex], win);
}