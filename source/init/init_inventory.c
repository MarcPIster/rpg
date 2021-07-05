/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** init_inventory
*/

#include "../../include/my_rpg.h"

void inventory_1_2_3_4(statmenu_t *statmenu)
{
    statmenu->item1 = sfText_create();
    statmenu->item2 = sfText_create();
    statmenu->item3 = sfText_create();
    statmenu->item4 = sfText_create();

    sfText_setFont(statmenu->item1, statmenu->font);
    sfText_setCharacterSize(statmenu->item1, 18);
    sfText_setPosition(statmenu->item1, (sfVector2f) {1005, 310});
    sfText_setColor(statmenu->item1, sfBlack);    
    sfText_setFont(statmenu->item2, statmenu->font);
    sfText_setCharacterSize(statmenu->item2, 18);
    sfText_setPosition(statmenu->item2, (sfVector2f) {1005, 330});
    sfText_setColor(statmenu->item2, sfBlack);
    sfText_setFont(statmenu->item3, statmenu->font);
    sfText_setCharacterSize(statmenu->item3, 18);
    sfText_setPosition(statmenu->item3, (sfVector2f) {1005, 350});
    sfText_setColor(statmenu->item3, sfBlack);
    sfText_setFont(statmenu->item4, statmenu->font);
    sfText_setCharacterSize(statmenu->item4, 18);
    sfText_setPosition(statmenu->item4, (sfVector2f) {1005, 370});
    sfText_setColor(statmenu->item4, sfBlack);
}

void inventory_5_6_7_8(statmenu_t *statmenu)
{
    statmenu->item5 = sfText_create();
    statmenu->item6 = sfText_create();
    statmenu->item7 = sfText_create();
    statmenu->item8 = sfText_create();

    sfText_setFont(statmenu->item5, statmenu->font);
    sfText_setCharacterSize(statmenu->item5, 18);
    sfText_setPosition(statmenu->item5, (sfVector2f) {1005, 390});
    sfText_setColor(statmenu->item5, sfBlack);    
    sfText_setFont(statmenu->item6, statmenu->font);
    sfText_setCharacterSize(statmenu->item6, 18);
    sfText_setPosition(statmenu->item6, (sfVector2f) {1005, 410});
    sfText_setColor(statmenu->item6, sfBlack);
    sfText_setFont(statmenu->item7, statmenu->font);
    sfText_setCharacterSize(statmenu->item7, 18);
    sfText_setPosition(statmenu->item7, (sfVector2f) {1005, 430});
    sfText_setColor(statmenu->item7, sfBlack);
    sfText_setFont(statmenu->item8, statmenu->font);
    sfText_setCharacterSize(statmenu->item8, 18);
    sfText_setPosition(statmenu->item8, (sfVector2f) {1005, 450});
    sfText_setColor(statmenu->item8, sfBlack);
}

void inventory_header(statmenu_t *statmenu)
{
    statmenu->inventory = sfText_create();

    sfText_setString(statmenu->inventory, "INVENTORY");
    sfText_setFont(statmenu->inventory, statmenu->font);
    sfText_setCharacterSize(statmenu->inventory, 20);
    sfText_setPosition(statmenu->inventory, (sfVector2f) {1080, 280});
    sfText_setColor(statmenu->inventory, sfBlack);
}


void stats_menu_inventory(statmenu_t *statmenu)
{
    inventory_header(statmenu);
    inventory_1_2_3_4(statmenu);
    inventory_5_6_7_8(statmenu);
}