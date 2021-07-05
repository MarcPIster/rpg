/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** launch_particles
*/

#include "../../include/my_rpg.h"

void launch_win_particles(gameloop_t *game)
{
    game->part_fx[2].active = 1;
    game->part_fx[2].anim_clock = sfClock_create();
    game->part_fx[2].life_clock = sfClock_create();
}