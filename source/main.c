/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main
*/

#include "../include/my_rpg.h"

void screen_switch(screen_t *screen, sfVector2f pos_mouse)
{
    switch (screen->mode) {
        case 0:
            draw_main(screen, screen->main, pos_mouse);
            break;
        case 1:
            launch_room(screen->game->rm, screen->game->gm, screen);
            break;
        case 2:
            draw_help(screen, screen->help, pos_mouse);
            break;
        case 3:
            draw_settings(screen, screen->setting, pos_mouse);
            break;
        case 4:
            sfRenderWindow_close(screen->window);
            break;
        case 5:
            draw_pause(screen, screen->pause, pos_mouse);
            break;
        default:
            break;
    }
}

void open_window(screen_t *screen)
{
    sfVector2f pos_mouse;

    sfRenderWindow_setFramerateLimit(screen->window, 60);
    sfMusic_setLoop(screen->soundtrack, sfTrue);
    sfMusic_play(screen->soundtrack);
    //LOOP
    while (sfRenderWindow_isOpen(screen->window)) {
        pos_mouse.x = (float) sfMouse_getPosition((const sfWindow *)\
        screen->window).x;
        pos_mouse.y = (float) sfMouse_getPosition((const sfWindow *) \
        screen->window).y;
        screen_switch(screen, pos_mouse);
        sfRenderWindow_display(screen->window);
        sfRenderWindow_clear(screen->window, sfBlack);
    }
    destroy_everything(screen);
}

int main(int ac, char **av)
{
    screen_t *screen = malloc(sizeof(screen_t));

    screen = prep_struct(screen);
    open_window(screen);
    return 0;
}