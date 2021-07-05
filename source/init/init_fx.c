/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** init_fx
*/

#include "../../include/my_rpg.h"

particles *init_fx(char *fx_file_path)
{
    csv *parsed_csv = parse_csv(fx_file_path);
    particles *fx = malloc(sizeof(particles) * (parsed_csv->n_rows + 1));

    for (int i = 0; i < parsed_csv->n_rows; i++) {
        fx[i].name = parsed_csv->data[i][0];
        fx[i].effect = sfTexture_createFromFile(parsed_csv->data[i][1], NULL);
        fx[i].psprite = sfSprite_create();
        fx[i].active = 0;
        fx[i].position.x = 0;
        fx[i].position.y = 0;
        fx[i].animation_rect.top = 0;
        fx[i].animation_rect.left = 0;
        fx[i].animation_rect.height = my_getnbr(parsed_csv->data[i][2]);
        fx[i].animation_rect.width = my_getnbr(parsed_csv->data[i][3]);
        fx[i].origin.x = fx[i].animation_rect.width / 2;
        fx[i].origin.y = fx[i].animation_rect.height / 2;
        fx[i].image_height  = my_getnbr(parsed_csv->data[i][4]);
        fx[i].image_width  = my_getnbr(parsed_csv->data[i][5]);
        fx[i].scale.x = 48 / fx[i].animation_rect.width;
        fx[i].scale.y = 48 / fx[i].animation_rect.height;
        fx[i].anim_count = my_getnbr(parsed_csv->data[i][6]);
        sfSprite_setOrigin(fx[i].psprite, fx[i].origin);
        sfSprite_setTexture(fx[i].psprite, fx[i].effect, 0);
        fx[i].anim_clock = sfClock_create();
        fx[i].life_clock = sfClock_create();
    }
    return fx;
}