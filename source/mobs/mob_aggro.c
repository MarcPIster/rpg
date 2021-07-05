/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** mob_move
*/

#include "../../include/my_rpg.h"

int check_in_move_radius(sfVector2f currentpos, sfVector2f tarpos, int range)
{
    int arrived = 0;

    if (fabs(currentpos.x - tarpos.x) < range &&
        fabs(currentpos.y - tarpos.y) < range) {
            arrived = 1;
        }
    return arrived;
}

int set_facing_direction(double hori, double vert, sfVector2i direction)
{
    
    if (hori > vert) {
        if (direction.x == 1) {
            return MOVE_RIGHT;
        }
        else
            return MOVE_LEFT;
    }
    else {
        if (direction.y == 1) {
            return MOVE_DOWN;
        }
        else 
            return MOVE_UP;
    }
}

sfVector2i direction_check(mob_data *current_mob, player *player1)
{
    sfVector2i direction;
    direction.x = 1;
    direction.y = 1;

    if (current_mob->position.x > player1->position.x)
            direction.x = -1;
    if (current_mob->position.y > player1->position.y)
            direction.y = -1;
    current_mob->aggro = set_facing_direction(fabs(current_mob->position.x - player1->position.x), fabs(current_mob->position.y - player1->position.y), direction);
    return direction;
}

void move_math(mob_data *current_mob, player *player1, sfVector2i direction)
{
    double delta_y = 0;
    double delta_x = 0;
    double newangle = 0;
    double valX = 0;
    double valY = 0;

    delta_y = fabs(player1->position.y - current_mob->position.y);
    delta_x = fabs(player1->position.x - current_mob->position.x);
    newangle = atan2(delta_x, delta_y);
    valX = sinf(newangle) * (current_mob->movespeed / FRAMERATE);
    valY = cosf(newangle) * (current_mob->movespeed / FRAMERATE);
    current_mob->position.x = current_mob->position.x + (direction.x * valX);
    current_mob->position.y = current_mob->position.y + (direction.y * valY);
}

void mob_aggro(gameloop_t *game, screen_t *screen)
{
    sfVector2i direction;

    if (game->state != world)
            return;
    for (int i = 0; i < game->mob->unit_amount; i++) {
        if (game->mob[i].minspawnlevel == screen->level) {
            if (check_in_move_radius(game->player1->position, game->mob[i].position, game->mob[i].aggrorange)) {
                direction = direction_check(&game->mob[i], game->player1);
                move_math(&game->mob[i], game->player1, direction);
                sfSprite_setPosition(game->mob[i].out_sprite, game->mob[i].position);
            }
            else
                game->mob[i].aggro = 0;
        }
    }
}