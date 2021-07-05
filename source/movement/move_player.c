/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** move_player
*/

#include "../../include/my_rpg.h"

int check_hitbox_wall(gameloop_t *game, sfVector2f player, screen_t *screen)
{
    sfVector2f backdoor;
    sfVector2f frontdoor;

    frontdoor.x = 1250;
    frontdoor.y = 7 * 47;
    backdoor.x = 0;
    backdoor.y = 7 * 47;
    if ((game->rm->active_door.x <= player.x|| game->rm->active_door.x <= player.x + 47/2) &&\
        (game->rm->active_door.x + 47 >= player.x ||\
        game->rm->active_door.x + 47 >= player.x + 47/2) &&\
        (game->rm->active_door.y <= player.y  || game->rm->active_door.y <= player.y + 47) &&\
        (game->rm->active_door.y + 47 >= player.y ||\
        game->rm->active_door.y + 47 >= player.y + 47)) {
            return 1;
    } else if ((backdoor.x <= game->player1->position.x || backdoor.x <= game->player1->position.x + 47) &&\
        (backdoor.x + 47 >= game->player1->position.x ||\
        backdoor.x + 47 >= game->player1->position.x + 47) &&\
        (backdoor.y <= game->player1->position.y  || backdoor.y <= game->player1->position.y + 47) &&\
        (backdoor.y + 47 >= game->player1->position.y ||\
        backdoor.y + 47 >= game->player1->position.y + 47)) {
            return 1;
    } else if ((frontdoor.x <= game->player1->position.x || frontdoor.x <= game->player1->position.x + 47) &&\
        (frontdoor.x + 47 >= game->player1->position.x ||\
        frontdoor.x + 47 >= game->player1->position.x + 47) &&\
        (frontdoor.y <= game->player1->position.y  || frontdoor.y <= game->player1->position.y + 47) &&\
        (frontdoor.y + 47 >= game->player1->position.y ||\
        frontdoor.y + 47 >= game->player1->position.y + 47)) {
            if (screen->max_reached > screen->level)
                return 1;
            else
                return 0;
    }
    return 0;
}

void move_player_up(gameloop_t *game, screen_t *screen)
{
    sfVector2f temp;
    temp.x = game->player1->position.x;
    temp.y = game->player1->position.y;
    temp.y -= game->player1->movespeed;

    if (temp.y <= 47 && check_hitbox_wall(game, temp, screen) == 0)
        return;
    game->player1->position.y -= game->player1->movespeed;
    game->player1->prev_pos.y = temp.y;
    game->player1->move_dir = MOVE_UP;
    game->player1->prev_dir = MOVE_UP;
}

void move_player_down(gameloop_t *game, screen_t *screen)
{
    sfVector2f temp;

    temp.x = game->player1->position.x;
    temp.y = game->player1->position.y;
    temp.y += game->player1->movespeed;
    if (temp.y >= 672 && check_hitbox_wall(game, temp, screen) == 0)
        return;
    game->player1->position.y += game->player1->movespeed;
    game->player1->prev_pos.y = temp.y;
    game->player1->move_dir = MOVE_DOWN;
    game->player1->prev_dir = MOVE_DOWN;
}

void move_player_left(gameloop_t *game, screen_t *screen)
{
    sfVector2f temp;

    temp.x = game->player1->position.x;
    temp.y = game->player1->position.y;
    temp.x -= game->player1->movespeed;
    if (temp.x <= 40 && check_hitbox_wall(game, temp, screen) == 0)
        return;
    printf("pos x %f pos y %f\n", game->player1->position.x, game->player1->position.y);
    game->player1->position.x -= game->player1->movespeed;
    game->player1->prev_pos.x = temp.x;
    game->player1->move_dir = MOVE_LEFT;
    game->player1->prev_dir = MOVE_LEFT;
}

void move_player_right(gameloop_t *game, screen_t *screen)
{
    sfVector2f temp;

    temp.x = game->player1->position.x;
    temp.y = game->player1->position.y;
    temp.x += game->player1->movespeed;
    if (temp.x >= 1233 && check_hitbox_wall(game, temp, screen) == 0)
        return;
    game->player1->position.x += game->player1->movespeed;
    game->player1->prev_pos.x = temp.x;
    game->player1->move_dir = MOVE_RIGHT;
    game->player1->prev_dir = MOVE_RIGHT;
}