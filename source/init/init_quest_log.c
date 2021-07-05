/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** init_quest_log
*/

#include "../../include/my_rpg.h"

void questlog_shapes(questlog_t *questlog)
{
    questlog->iconpos = (sfVector2f) {1180, 670};
    questlog->openpos = (sfVector2f) {100, 100};
    questlog->buttontext = sfText_create();

    sfRectangleShape_setTexture(questlog->abandonbutton, questlog->buttontexture, sfFalse);
    sfRectangleShape_setSize(questlog->abandonbutton, (sfVector2f) {50, 20});

    sfRectangleShape_setTexture(questlog->icon_rect, questlog->icontexture, sfFalse);
    sfRectangleShape_setSize(questlog->icon_rect, (sfVector2f) {50, 50});
    sfRectangleShape_setPosition(questlog->icon_rect, questlog->iconpos);

    sfRectangleShape_setTexture(questlog->open_rect, questlog->opentexture, sfFalse);
    sfRectangleShape_setSize(questlog->open_rect, (sfVector2f) {250, 400});
    sfRectangleShape_setPosition(questlog->open_rect, questlog->openpos);
}

questlog_t *init_quest_log(questlog_t *questlog)
{
    questlog = malloc(sizeof(questlog_t));
    questlog->font = sfFont_createFromFile("./assets/font/font.ttf");
    questlog->buttonfont = sfFont_createFromFile("./assets/font/DimboRegular.ttf");
    questlog->icon_rect = sfRectangleShape_create();
    questlog->open_rect = sfRectangleShape_create();
    questlog->abandonbutton = sfRectangleShape_create();
    questlog->icontexture = sfTexture_createFromFile("./assets/questlog/questlog_icon.png", NULL);
    questlog->buttontexture = sfTexture_createFromFile("./assets/questlog/button_empty.png", NULL);
    questlog->opentexture = sfTexture_createFromFile("./assets/questlog/window_1.png", NULL);

    questlog_shapes(questlog);
    init_quests(questlog);
    return questlog;
}