/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** enter_combat
*/

#include "../../../include/my_rpg.h"

void display_objects(fbutton_t *button, window_t *win, sfText **text)
{
    static int change = 0;
    
    sfRenderWindow_drawSprite(win->window, win->sprite[change], NULL);
    sfSprite_setPosition(win->sprite[change], (sfVector2f) {430.0, 178.32});
    sfRenderWindow_drawSprite(win->window, win->sprite[change], NULL);
    sfSprite_setPosition(win->sprite[change], (sfVector2f) {330.0, 178.32});
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawRectangleShape(win->window, button->rect[i], NULL);
    sfRenderWindow_drawRectangleShape(win->window, win->player, NULL);
    sfRenderWindow_drawRectangleShape(win->window, win->enemy, NULL);
    if (win->time >= 0.2) {
        sfClock_restart(win->clock);
        win->time = 0;
        change += 1;
    }
    if (change == 3)
        change = 0;
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawText(win->window, text[i], NULL);
}

void eventhandler_helper(window_t *win ,fbutton_t *button, player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed) {
            if (player_stats->speed <= monster_stats->speed) {
                player_stats->hp = player_stats->hp - 50;
                win->end = 1;
            }
        }
    }
}

void game_loop(window_t *win, fbutton_t *buttons, player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    while (sfRenderWindow_isOpen(win->window)) {
        win->time = sfTime_asSeconds(sfClock_getElapsedTime(win->clock));
        eventhandler_helper(win, buttons, player_stats, monster_stats);
        sfRenderWindow_clear(win->window, sfBlack);
        change_state_button(buttons, win, player_stats, monster_stats);
        sfRenderWindow_drawRectangleShape(win->window, win->background, NULL);
        display_objects(buttons, win, win->text);
        display_hp_bars(player_stats, monster_stats, win, buttons);
        sfRenderWindow_display(win->window);
        if (win->end != 0)
            break;
    }
}

void free_struct(window_t *win, fbutton_t *buttons, player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    sfRectangleShape_destroy(win->enemy);
    sfRectangleShape_destroy(win->player);
    for (int i = 0; i < 3; i++) {
        sfSprite_destroy(win->sprite[i]);
        sfTexture_destroy(win->texture[i]);
    }
    free(win->sprite);
    free(win->texture);
    for (int i = 0; i < 5; i++)
        sfText_destroy(win->text[i]);
    free(win->text);
    sfClock_destroy(win->clock);
    for (int i = 0; i < 4; i++)
        sfRectangleShape_destroy(buttons->rect[i]);
    free(buttons->pos);
    free(buttons->rect);
    free(monster_stats->name_t);
    free(player_stats->name_t);
}

int fightsystem(gameloop_t *game)
{
    window_t *win = malloc(sizeof(window_t));
    fbutton_t *buttons = malloc(sizeof(fbutton_t));
    player_stats_t *player_stats = malloc(sizeof(player_stats_t));                   
    monster_stats_t *monster_stats = malloc(sizeof(monster_stats_t));
    sfFont *font = sfFont_createFromFile("source/fightsystem/fonts/font.otf");

    if (!buttons || !win || !player_stats || !monster_stats || !win)
        exit(84);
    init_structures(win, game, player_stats, monster_stats);
    declare_buttons(buttons);
    declare_buttons_helper(buttons);
    intro_scene(win, game->mob[game->mobfightindex].battle);
    declare_text(font, win->text);
    game_loop(win, buttons, player_stats, monster_stats);
    put_back_stats(game->player1, player_stats);
    free_struct(win, buttons, player_stats, monster_stats);
    sfRenderWindow_destroy(win->window);
    return win->end;
}
