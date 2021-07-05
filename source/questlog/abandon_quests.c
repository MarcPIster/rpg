/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** abandon_quests
*/

#include "../../include/my_rpg.h"

sfFloatRect getbuttonbounds2(int i)
{
    sfFloatRect buttonbounds;

    buttonbounds.left = 295;
    buttonbounds.top = 153 + (i * 30);
    buttonbounds.width = 50;
    buttonbounds.height = 20;
    return buttonbounds;
}

void abandon_quest(int i, quest_list *questlist, player *player1)
{
    printf("abandonning quest: %d\n", i+1);
    questlist[i].quest_name = "-EMPTY-";
    questlist[i].quest_index = -1;
    questlist[i].completed = 0;
    questlist[i].item_to_have_index = -1;
    questlist[i].mob_to_kill_index = -1;
}

void detect_mouseover_abandon(int i, gameloop_t *game, screen_t *screen, sfVector2i pos_mouse)
{
    sfFloatRect buttonbounds = getbuttonbounds2(i);

    float use_right = buttonbounds.left + buttonbounds.width;
    float use_bottom = buttonbounds.top + buttonbounds.height;
    float elapsed_time = sfTime_asMilliseconds(sfClock_getElapsedTime(game->clicktimer));

    if (pos_mouse.x > buttonbounds.left && pos_mouse.x < use_right &&
        pos_mouse.y > buttonbounds.top && pos_mouse.y < use_bottom) {
            sfRectangleShape_setScale(game->questlog->abandonbutton, (sfVector2f) {1.1 , 1.1});
            sfText_setCharacterSize(game->questlog->buttontext, 18);
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && elapsed_time > 100) {
                sfClock_restart(game->clicktimer);
                abandon_quest(i, game->player1->questlist, game->player1);
                return;
            }
    }
    else {
        sfRectangleShape_setScale(game->questlog->abandonbutton, (sfVector2f) {1 , 1});
        sfText_setCharacterSize(game->questlog->buttontext, 16);
    }  
}
