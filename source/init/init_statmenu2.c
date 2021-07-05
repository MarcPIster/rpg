/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** init_statmenu2
*/

#include "../../include/my_rpg.h"

void stats_menu_level(statmenu_t *statmenu)
{
    statmenu->level = sfText_create();
    statmenu->curlvl = sfText_create();

    sfText_setString(statmenu->level, "Level : ");
    sfText_setFont(statmenu->level, statmenu->font);
    sfText_setCharacterSize(statmenu->level, 18);
    sfText_setPosition(statmenu->level, (sfVector2f) {1005, 110});
    sfText_setColor(statmenu->level, sfBlack);
    sfText_setFont(statmenu->curlvl, statmenu->font);
    sfText_setCharacterSize(statmenu->curlvl, 18);
    sfText_setPosition(statmenu->curlvl, (sfVector2f) {1075, 110});
    sfText_setColor(statmenu->curlvl, sfBlack);
}

void stats_menu_attack(statmenu_t *statmenu)
{
    statmenu->attack = sfText_create();
    statmenu->curatk = sfText_create();

    sfText_setString(statmenu->attack, "Attack : ");
    sfText_setFont(statmenu->attack, statmenu->font);
    sfText_setCharacterSize(statmenu->attack, 18);
    sfText_setPosition(statmenu->attack, (sfVector2f) {1005, 130});
    sfText_setColor(statmenu->attack, sfBlack);
    sfText_setFont(statmenu->curatk, statmenu->font);
    sfText_setCharacterSize(statmenu->curatk, 18);
    sfText_setPosition(statmenu->curatk, (sfVector2f) {1075, 130});
    sfText_setColor(statmenu->curatk, sfBlack);

}

void stats_menu_defense(statmenu_t *statmenu)
{
    statmenu->defense = sfText_create();
    statmenu->curdef = sfText_create();

    sfText_setString(statmenu->defense, "Defense : ");
    sfText_setFont(statmenu->defense, statmenu->font);
    sfText_setCharacterSize(statmenu->defense, 18);
    sfText_setPosition(statmenu->defense, (sfVector2f) {1005, 150});
    sfText_setColor(statmenu->defense, sfBlack);
    sfText_setFont(statmenu->curdef, statmenu->font);
    sfText_setCharacterSize(statmenu->curdef, 18);
    sfText_setPosition(statmenu->curdef, (sfVector2f) {1075, 150});
    sfText_setColor(statmenu->curdef, sfBlack);
}

void stats_menu_speed(statmenu_t *statmenu)
{
    statmenu->speed = sfText_create();
    statmenu->curspd = sfText_create();

    sfText_setString(statmenu->speed, "Speed : ");
    sfText_setFont(statmenu->speed, statmenu->font);
    sfText_setCharacterSize(statmenu->speed, 18);
    sfText_setPosition(statmenu->speed, (sfVector2f) {1005, 170});
    sfText_setColor(statmenu->speed, sfBlack);
    sfText_setFont(statmenu->curspd, statmenu->font);
    sfText_setCharacterSize(statmenu->curspd, 18);
    sfText_setPosition(statmenu->curspd, (sfVector2f) {1075, 170});
    sfText_setColor(statmenu->curspd, sfBlack);
}

void stats_menu_magic(statmenu_t *statmenu)
{
    statmenu->magic = sfText_create();
    statmenu->curmag = sfText_create();

    sfText_setString(statmenu->magic, "Magic : ");
    sfText_setFont(statmenu->magic, statmenu->font);
    sfText_setCharacterSize(statmenu->magic, 18);
    sfText_setPosition(statmenu->magic, (sfVector2f) {1005, 190});
    sfText_setColor(statmenu->magic, sfBlack);
    sfText_setFont(statmenu->curmag, statmenu->font);
    sfText_setCharacterSize(statmenu->curmag, 18);
    sfText_setPosition(statmenu->curmag, (sfVector2f) {1075, 190});
    sfText_setColor(statmenu->curmag, sfBlack);
}