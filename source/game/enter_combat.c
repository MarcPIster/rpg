/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** enter_combat
*/

#include "../../include/my_rpg.h"

void exp_increase(gameloop_t *game)
{
    static int exp_limit = 500;
    
    game->player1->exp += 100;
    while (game->player1->exp >= exp_limit) {
        game->player1->level += 1;
        game->player1->hpmax += game->player1->hpmax * 0.10;
        game->player1->hp = game->player1->hpmax;
        game->player1->def += game->player1->def * 0.10;
        game->player1->atk += game->player1->atk * 0.10;
        game->player1->magic += game->player1->magic * 0.10;
        game->player1->exp -= exp_limit;
        exp_limit += exp_limit * 0.20;
    }
    if (game->player1->exp < 0) {
        game->player1->exp = 0;
    }
}

void item_drop(gameloop_t *game)
{
    int b = 0;
    int random_nb = 0;

    srand(time(NULL));
    for (int i = 0; game->mob[game->mobfightindex].loot_table[i]; i++) {
        b += 1;
    }
    b -= 1;
    random_nb = rand() % b;
    for (int i = 0; i < 8; i++) {
        if (game->player1->inventory[i].item_index == -1) {
            game->player1->inventory[i] = \
            game->items[game->mob[game->mobfightindex].loot_table[random_nb]];
            printf("looting this item : %s\n", game->items[game->mob[game->mobfightindex].loot_table[random_nb]].item_name);
            break;
        }
    }
}

void enter_combat(gameloop_t *game, screen_t *screen)
{
    int cond = 0;

    for (int i = 0; i < game->mob->unit_amount; i++) {
        if (game->mob[i].minspawnlevel == screen->level && check_in_move_radius(game->player1->position, game->mob[i].position, 48)) {
            printf(" %d ENTER COMBAT\n", i);
            game->state = fight;
            game->mob[i].infight = 1;
            game->mobfightindex = i;
            break;
        }
    }
    if (game->state == fight) {
        printf("mob hp : %d\n", game->mob[game->mobfightindex].hp);
        printf("mob atk : %d\n", game->mob[game->mobfightindex].atk);
        printf("mob def : %d\n", game->mob[game->mobfightindex].def);
        printf("mob magic : %d\n", game->mob[game->mobfightindex].magic);
        printf("mob speed : %d\n", game->mob[game->mobfightindex].speed);
        cond = fightsystem(game);

        if (cond == -1)
            printf("loser\n");
        else {
            item_drop(game);
            exp_increase(game);
            game->mob[game->mobfightindex].is_alive = 0;
            game->mob[game->mobfightindex].position.x = 20;
            game->mob[game->mobfightindex].position.y = 20;
        }
        game->state = world;
        /*sfRenderWindow_drawRectangleShape(screen->window, screen->fight->fightwindow,
        NULL);
        if (sfKeyboard_isKeyPressed(sfKeyM)) {
            game->mob[game->mobfightindex].position = (sfVector2f) {100, 100};
            game->state = world;
        }*/
        //process_combat();
        //draw_combat();
    }
}