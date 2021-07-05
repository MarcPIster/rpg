/*
** EPITECH PROJECT, 2021
** B-MUL-200-BER-2-1-myrpg-gylian.karsch
** File description:
** init_npcs
*/

#include "../../include/my_rpg.h"

npc_data *init_npcs(char *npcs_csv_path)
{
    csv *parsed_csv = parse_csv(npcs_csv_path);
    npc_data *npcs = malloc(sizeof(npc_data) * (parsed_csv->n_rows + 1));


    for (int i = 0; i < parsed_csv->n_rows; i++) {
        npcs[i].name = parsed_csv->data[i][0];
        npcs[i].anim_rect.top = 0;        
        npcs[i].anim_rect.left = 0; 
        npcs[i].anim_rect.width = my_getnbr(parsed_csv->data[i][3]);
        npcs[i].anim_rect.height = my_getnbr(parsed_csv->data[i][4]);
        npcs[i].animnums.y = my_getnbr(parsed_csv->data[i][5]);
        npcs[i].animnums.x = my_getnbr(parsed_csv->data[i][6]) - 1;
        npcs[i].origin.x = npcs[i].anim_rect.width / 2;
        npcs[i].origin.y = npcs[i].anim_rect.height / 2;
        npcs[i].aggro = 0;             
        npcs[i].unit_amount = parsed_csv->n_rows;
        npcs[i].position.x = my_getnbr(parsed_csv->data[i][7]);
        npcs[i].position.y = my_getnbr(parsed_csv->data[i][8]);
        npcs[i].movespeed = my_getnbr(parsed_csv->data[i][9]);
        npcs[i].aggrorange = my_getnbr(parsed_csv->data[i][10]);
        npcs[i].anim_clock = sfClock_create();
        npcs[i].npc_sprite = sfSprite_create();
        npcs[i].intalk = 0;
        npcs[i].move_dir = MOVE_DOWN;
        npcs[i].hasspawned = 0;
        npcs[i].questnumber = my_getnbr(parsed_csv->data[i][12]);
        npcs[i].minspawnlevel = my_getnbr(parsed_csv->data[i][13]);
        npcs[i].walking = sfTexture_createFromFile(parsed_csv->data[i][1], NULL);
        npcs[i].portrait = sfTexture_createFromFile(parsed_csv->data[i][2], NULL);
        sfSprite_setOrigin(npcs[i].npc_sprite, npcs[i].origin);
        sfSprite_setTextureRect(npcs[i].npc_sprite, npcs[i].anim_rect);
        sfSprite_setTexture(npcs[i].npc_sprite, npcs[i].walking, 0);
    }
    return npcs;
}