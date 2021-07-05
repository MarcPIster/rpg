/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** destroy gameloop
*/

#include "../../include/my_rpg.h"

void destroy_statmenu_two(statmenu_t *s)
{
    sfText_destroy(s->defense);
    sfText_destroy(s->curdef);
    sfText_destroy(s->speed);
    sfText_destroy(s->curspd);
    sfText_destroy(s->magic);
    sfText_destroy(s->curmag);
    sfText_destroy(s->hp);
    sfText_destroy(s->curhp);
    sfText_destroy(s->hpmax);
    sfText_destroy(s->curhpmax);
    sfText_destroy(s->exp);
    sfText_destroy(s->curexp);
    sfText_destroy(s->item1);
    sfText_destroy(s->item2);
    sfText_destroy(s->item3);
    sfText_destroy(s->item4);
    sfText_destroy(s->item5);
    sfText_destroy(s->item6);
    sfText_destroy(s->item7);
    sfText_destroy(s->item8);
}

void destroy_statmenu(statmenu_t *s)
{
    sfTexture_destroy(s->icontexture);
    sfTexture_destroy(s->opentexture);
    sfTexture_destroy(s->buttontexture);
    sfTexture_destroy(s->charface);
    sfRectangleShape_destroy(s->icon_rect);
    sfRectangleShape_destroy(s->open_rect);
    sfRectangleShape_destroy(s->character);
    sfRectangleShape_destroy(s->usebutton);
    sfFont_destroy(s->font);
    sfFont_destroy(s->buttonfont);
    sfText_destroy(s->inventory);
    sfText_destroy(s->buttontext);
    sfText_destroy(s->level);
    sfText_destroy(s->curlvl);
    sfText_destroy(s->attack);
    sfText_destroy(s->curatk);
    destroy_statmenu_two(s);
    free(s);
}

void destroy_game(game *gm)
{
    sfRenderWindow_destroy(gm->render);
    for (int i = 0; gm->tileset[i] != NULL; i++)
        sfTexture_destroy(gm->tileset[i]);
    for (int i = 0; gm->tile_sprites[i] != NULL; i++)
        sfSprite_destroy(gm->tile_sprites[i]);
    free(gm);
}

void destroy_gameloop(gameloop_t *g)
{
    destroy_mob(g->mob);
    destroy_npc(g->npc);
    destroy_player(g->player1);
    destroy_statmenu(g->statmenu);
    destroy_questlog(g->questlog);
    destroy_room(g->rm);
    destroy_game(g->gm);
    sfClock_destroy(g->clicktimer);
    free(g);
}