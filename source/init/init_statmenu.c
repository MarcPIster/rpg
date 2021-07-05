/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** init_statmenu
*/

#include "../../include/my_rpg.h"

void stats_menu_hp(statmenu_t *statmenu)
{
    statmenu->hp = sfText_create();
    statmenu->curhp = sfText_create();

    sfText_setString(statmenu->hp, "HP : ");
    sfText_setFont(statmenu->hp, statmenu->font);
    sfText_setCharacterSize(statmenu->hp, 18);
    sfText_setPosition(statmenu->hp, (sfVector2f) {1005, 210});
    sfText_setColor(statmenu->hp, sfBlack);
    sfText_setFont(statmenu->curhp, statmenu->font);
    sfText_setCharacterSize(statmenu->curhp, 18);
    sfText_setPosition(statmenu->curhp, (sfVector2f) {1075, 210});
    sfText_setColor(statmenu->curhp, sfBlack);    
}

void stats_menu_maxhp(statmenu_t *statmenu)
{
    statmenu->hpmax = sfText_create();
    statmenu->curhpmax = sfText_create();

    sfText_setString(statmenu->hpmax, "Max HP : ");
    sfText_setFont(statmenu->hpmax, statmenu->font);
    sfText_setCharacterSize(statmenu->hpmax, 18);
    sfText_setPosition(statmenu->hpmax, (sfVector2f) {1005, 230});
    sfText_setColor(statmenu->hpmax, sfBlack);
    sfText_setFont(statmenu->curhpmax, statmenu->font);
    sfText_setCharacterSize(statmenu->curhpmax, 18);
    sfText_setPosition(statmenu->curhpmax, (sfVector2f) {1075, 230});
    sfText_setColor(statmenu->curhpmax, sfBlack);    
}

void stats_menu_exp(statmenu_t *statmenu)
{
    statmenu->exp = sfText_create();
    statmenu->curexp = sfText_create();

    sfText_setString(statmenu->exp, "EXP : ");
    sfText_setFont(statmenu->exp, statmenu->font);
    sfText_setCharacterSize(statmenu->exp, 18);
    sfText_setPosition(statmenu->exp, (sfVector2f) {1005, 250});
    sfText_setColor(statmenu->exp, sfBlack);
    sfText_setFont(statmenu->curexp, statmenu->font);
    sfText_setCharacterSize(statmenu->curexp, 18);
    sfText_setPosition(statmenu->curexp, (sfVector2f) {1075, 250});
    sfText_setColor(statmenu->curexp, sfBlack);    
}

void stats_menu_shapes(statmenu_t *statmenu)
{
    statmenu->iconpos = (sfVector2f) {1230, 670};
    statmenu->openpos = (sfVector2f) {1000, 100};
    statmenu->characterpos = (sfVector2f) {1150, 120};
    statmenu->buttontext = sfText_create();

    sfRectangleShape_setTexture(statmenu->usebutton, statmenu->buttontexture, sfFalse);
    sfRectangleShape_setSize(statmenu->usebutton, (sfVector2f) {40, 20});

    sfRectangleShape_setTexture(statmenu->icon_rect, statmenu->icontexture, sfFalse);
    sfRectangleShape_setSize(statmenu->icon_rect, (sfVector2f) {50, 50});
    sfRectangleShape_setPosition(statmenu->icon_rect, statmenu->iconpos);

    sfRectangleShape_setTexture(statmenu->open_rect, statmenu->opentexture, sfFalse);
    sfRectangleShape_setSize(statmenu->open_rect, (sfVector2f) {250, 400});
    sfRectangleShape_setPosition(statmenu->open_rect, statmenu->openpos);

    sfRectangleShape_setTexture(statmenu->character, statmenu->charface, sfFalse);
    sfRectangleShape_setSize(statmenu->character, (sfVector2f) {250, 220});
    sfRectangleShape_setPosition(statmenu->character, statmenu->characterpos);
}

statmenu_t *init_statmenu(statmenu_t *statmenu)
{
    statmenu = malloc(sizeof(statmenu_t));
    statmenu->font = sfFont_createFromFile("./assets/font/font.ttf");
    statmenu->buttonfont = sfFont_createFromFile("./assets/font/DimboRegular.ttf");
    statmenu->icon_rect = sfRectangleShape_create();
    statmenu->open_rect = sfRectangleShape_create();
    statmenu->character = sfRectangleShape_create();
    statmenu->usebutton = sfRectangleShape_create();
    statmenu->icontexture = sfTexture_createFromFile("./assets/statmenu/statmenu_icon.png", NULL);
    statmenu->buttontexture = sfTexture_createFromFile("./assets/statmenu/button_empty.png", NULL);
    statmenu->opentexture = sfTexture_createFromFile("./assets/statmenu/window_1.png", NULL);
    statmenu->charface = sfTexture_createFromFile("./assets/sprites/player/ace1.png", NULL);  

    stats_menu_shapes(statmenu);
    stats_menu_level(statmenu);
    stats_menu_attack(statmenu);
    stats_menu_defense(statmenu);
    stats_menu_speed(statmenu);
    stats_menu_magic(statmenu);
    stats_menu_hp(statmenu);
    stats_menu_maxhp(statmenu);
    stats_menu_exp(statmenu);
    stats_menu_inventory(statmenu);
    return statmenu;
}