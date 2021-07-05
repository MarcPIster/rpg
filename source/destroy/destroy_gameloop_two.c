/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** destroy gameloop
*/

#include "../../include/my_rpg.h"

void destroy_mob(mob_data *m)
{
    for (int i = 0; i < m->unit_amount; i++) {
        free(m[i].name);
        sfClock_destroy(m[i].anim_clock);
        sfSprite_destroy(m[i].out_sprite);
        sfTexture_destroy(m[i].battle);
        sfTexture_destroy(m[i].dying);
        sfTexture_destroy(m[i].walking);
        sfTexture_destroy(m[i].portrait);
    }
    free(m);
}

void destroy_npc(npc_data *n)
{
    for (int i = 0; i < n->unit_amount; i++) {
        free(n[i].name);
        sfTexture_destroy(n[i].walking);
        sfTexture_destroy(n[i].portrait);
        sfSprite_destroy(n[i].npc_sprite);
        sfClock_destroy(n[i].anim_clock);
    }
    free(n);
}

void destroy_player(player *p)
{
    sfTexture_destroy(p->walking);
    sfTexture_destroy(p->dying);
    sfTexture_destroy(p->portrait);
    sfTexture_destroy(p->battle);
    sfSprite_destroy(p->player1_sprite);
    sfClock_destroy(p->anim_clock);
    free(p->inventory);
    free(p->questlist);
    free(p);
}

void destroy_questlog(questlog_t *q)
{
    sfTexture_destroy(q->icontexture);
    sfTexture_destroy(q->opentexture);
    sfTexture_destroy(q->buttontexture);
    sfRectangleShape_destroy(q->icon_rect);
    sfRectangleShape_destroy(q->open_rect);
    sfRectangleShape_destroy(q->abandonbutton);
    sfFont_destroy(q->font);
    sfFont_destroy(q->buttonfont);
    sfText_destroy(q->quests);
    sfText_destroy(q->buttontext);
    sfText_destroy(q->quest1);
    sfText_destroy(q->quest2);
    sfText_destroy(q->quest3);
    sfText_destroy(q->quest4);
    sfText_destroy(q->quest5);
    sfText_destroy(q->quest6);
    sfText_destroy(q->quest7);
    sfText_destroy(q->quest8);
    free(q);
}

void destroy_room(room *r)
{
    for (int i = 0; r->tiling[i] != NULL; i++) 
        free(r->tiling[i]);
    free(r->connections);
    free(r);
}