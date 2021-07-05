/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** display_questlog
*/

#include "../../include/my_rpg.h"


void display_abandon_quest(int i, gameloop_t *game, screen_t *screen, sfVector2i pos_mouse)
{
    sfRectangleShape_setPosition(game->questlog->abandonbutton, (sfVector2f) {295, 153 + (i * 30)});
    sfText_setString(game->questlog->buttontext, "give up");
    sfText_setFont(game->questlog->buttontext, game->questlog->buttonfont);
    sfText_setCharacterSize(game->questlog->buttontext, 16);
    sfText_setPosition(game->questlog->buttontext, (sfVector2f) {299, 152 + (i * 30)});
    sfText_setColor(game->questlog->buttontext, sfGreen);
    detect_mouseover_abandon(i, game, screen, pos_mouse);
    sfRenderWindow_drawRectangleShape(screen->window, screen->game->questlog->abandonbutton,
        NULL);
    sfRenderWindow_drawText(screen->window, game->questlog->buttontext, NULL);
}

void display_quests(gameloop_t *game, screen_t *screen, sfVector2i pos_mouse)
{
    sfRenderWindow_drawText(screen->window, game->questlog->quests, NULL);
    sfText_setString(game->questlog->quest1, game->player1->questlist[0].quest_name);
    sfRenderWindow_drawText(screen->window, game->questlog->quest1, NULL);
    sfText_setString(game->questlog->quest2, game->player1->questlist[1].quest_name);
    sfRenderWindow_drawText(screen->window, game->questlog->quest2, NULL);
    sfText_setString(game->questlog->quest3, game->player1->questlist[2].quest_name);
    sfRenderWindow_drawText(screen->window, game->questlog->quest3, NULL);
    sfText_setString(game->questlog->quest4, game->player1->questlist[3].quest_name);
    sfRenderWindow_drawText(screen->window, game->questlog->quest4, NULL);
    sfText_setString(game->questlog->quest5, game->player1->questlist[4].quest_name);
    sfRenderWindow_drawText(screen->window, game->questlog->quest5, NULL);
    sfText_setString(game->questlog->quest6, game->player1->questlist[5].quest_name);
    sfRenderWindow_drawText(screen->window, game->questlog->quest6, NULL);
    sfText_setString(game->questlog->quest7, game->player1->questlist[6].quest_name);
    sfRenderWindow_drawText(screen->window, game->questlog->quest7, NULL);
    sfText_setString(game->questlog->quest8, game->player1->questlist[7].quest_name);
    sfRenderWindow_drawText(screen->window, game->questlog->quest8, NULL);
    for (int i = 0; i < 8; i++) {
        if (game->player1->questlist[i].quest_index != -1) {
            display_abandon_quest(i, game, screen, pos_mouse);
        }
    }    
}

void display_questlog(gameloop_t *game, screen_t *screen, sfVector2i pos_mouse)
{
    sfRenderWindow_drawRectangleShape(screen->window, screen->game->questlog->open_rect,
        NULL);
    display_quests(game, screen, pos_mouse);    
}