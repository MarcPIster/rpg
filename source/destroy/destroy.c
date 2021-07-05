/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** destroy everything
*/

#include "../../include/my_rpg.h"

void destroy_main(main_t *m)
{
    for (int i = 0; m->button[i] != NULL; i++) {
        sfFont_destroy(m->button[i]->font);
        sfRectangleShape_destroy(m->button[i]->rect);
        sfText_destroy(m->button[i]->text);
    }
    free(m->button);
    for (int i = 0; m->text[i] != NULL; i++) {
        sfFont_destroy(m->text[i]->font);
        sfText_destroy(m->text[i]->text);
    }
    free(m->text);
    free(m);
}

void destroy_help(help_t *h)
{
    for (int i = 0; h->button[i] != NULL; i++) {
        sfFont_destroy(h->button[i]->font);
        sfRectangleShape_destroy(h->button[i]->rect);
        sfText_destroy(h->button[i]->text);
    }
    free(h->button);
    for (int i = 0; h->text[i] != NULL; i++) {
        sfFont_destroy(h->text[i]->font);
        sfText_destroy(h->text[i]->text);
    }
    free(h->text);
    free(h);
}

void destroy_settings(setting_t *s)
{
    for (int i = 0; s->button[i] != NULL; i++) {
        sfFont_destroy(s->button[i]->font);
        sfRectangleShape_destroy(s->button[i]->rect);
        sfText_destroy(s->button[i]->text);
    }
    free(s->button);
    for (int i = 0; s->text[i] != NULL; i++) {
        sfFont_destroy(s->text[i]->font);
        sfText_destroy(s->text[i]->text);
    }
    free(s->text);
    sfSprite_destroy(s->plus);
    sfSprite_destroy(s->minus);
    sfTexture_destroy(s->vp);
    sfTexture_destroy(s->vm);
    sfRectangleShape_destroy(s->volm);
    sfRectangleShape_destroy(s->volp);
    free(s);
}

void destroy_pause(pause_t *p)
{
    for (int i = 0; p->button[i] != NULL; i++) {
        sfFont_destroy(p->button[i]->font);
        sfRectangleShape_destroy(p->button[i]->rect);
        sfText_destroy(p->button[i]->text);
    }
    free(p->button);
    for (int i = 0; p->text[i] != NULL; i++) {
        sfFont_destroy(p->text[i]->font);
        sfText_destroy(p->text[i]->text);
    }
    free(p->text);
    sfSprite_destroy(p->sprite);
    sfTexture_destroy(p->texture);
    free(p);
}

void destroy_everything(screen_t *s)
{
    destroy_main(s->main);
    sfSprite_destroy(s->background);
    sfTexture_destroy(s->bgt);
    destroy_settings(s->setting);
    destroy_pause(s->pause);
    destroy_help(s->help);
    sfMusic_stop(s->soundtrack);
    sfMusic_destroy(s->soundtrack);
    sfMusic_destroy(s->death);
    free(s);
}