/*
** EPITECH PROJECT, 2021
** possible_basic_structure
** File description:
** init_fight_scene
*/

#include "../../include/my_rpg.h"

fight_t *init_fight(fight_t *fight)
{
    fight = malloc(sizeof(fight_t));
    fight->background = sfTexture_createFromFile(
            "./assets/fight_background/dungeonbackground.png", NULL);
    fight->fightwindow = sfRectangleShape_create();
    sfRectangleShape_setTexture(fight->fightwindow, fight->background, sfFalse);
    sfRectangleShape_setSize(fight->fightwindow, (sfVector2f) {700, 450});
    sfRectangleShape_setOrigin(fight->fightwindow, (sfVector2f) {350, 225});
    sfRectangleShape_setPosition(fight->fightwindow, (sfVector2f) {640, 350});
    sfRectangleShape_setOutlineThickness(fight->fightwindow, 12.5);
    sfRectangleShape_setOutlineColor(fight->fightwindow, sfRed);
    return fight;
}