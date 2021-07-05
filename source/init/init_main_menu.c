/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_main_menu
*/

#include "../../include/my_rpg.h"

text_t *init_main_t(text_t *text)
{
    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./assets/font/font2.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, "MY_RPG");
    sfText_setCharacterSize(text->text, 100);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, (sfVector2f) {450, 50});
    return text;
}

text_t **init_main_text(text_t **text)
{
    text = malloc(sizeof(text_t *) * 2);
    text[0] = init_main_t(text[0]);
    text[1] = NULL;
    return text;
}

main_t *init_main(main_t *main)
{
    main = malloc(sizeof(main_t));
    main->button = init_main_buttons(main->button);
    main->text = init_main_text(main->text);
    return main;
}