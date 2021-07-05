/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** draw_scenes
*/


#include "../../include/my_rpg.h"


void check_hitbox_project_helper(gameloop_t *game, screen_t *screen)
{
    if ((game->rm->active_door.x <= game->player1->position.x || game->rm->active_door.x <= game->player1->position.x + 47/2) &&\
        (game->rm->active_door.x + 47 >= game->player1->position.x ||\
        game->rm->active_door.x + 47 >= game->player1->position.x + 47/2) &&\
        (game->rm->active_door.y <= game->player1->position.y  || game->rm->active_door.y <= game->player1->position.y + 47) &&\
        (game->rm->active_door.y + 47 >= game->player1->position.y ||\
        game->rm->active_door.y + 47 >= game->player1->position.y + 47)) {
            if (screen->level >= screen->max_reached)
                screen->max_reached++;
            screen->level += 1;
            game->player1->position.x = 70;
            game->player1->position.y = 7 * 47;
            random_door_select(28, 16, game->rm);
    }
}

void check_backdoor(gameloop_t *game, screen_t *screen)
{
    sfVector2f backdoor;
    backdoor.x = 0;
    backdoor.y = 7 * 47;
    if ((backdoor.x <= game->player1->position.x || backdoor.x <= game->player1->position.x + 47/2) &&\
        (backdoor.x + 47 >= game->player1->position.x ||\
        backdoor.x + 47 >= game->player1->position.x + 47/2) &&\
        (backdoor.y <= game->player1->position.y  || backdoor.y <= game->player1->position.y + 47) &&\
        (backdoor.y + 47 >= game->player1->position.y ||\
        backdoor.y + 47 >= game->player1->position.y + 47)) {
            screen->level -= 1;
            game->player1->position.x = 1230;
            game->player1->position.y = 330;
            random_door_select(28, 16, game->rm);
    }
}

void check_frontdoor(gameloop_t *game, screen_t *screen)
{
    sfVector2f frontdoor;
    frontdoor.x = 27*47;
    frontdoor.y = 7 * 47;
    if ((frontdoor.x <= game->player1->position.x || frontdoor.x <= game->player1->position.x + 47/2) &&\
        (frontdoor.x + 47 >= game->player1->position.x ||\
        frontdoor.x + 47 >= game->player1->position.x + 47/2) &&\
        (frontdoor.y <= game->player1->position.y  || frontdoor.y <= game->player1->position.y + 47) &&\
        (frontdoor.y + 47 >= game->player1->position.y ||\
        frontdoor.y + 47 >= game->player1->position.y + 47)) {
            if (screen->max_reached > screen->level) {
                screen->level += 1;
                game->player1->position.x = 70;
                game->player1->position.y = 7 * 47;
                random_door_select(28, 16, game->rm);
            }
        }
}

void check_door(screen_t *screen, gameloop_t *game)
{
    check_hitbox_project_helper(game, screen);
    check_backdoor(game, screen);
    check_frontdoor(game, screen);
}