/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init pause screen
*/

#include "../../include/screen_structs.h"
#include "../../include/my_rpg.h"

text_t *init_pause_head(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./assets/font/font2.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, "Pause");
    sfText_setCharacterSize(text->text, 100);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f) {500, 50});
    return text;
}

button_t **init_pause_button(button_t **button)
{
    button = malloc(sizeof(button_t *) * 6);
    button[0] = continue_button();
    button[1] = restart_button();
    button[2] = option_button();
    button[3] = main_menu_button();
    button[4] = quit_button();
    button[5] = NULL;
    return button;
}

text_t **init_pause_text(text_t **text)
{
    text = malloc(sizeof(text_t *) * 2);
    text[0] = init_pause_head(text[0]);
    text[1] = NULL;
    return text;
}

pause_t *init_pause(void)
{
    pause_t *pause = malloc(sizeof(pause_t));

    pause->button = init_pause_button(pause->button);
    pause->text = init_pause_text(pause->text);
    pause->sprite = sfSprite_create();
    pause->texture = sfTexture_createFromFile\
    ("./assets/sprites/background/pause.png", NULL);
    sfSprite_setTexture(pause->sprite, pause->texture, sfTrue);
    sfSprite_setScale(pause->sprite, (sfVector2f) {0.777, 0.777});
    sfSprite_setPosition(pause->sprite, (sfVector2f) {-100, 0});
    pause->pasuestate = pauseclosed;
    return pause;
}