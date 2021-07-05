/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** init_quests
*/

#include "../../include/my_rpg.h"

void quests_1_2_3_4(questlog_t *questlog)
{
    questlog->quest1 = sfText_create();
    questlog->quest2 = sfText_create();
    questlog->quest3 = sfText_create();
    questlog->quest4 = sfText_create();

    sfText_setFont(questlog->quest1, questlog->font);
    sfText_setCharacterSize(questlog->quest1, 18);
    sfText_setPosition(questlog->quest1, (sfVector2f) {110, 150});
    sfText_setColor(questlog->quest1, sfBlack);    
    sfText_setFont(questlog->quest2, questlog->font);
    sfText_setCharacterSize(questlog->quest2, 18);
    sfText_setPosition(questlog->quest2, (sfVector2f) {110, 180});
    sfText_setColor(questlog->quest2, sfBlack);
    sfText_setFont(questlog->quest3, questlog->font);
    sfText_setCharacterSize(questlog->quest3, 18);
    sfText_setPosition(questlog->quest3, (sfVector2f) {110, 210});
    sfText_setColor(questlog->quest3, sfBlack);
    sfText_setFont(questlog->quest4, questlog->font);
    sfText_setCharacterSize(questlog->quest4, 18);
    sfText_setPosition(questlog->quest4, (sfVector2f) {110, 240});
    sfText_setColor(questlog->quest4, sfBlack);
}

void quests_5_6_7_8(questlog_t *questlog)
{
    questlog->quest5 = sfText_create();
    questlog->quest6 = sfText_create();
    questlog->quest7 = sfText_create();
    questlog->quest8 = sfText_create();

    sfText_setFont(questlog->quest5, questlog->font);
    sfText_setCharacterSize(questlog->quest5, 18);
    sfText_setPosition(questlog->quest5, (sfVector2f) {110, 270});
    sfText_setColor(questlog->quest5, sfBlack);    
    sfText_setFont(questlog->quest6, questlog->font);
    sfText_setCharacterSize(questlog->quest6, 18);
    sfText_setPosition(questlog->quest6, (sfVector2f) {110, 300});
    sfText_setColor(questlog->quest6, sfBlack);
    sfText_setFont(questlog->quest7, questlog->font);
    sfText_setCharacterSize(questlog->quest7, 18);
    sfText_setPosition(questlog->quest7, (sfVector2f) {110, 330});
    sfText_setColor(questlog->quest7, sfBlack);
    sfText_setFont(questlog->quest8, questlog->font);
    sfText_setCharacterSize(questlog->quest8, 18);
    sfText_setPosition(questlog->quest8, (sfVector2f) {110, 360});
    sfText_setColor(questlog->quest8, sfBlack);
}

void quests_header(questlog_t *questlog)
{
    questlog->quests = sfText_create();

    sfText_setString(questlog->quests, "QUESTS");
    sfText_setFont(questlog->quests, questlog->font);
    sfText_setCharacterSize(questlog->quests, 20);
    sfText_setPosition(questlog->quests, (sfVector2f) {200, 115});
    sfText_setColor(questlog->quests, sfBlack);
}


void init_quests(questlog_t *questlog)
{
    quests_header(questlog);
    quests_1_2_3_4(questlog);
    quests_5_6_7_8(questlog);
}